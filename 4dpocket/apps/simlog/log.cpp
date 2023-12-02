#include "log.h"

namespace pocket {
namespace simlog {

// 颜色宏定义
#define NONE "\033[m"
#define RED "\033[0;32;31m"
#define LIGHT_RED "\033[1;31m"
#define GREEN "\033[0;32;32m"
#define LIGHT_GREEN "\033[1;32m"
#define BLUE "\033[0;32;34m"
#define LIGHT_BLUE "\033[1;34m"
#define DARY_GRAY "\033[1;30m"
#define CYAN "\033[0;36m"
#define LIGHT_CYAN "\033[1;36m"
#define PURPLE "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN "\033[0;33m"
#define YELLOW "\033[1;33m"
#define LIGHT_GRAY "\033[0;37m"
#define WHITE "\033[1;37m"

std::string Logger::getTimeStamp() {
    std::time_t now = std::time(nullptr);
    char buffer[80];
    std::strftime(
        buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return std::string(buffer);
}

Logger::Logger(const std::string& filename, LogLevel level) {
    logFile.open(filename, std::ios_base::app);
    currentLogLevel = level;
    if (!logFile.is_open()) {
        std::runtime_error("logger open file failed!");
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::setLogLevel(LogLevel level) { currentLogLevel = level; }

void Logger::debug(const std::string& message) {
    if (currentLogLevel > LogLevel::DEBUG) {
        return;
    }
    std::ostringstream logStream;
    logStream << "[" << getTimeStamp() << "] ";
    logStream << "[D] ";
    logStream << message << std::endl;
    std::cout << LIGHT_BLUE + logStream.str() + NONE;  // Output to console
    if (logFile.is_open()) {
        logFile << logStream.str();  // Output to file
    }
}

void Logger::info(const std::string& message) {
    if (currentLogLevel > LogLevel::INFO) {
        return;
    }
    std::ostringstream logStream;
    logStream << "[" << getTimeStamp() << "] ";
    logStream << "[I] ";
    logStream << message << std::endl;

    std::cout << LIGHT_CYAN + logStream.str() + NONE;  // Output to console
    if (logFile.is_open()) {
        logFile << logStream.str();  // Output to file
    }
}

void Logger::warning(const std::string& message) {
    if (currentLogLevel > LogLevel::WARNING) {
        return;
    }
    std::ostringstream logStream;
    logStream << "[" << getTimeStamp() << "] ";
    logStream << "[W] ";
    logStream << message << std::endl;

    std::cout << LIGHT_PURPLE + logStream.str() + NONE;  // Output to console
    if (logFile.is_open()) {
        logFile << logStream.str();  // Output to file
    }
}

void Logger::error(const std::string& message) {
    if (currentLogLevel > LogLevel::ERROR) {
        return;
    }
    std::ostringstream logStream;
    logStream << "[" << getTimeStamp() << "] ";
    logStream << "[E] ";
    logStream << message << std::endl;

    std::cout << LIGHT_RED + logStream.str() + NONE;  // Output to console
    if (logFile.is_open()) {
        logFile << logStream.str();  // Output to file
    }
}

void Logger::critical(const std::string& message) {
    if (currentLogLevel > LogLevel::CRITICAL) {
        return;
    }
    std::ostringstream logStream;
    logStream << "[" << getTimeStamp() << "] ";
    logStream << "[C] ";
    logStream << message << std::endl;

    std::cout << YELLOW + logStream.str() + NONE;  // Output to console
    if (logFile.is_open()) {
        logFile << logStream.str();  // Output to file
    }
}

};  // namespace simlog
};  // namespace pocket

// int main() {
//     using namespace pocket::simlog;
//     Logger log1("a.txt", LogLevel::DEBUG);
//     log1.debug("1");
//     log1.info("2");
//     log1.warning("3");
//     log1.error("4");
//     log1.critical("5");
//     return 0;
// }
