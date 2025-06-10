cmake_minimum_required(VERSION 3.10)
project(io_system_simulation)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.cpp")

add_executable(io_simulation ${SOURCES})