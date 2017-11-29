cmake_minimum_required(VERSION 3.8)
project(CriticalSection)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Algorithm_3.cpp Algorithm_3.h Algorithm_3.cpp Algorithm_3.h MutualExclusion.cpp MutualExclusion.h TestAlgorithm.cpp Worker.cpp Worker.h)
add_executable(TestAlgorithm.cpp ${SOURCE_FILES})