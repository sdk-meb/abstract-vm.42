#include <logger.hpp>

std::ofstream Logger::log_file;
bool Logger::isInitialized;

void Logger::__init_() {

    if (Logger::isInitialized)
        throw std::runtime_error("Logger already initialized");
    __re_init_();
}

void Logger::__re_init_() {

    if (Logger::isInitialized)
        log_file.close();

    std::string path = LOG_PATH;
    if (path.back() != '/') path += '/';

    std::time_t t = std::time(nullptr);
    char date[100];
    std::strftime(date, sizeof(date), "%Y-%m-%d_%H-%M-%S", std::localtime(&t));
    std::string filename = path + date + ".log.json";

    log_file.open(filename);
    if (not log_file.is_open())
        throw std::runtime_error("Failed to open log file");

    Logger::isInitialized = true;
}

/**
 * @param
 *  smatch: <loglevel>\: <msg> <funtype> <funname>
 */
void Logger::loghandler(const int& line_number, const std::smatch &smatch) {

    if (not Logger::isInitialized)
        __init_();

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S");
    std::string timestamp = oss.str();

    // # TODO: need json validation
    log_file << "{"
           << "\"timestamp\": \"" << timestamp << "\", "
           << "\"message\": \"" << smatch[2] << "\", "
           << "\"log\": {"
           << "\"level\": \"" << smatch[1] << "\", "
           << "\"funtype\": \"" << smatch[3] <<"\", "
           << "\"function\": \"" << smatch[4] <<"\", "
           << "\"line\": " << line_number
           << "} "
           << "}" << std::endl;
}
