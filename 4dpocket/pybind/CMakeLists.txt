set(csrc    pybind.cpp
            simlog/py_simlog.cpp)

include_directories(${CMAKE_CURRENT_LIST_DIR})

pybind11_add_module(DoraemonPocket ${csrc})

target_link_libraries(DoraemonPocket PRIVATE apps)