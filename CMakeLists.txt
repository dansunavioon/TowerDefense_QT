cmake_minimum_required(VERSION 3.25)
project(Projet_QT)

set(CMAKE_CXX_STANDARD 23) # si nécessaire
set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()
add_executable(Projet_QT
        main.cpp
        MainWindow.cpp
        MyScene.cpp
        MainWindow.cpp
        MyScene.cpp
        MyScene.cpp
)
target_link_libraries(Projet_QT PRIVATE Qt6::Widgets)