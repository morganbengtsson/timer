cmake_minimum_required(VERSION 3.7)
project(timer)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(external/Catch)
include_directories(external/Catch/include)

set(HEADER_FILES timer.hpp)
set(SOURCE_FILES main.cpp timer.cpp)
add_executable(timer ${SOURCE_FILES})

add_executable(timer_test test.cpp timer.cpp)

find_package(Threads)
target_link_libraries(timer ${CMAKE_THREAD_LIBS_INIT} )
target_link_libraries(timer_test ${CMAKE_THREAD_LIBS_INIT} )