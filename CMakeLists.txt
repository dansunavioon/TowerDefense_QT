cmake_minimum_required(VERSION 3.25)
project(Projet_QT)

set(CMAKE_CXX_STANDARD 23) # si nécessaire
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()
set(CMAKE_AUTOMOC ON)
add_executable(Projet_QT
        main.cpp
        MainWindow.cpp
        MyScene.cpp
        MainWindow.cpp
        MyScene.cpp
        MyScene.cpp
        Tower/tower.cpp
        Tower/tower.h
        Tower/tower.h
        Position/positon.cpp
        Position/positon.h
        Map/map_bloc.cpp
        Map/map_bloc.h
        Map/map_bloc.h
        Assaillant/enemy.cpp
        Assaillant/enemy.h
        Assaillant/enemy.h

)
target_link_libraries(Projet_QT PRIVATE Qt6::Widgets)