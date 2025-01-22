#include <logger.hpp>
#include <iostream>

std::ofstream Logger::log_file;
bool Logger::isInitialized;

void Logger::__init_() {

    if (Logger::isInitialized)
        throw std::logic_error("Failed: Logger already initialized");
    __re_init_();
}

void Logger::__re_init_() {

    short log_num = 0;
    if (Logger::isInitialized)
        log_file.close();

    std::string path = LOG_PATH;
    if (path.back() != '/') path += '/';

    std::time_t t = std::time(nullptr);
    char date[100];
    std::strftime(date, sizeof(date), "%Y-%m-%d_%H-%M-%S", std::localtime(&t));
    std::string filename = path + date + ".log" + std::to_string(log_num) + ".json";

    for (log_file.open(filename); not log_file.is_open(); log_file.open(filename)) {
        if (++log_num > 10)
            std::__throw_runtime_error("Failed: logger init!");
    }

    Logger::isInitialized = true;
}

/**
 * @param
 *  smatch: <loglevel>\: <msg> <funtype> <funname> <cause>
 */
void Logger::loghandler(const int& line_number, const std::smatch &smatch) {

    if (not Logger::isInitialized)
        __init_();

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%H:%M:%S");
    std::string timestamp = oss.str();

    // # TODO: need json validation
    log_file << "{"
           << "\"Line\": " << line_number << ", "
           << "\"Log\": {"
           << "\"Level\": \"" << smatch[1] << "\", "
           << "\"Cause\": \"" << smatch[5] <<"\", "
           << "\"Message\": \"" << smatch[2] << "\", "
           << "\"Funtype\": \"" << smatch[3] <<"\", "
           << "\"Function\": \"" << smatch[4] <<"\" "
           << "}, "
           << "\"Timestamp\": \"" << timestamp << "\" "
           << "}" << std::endl;
}
