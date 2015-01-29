#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <regex>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>

#include "Util.h"

int readConfigToString(const std::string& config_path, std::string& sconf)
{
    std::stringstream ssconfig;
    std::ifstream ifsconfig(config_path, std::ifstream::in);
    if (ifsconfig.good())
    {
        ssconfig << ifsconfig.rdbuf();
        sconf = std::move(ssconfig.str());
        return 0;
    }
    else
        return -1;
}

int parseConfig(const std::string& sconf, AfcdConfig& config)
{
    std::smatch m;

    /*
     * regex that match blank lines, trailing spaces
     * and bash like comments
     */
    std::string bc = "(?:\\s*(?:#.*[\r\n])*)*";

    /*
     * regex that match afsc config file
     */
    std::regex r(bc + "TEMP_SOURCE=([-_./[:alnum:]]+)"+
                 bc + "INTERVAL=(\\d+)"+
                 bc + "MIN_SPEED=(\\d+)"+
                 bc + "POLICY=((?:\\d+:\\d+\\s+)+)" + bc);

    std::regex_match(sconf, m, r);

    if (m.size() == 0)
        return -1;

    config.path = std::move(m[1].str());
    config.interval = std::stoi(m[2].str());
    config.min_speed = std::stoi(m[3].str());
    config.temp_policy = [](const std::string& pstr) {
        std::istringstream iss(pstr);

        std::vector<std::pair<int, int>> tmp;
        std::string token;
        while(iss >> token)
        {
            std::string::size_type sz;
            auto first = std::stoi(token, &sz);
            auto second = std::stoi(token.substr(sz + 1));
            tmp.emplace_back(first, second);
        }

        std::sort(tmp.rbegin(), tmp.rend());

        return std::move(tmp);

    }(m[4].str());

    return 0;
}

void writelog(const std::string& msg)
{
    static std::ofstream log("/var/log/afsc.log", std::ofstream::out | std::ofstream::app);

    if (log.fail())
        return;

    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);

    log << std::put_time(std::localtime(&now_c), "%c") << " "
            << msg << '\n';
    log.flush();
}

