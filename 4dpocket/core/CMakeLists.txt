set(csrc context.cpp)

include_directories(${CMAKE_CURRENT_LIST_DIR})

add_library(core SHARED ${csrc})