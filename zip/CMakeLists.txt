cmake_minimum_required(VERSION 3.5) #sprawdzanie wersji CMake

project(zip LANGUAGES CXX) #Nazwa Projektu

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON) #czy CMake będzie obsługiwać generator kodu Qt uic automatycznie
set(CMAKE_AUTOMOC ON) #wartością logiczną określającą, czy CMake będzie obsługiwać preprocesor Qt moc automatycznie
set(CMAKE_AUTORCC ON) #czy CMake będzie obsługiwać generator kodu rcc Qt automatycznie

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Funkcja find_package przyjmuje nazwę biblioteki jako argument i wywołuje
#CMake w celu znalezienia skryptu do skonfigurowania zmiennych dla tej biblioteki
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_executable(zip
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    zipper.cpp
    zipper.h )

#Łączenie programu z biblioteką
target_link_libraries(zip PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
