cmake_minimum_required(VERSION 3.8)
project(TestApplet)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES ClockApplet.cpp ClockApplet.h)
add_executable(ClockApplet ${SOURCE_FILES})