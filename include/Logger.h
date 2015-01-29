#ifndef _LOGGER_H
#define _LOGGER_H

#include <fstream>
#include <string>

#define LOG(loggerInst, level, _msg)\
    loggerInst(static_cast<std::ostringstream&>(std::ostringstream().flush() << #level \
                                                                      << " "    \
                                                                      << _msg   \
                                        ).str()); 
class Logger
{
    private:
        std::ofstream logFile;

    public:
        Logger(const std::string& path);
        void operator()(const std::string& msg);
};

#endif
