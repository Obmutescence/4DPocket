#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "4dpocket/apps/simlog/log.h"
#include "4dpocket/pybind/simlog/py_simlog.h"

namespace pocket {
namespace pybind {

void build_simlog(py::module *m) {
    // 子模块
    py::module m_simlog = m->def_submodule("simlog", "simlog");

    py::enum_<LogLevel>(m_simlog, "LogLevel")
        .value("DEBUG", LogLevel::DEBUG)
        .value("INFO", LogLevel::INFO)
        .value("WARNING", LogLevel::WARNING)
        .value("ERROR", LogLevel::ERROR)
        .value("CRITICAL", LogLevel::CRITICAL)
        .export_values();

    py::class_<Logger>(m_simlog, "Logger")
        .def(py::init<const std::string&, LogLevel>(),
             py::arg("filename"),
             py::arg("level") = LogLevel::INFO)
        .def("set_log_level", &Logger::setLogLevel, py::arg("level"))
        .def("debug", &Logger::debug, py::arg("message"))
        .def("info", &Logger::info, py::arg("message"))
        .def("warning", &Logger::warning, py::arg("message"))
        .def("error", &Logger::error, py::arg("message"))
        .def("critical", &Logger::critical, py::arg("message"));
}

};  // namespace pybind
};  // namespace pocket