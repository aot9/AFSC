#include <sstream>

#include <unistd.h>
#include <signal.h>
#include <cstdint> // uint8_t, uint16_t
#include <sys/io.h> // inb, outb

#include "Util.h"
#include "Logger.h"

#define noop (void(0))

#ifdef NLOG
    #define ILOG(_msg) noop
    #define ELOG(_msg) noop
#else
    Logger log("/var/log/afcd.log");

    #define ILOG(_msg) LOG(log, INFO, _msg)
    #define ELOG(_msg) LOG(log, ERROR, _msg)
#endif

// IO ports
const uint16_t AEIC = 0x025D; // command register
const uint16_t AEID = 0x025C; // data register

// waits for the status bit to clear, max 0x4000 tries
void WEIE() {
    uint16_t Local0 = 0x4000;
    uint8_t Local1 = inb(AEIC) & 0x02;
    while(Local0 != 0 && Local1 == 0x02) {
        Local1 = inb(AEIC) & 0x02;
        Local0--;
        usleep(500); // sleep 0.5ms
    }
}

// sets the fan speed
void WMFN(uint8_t Arg0) {
    WEIE();
    outb(0x98, AEIC);
    WEIE();
    outb(Arg0, AEID);
    WEIE();
}

void signalHandler(int sig)
{
    ILOG("Signal caught: " << sig << ". Exiting...");
    exit(sig);
}

void registerSignals()
{
    signal(SIGTTIN, SIG_IGN);
    signal(SIGTTOU, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);

    signal(SIGINT, signalHandler);
    signal(SIGQUIT, signalHandler);
    signal(SIGTERM, signalHandler);
}

int main()
{
    std::string sconfig;
    AfcdConfig config;

    int curTemp = 0;
    int speed = 0;

    if (readConfigToString("/etc/afcd.conf", sconfig) != 0)
    {
        ELOG("Unable to read config");
        exit(1);
    }

    if (parseConfig(sconfig, config) != 0)
    {
        ELOG("Invalid config");
        exit(1);
    }

    std::ifstream temp_source(config.path, std::ifstream::in);
    if (temp_source.fail())
    {
        ELOG("Unable to open temperature source file");
        exit(1);
    }

    if (daemon(0, 0) != 0)
    {
        ELOG("Unable to daemonize");
        exit(1);
    }

    registerSignals();

    while (true)
    {
        temp_source.clear();
        temp_source.seekg(0, temp_source.beg);
        temp_source >> curTemp;

        // check if temperature is under lowest threshold
        if (curTemp <= config.temp_policy.rbegin()->first)
            speed = config.min_speed;
        else
        {
            for (auto tempPolItem : config.temp_policy)
            {
                if (curTemp > tempPolItem.first)
                {
                    speed = tempPolItem.second;
                    break;
                }
            }
        }

        ILOG("Temperature is " << curTemp << ", setting speed to " << speed);
        
        // speed control code here
        speed = (speed << 3) | 0x07;

#ifdef NDEBUG
        if(ioperm(AEID, 1, 1))
        {
            ELOG("Could not gain access to IO port AEID (0x025C). Exiting...");
            exit(1);
        }

        if(ioperm(AEIC, 1, 1))
        {
            ELOG("Could not gain access to IO port AEIC (0x025D). Exiting...");
            exit(1);
        }
        WMFN(speed);
#endif

        sleep(config.interval);
    }
}
