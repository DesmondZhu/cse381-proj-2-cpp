cmake_minimum_required(VERSION 3.8)
project(TestThread)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Driver.cpp Driver.h Sum.cpp Sum.h Summation.cpp Summation.h)
add_executable(Driver.cpp ${SOURCE_FILES})