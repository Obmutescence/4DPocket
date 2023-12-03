set(csrc simlog/log.cpp
)
include_directories(${CMAKE_CURRENT_LIST_DIR})

add_library(apps SHARED ${csrc})