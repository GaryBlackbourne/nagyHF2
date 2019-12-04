cmake_minimum_required(VERSION 3.12)
project(nagyHF2)

set(CMAKE_CXX_STANDARD 17)

add_executable(nagyHF2 main.cpp System.cpp System.h Signal.cpp Signal.h IO.cpp IO.h)