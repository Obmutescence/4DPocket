#include "log.h"

namespace pocket {
namespace simlog {

std::string Logger::getTimeStamp() {
    std::time_t now = std::time(nullptr);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return std::string(buffer);
}


Logger::Logger(const std::string& filename, LogLevel level){
    logFile.open(filename, std::ios_base::app);
    currentLogLevel = level;
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::setLogLevel(LogLevel level) {
    currentLogLevel = level;
}

void Logger::log(const std::string& message) {

    std::ostringstream logStream;
    logStream << "[" << getTimeStamp() << "] ";
    
    switch (currentLogLevel) {
        case LogLevel::DEBUG:
            logStream << "[DEBUG] ";
            break;
        case LogLevel::INFO:
            logStream << "[INFO] ";
            break;
        case LogLevel::WARNING:
            logStream << "[WARNING] ";
            break;
        case LogLevel::ERROR:
            logStream << "[ERROR] ";
            break;
        case LogLevel::CRITICAL:
            logStream << "[CRITICAL] ";
            break;
        default:
            logStream << "[UNKNOWN] ";
            break;
    }
    logStream << message << std::endl;

    std::cout << logStream.str(); // Output to console
    if (logFile.is_open()) {
        logFile << logStream.str(); // Output to file
    }
}


};
};

// int main() {
//     using namespace pocket::simlog;
//     Logger log1("a.txt", LogLevel::INFO);
//     log1.log("dadas");
//     return 0;
// }

