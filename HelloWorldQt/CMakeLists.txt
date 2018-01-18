cmake_minimum_required(VERSION 3.2)

project(HelloWorldQt)

add_executable(HelloWordQt main.cpp)

find_package(Qt5Core)

target_link_libraries(HelloWordQt Qt5::Core)
