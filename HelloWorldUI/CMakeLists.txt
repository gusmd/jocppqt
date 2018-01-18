cmake_minimum_required(VERSION 3.2)

project(HelloWorldUI)

add_executable(HelloWordUI main.cpp)

find_package(Qt5Widgets)

target_link_libraries(HelloWordUI Qt5::Widgets)
