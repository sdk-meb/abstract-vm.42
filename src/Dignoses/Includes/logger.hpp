#ifndef __LOGGER_HPP
#define __LOGGER_HPP

#include <fstream>
#include <string>
#include <ctime>
#include <stdexcept>
#include <iomanip>

#include <regex>

#ifndef LOG_PATH
# define LOG_PATH "Logs"
#endif

enum class LogLevel {

    SUSSC,
    INFO,
    WARN,
    HINT,
    DEBUG,
    ERROR,
};

/**
 * @attention `__re_init_`  cause a lost of resource
 * 
 * @exception `__init_` @throw when alreday init
 *
 * @note calling `loghandler` has an auto init 
 *  with a default path Logs/ *.log.json
 */
class Logger {

        static std::ofstream log_file;
        static bool isInitialized;

    public:
        static void __re_init_();
        static void __init_();
        static void loghandler(const int& line_number, const std::smatch &smatch);
};

#endif
