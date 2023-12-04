#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "4dpocket/apps/simlog/log.h"

namespace pocket {
namespace pybind {

namespace py = pybind11;
using namespace simlog;

void build_simlog(py::module *m);

};  // namespace pybind
};  // namespace pocket



