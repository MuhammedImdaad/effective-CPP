cmake_minimum_required(VERSION 3.5)
# Optionally, you can specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(item VERSION 0.1.0 LANGUAGES C CXX)

# Add the executable
add_executable(item main.cpp)

# You may need to add additional settings here, such as compiler flags or include directories
include_directories(.)

find_package(Boost 1.84.0 REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})