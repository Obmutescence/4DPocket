#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// #include "../../apps/simlog/log.h"
#include "../../apps/simlog/log.cpp"

namespace pocket {
namespace simlog {

namespace py = pybind11;

PYBIND11_MODULE(simlog, m) {
    py::enum_<LogLevel>(m, "LogLevel")
        .value("DEBUG", LogLevel::DEBUG)
        .value("INFO", LogLevel::INFO)
        .value("WARNING", LogLevel::WARNING)
        .value("ERROR", LogLevel::ERROR)
        .value("CRITICAL", LogLevel::CRITICAL)
        .export_values();

    py::class_<Logger>(m, "Logger")
        .def(py::init<const std::string&, LogLevel>())
        .def("set_log_level", &Logger::setLogLevel)
        .def("log", &Logger::log);
}

};  // namespace simlog
};  // namespace pocket