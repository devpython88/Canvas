cmake_minimum_required(VERSION 3.16)
project(Canvas)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-narrowing")

set(HEADERS src/Canvas/window.hpp src/Canvas/graphics.hpp src/Canvas/audio.hpp src/Canvas/ui.hpp
    src/Canvas/input.hpp src/Canvas/math.hpp src/Canvas/dialog.hpp src/Canvas/misc.hpp src/Canvas/3D/graphics3d.hpp)

set(SOURCES src/Canvas/window.cpp src/Canvas/graphics.cpp src/Canvas/audio.cpp src/Canvas/ui.cpp
    src/Canvas/input.cpp src/Canvas/math.cpp src/Canvas/dialog.cpp src/Canvas/misc.cpp src/Canvas/3D/graphics3d.cpp)

set(UNIT_TEST_1 UnitTest1)
set(UNIT_TEST_2 UnitTest2)

set(LIBRARY canvas)

add_executable(${UNIT_TEST_1} src/unit_test_1.cpp ${HEADERS} ${SOURCES})
add_executable(${UNIT_TEST_2} src/unit_test_2.cpp ${HEADERS} ${SOURCES})

add_library(${LIBRARY} STATIC ${SOURCES})

target_link_libraries(${UNIT_TEST_1} raylib stdc++)
target_link_libraries(${UNIT_TEST_2} raylib stdc++)
