cmake_minimum_required(VERSION 3.2)

project(CC)

SET(MACOSX_BUNDLE_BUNDLE_NAME CC)

add_executable(CC MACOSX_BUNDLE main.cpp MainWindow.h MainWindow.cpp)

set_target_properties(CC
    PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    MACOSX_BUNDLE ON
)

find_package(Qt5Widgets)

target_link_libraries(CC Qt5::Widgets)
