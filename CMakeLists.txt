cmake_minimum_required(VERSION 3.25)
project(Projet_QT)

set(CMAKE_CXX_STANDARD 23) # si nécessaire
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
add_executable(Projet_QT
        main.cpp
        MainWindow.cpp
        MyScene.cpp
        Tower/tower.cpp
        Tower/tower.h
        Map/map_bloc.cpp
        Map/map_bloc.h
        Assaillant/enemy.cpp
        Assaillant/enemy.h
        Assaillant/enemy.h
        res.qrc

)
target_link_libraries(Projet_QT PRIVATE Qt6::Widgets) #Qt6::Multimedia