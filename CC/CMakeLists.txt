cmake_minimum_required(VERSION 3.2)

project(CC)

add_executable(CC main.cpp MainWindow.h MainWindow.cpp)

set_target_properties(CC
    PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
)

find_package(Qt5Widgets)

target_link_libraries(CC Qt5::Widgets)
