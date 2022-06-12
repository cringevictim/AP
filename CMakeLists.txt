cmake_minimum_required(VERSION 3.22)
project(labs-ap VERSION 0.3)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED true)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)

if(WIN32)
    message(FATAL_ERROR "This is not meant for WINDOWS users((")
endif(WIN32)

message(STATUS "Adding subdirectories")
add_subdirectory("11")
add_subdirectory("12")
add_subdirectory("13")
add_subdirectory("14")
add_subdirectory("15")
add_subdirectory("16")
add_subdirectory("17")
add_subdirectory("KP2")
add_subdirectory("Kursach")
message(STATUS "Adding subdirectories - done")