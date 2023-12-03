#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "4dpocket/pybind/simlog/py_simlog.h"

namespace pocket {
namespace pybind {

namespace py = pybind11;

PYBIND11_MODULE(DoraemonPocket, m) {
    m.doc() = "DoraemonPocket!";
    build_simlog(&m);
}

};  // namespace pybind
};  // namespace pocket
