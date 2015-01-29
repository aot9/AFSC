#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

#include "Logger.h"

Logger::Logger(const std::string& path)
{
    logFile.open(path, std::ofstream::out | std::ofstream::app);
}

void Logger::operator()(std::string const& msg) 
{
    if (logFile.fail())
        return;

    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    
    logFile << std::put_time(std::localtime(&now_c), "%c") << " " 
            << msg << '\n';
    logFile.flush();
}
