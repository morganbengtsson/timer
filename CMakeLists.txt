cmake_minimum_required(VERSION 3.7)
project(timer)

set(CMAKE_CXX_STANDARD 11)

set(HEADER_FILES timer.hpp)
set(SOURCE_FILES main.cpp timer.cpp)
add_executable(timer ${SOURCE_FILES})

find_package(Threads)
target_link_libraries(timer ${CMAKE_THREAD_LIBS_INIT} )
