set(csrc simlog/py_simlog.cpp)

pybind11_add_module(simlog ${csrc})
