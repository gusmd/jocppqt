cmake_minimum_required(VERSION 3.2)

project(ClickCounter)

add_executable(ClickCounter main.cpp MainWindow.h MainWindow.cpp)

set_target_properties(ClickCounter
    PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
)

find_package(Qt5Widgets)

target_link_libraries(ClickCounter Qt5::Widgets)
