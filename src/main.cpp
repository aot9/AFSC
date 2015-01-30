#include <sstream>
#include <fstream>
#include <iostream>

#include <unistd.h>
#include <signal.h>
#include <cstdint> // uint8_t, uint16_t
#include <sys/io.h> // inb, outb

#include "Util.h"

#ifdef NDEBUG
#define _LOG(level, _msg)\
{\
    writelog(static_cast<std::ostringstream&>(std::ostringstream().flush() << \
             #level << " " << _msg).str());\
}
#else
#define _LOG(level, _msg) \
{\
    std::cout << #level << " " << _msg << std::endl; \
}
#endif

#define ILOG(_msg) _LOG(INFO, _msg)
#define ELOG(_msg) _LOG(ERROR, _msg)

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
        usleep(5000); // sleep 5ms
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

    if (readConfigToString("/etc/afsc.conf", sconfig) != 0)
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

#ifdef NDEBUG
    if (daemon(0, 0) != 0)
    {
        ELOG("Unable to daemonize");
        exit(1);
    }
#endif

    registerSignals();

    while (true)
    {
        int curTemp = 0;

        temp_source.clear();
        temp_source.seekg(0, temp_source.beg);
        temp_source >> curTemp;

        // range of relSpeed is 0-10 or 250 for auto mode. relSpeed corresponds
        // to values that user can set in config file
        int relSpeed = 0;

        // check if temperature is under lowest threshold
        if (curTemp <= config.temp_policy.rbegin()->first)
            relSpeed = config.min_speed;
        else
        {
            for (auto tempPolItem : config.temp_policy)
            {
                if (curTemp > tempPolItem.first)
                {
                    relSpeed = tempPolItem.second;
                    break;
                }
            }
        }

        if (relSpeed == 250)
            ILOG("Temperature is " << curTemp << ", setting speed to auto")
        else
            ILOG("Temperature is " << curTemp << ", setting speed to " << relSpeed);

#ifdef NDEBUG
        // The MSB (Bit 7) control the method of fan control:
        // manual = 0, automatic (default)= 1
        // The next 4 Bit (Bit 6 - 2) sets the fan speed (only when Bit 7 is 0):
        // value 0x0 to 0x5: fan is off
        // from value 0x5 to 0xF: fan speeds in ascending order
        uint8_t speed = ((relSpeed | 0x05) << 3) | 0x07;

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
