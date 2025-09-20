cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

project(item VERSION  0.1.0 LANGUAGES C CXX)

add_executable(item main.cpp)
include_directories(.)