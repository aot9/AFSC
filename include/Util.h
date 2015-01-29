#ifndef _UTIL_H
#define _UTIL_H

#include <string>
#include <vector>
#include <map>

struct AfcdConfig {
    std::string path;
    int min_speed;
    int interval;
    std::vector<std::pair<int, int> > temp_policy;
};

int readConfigToString(const std::string& config_path, std::string& sconf);
int parseConfig(const std::string& sconf, AfcdConfig& config);

#endif
