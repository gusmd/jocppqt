cmake_minimum_required(VERSION 3.2)

project(Cadastro)

set(MACOSX_BUNDLE_BUNDLE_NAME Cadastro)

set(CADASTRO_INCLUDE
    MainWindow.h
    ContactInfo.h
)

set(CADASTRO_SRC
    main.cpp

    MainWindow.cpp
    ContactInfo.cpp
)

add_executable(Cadastro MACOSX_BUNDLE ${CADASTRO_SRC} ${CADASTRO_INCLUDE})

set_target_properties(Cadastro
    PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    MACOSX_BUNDLE ON
)

find_package(Qt5Widgets)

target_link_libraries(Cadastro Qt5::Widgets)
