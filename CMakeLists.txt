cmake_minimum_required(VERSION 3.10)
project(io_system_simulation)

set(CMAKE_CXX_STANDARD 17)

add_executable(io_simulation
    src/device_driver.cpp
    src/io_dispatcher.cpp
    src/main.cpp
)