cmake_minimum_required(VERSION 3.8)
project(TestSync)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES SynQApp.cpp SynQApp.h)
add_executable(TestSync ${SOURCE_FILES})