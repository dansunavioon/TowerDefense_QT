cmake_minimum_required(VERSION 3.25)
project(Projet_QT)

set(CMAKE_CXX_STANDARD 23) # si nécessaire
find_package(Qt6 REQUIRED COMPONENTS Widgets Sql Multimedia)
qt_standard_project_setup()
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
add_executable(Projet_QT
        main.cpp
        MainWindow.cpp
        MainWindow.h
        MyScene.cpp
        MyScene.h
        Tower/tower.cpp
        Tower/tower.h
        Map/map_bloc.cpp
        Map/map_bloc.h
        Assaillant/enemy.cpp
        Assaillant/enemy.h
        res.qrc
        DatabaseManager.cpp
        DatabaseManager.h
        MyScene.cpp
        volume_setting.cpp
        volume_setting.h
)
target_compile_options(Projet_QT PRIVATE -Wall -Wextra)
target_link_libraries(Projet_QT PRIVATE Qt6::Widgets Qt6::Sql Qt6::Multimedia) # Qt6::Multimedia