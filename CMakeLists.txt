cmake_minimum_required(VERSION 3.16)
project(Canvas)


set(CMAKE_CXX_STANDARD 17)

set(HEADERS src/Canvas/window.hpp src/Canvas/graphics.hpp src/Canvas/audio.hpp src/Canvas/ui.hpp
    src/Canvas/input.hpp src/Canvas/math.hpp src/Canvas/dialog.hpp)

set(SOURCES src/main.cpp src/Canvas/window.cpp src/Canvas/graphics.cpp src/Canvas/audio.cpp src/Canvas/ui.cpp
    src/Canvas/input.cpp src/Canvas/math.cpp src/Canvas/dialog.cpp)

set(TARGET test)
set(LIBRARY canvas)

add_executable(${TARGET} ${HEADERS} ${SOURCES})

add_library(${LIBRARY} STATIC ${SOURCES})

target_link_libraries(${TARGET} raylib stdc++)