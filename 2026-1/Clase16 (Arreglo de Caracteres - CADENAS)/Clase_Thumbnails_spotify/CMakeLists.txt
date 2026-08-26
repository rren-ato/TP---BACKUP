cmake_minimum_required(VERSION 4.1)
project(Clase_Thumbnails_spotify)

set(CMAKE_CXX_STANDARD 20)

add_executable(Clase_Thumbnails_spotify main.cpp
        Source/FuncionesAuxiliares.cpp
        Source/FuncionesAuxiliares.hpp
        Source/Utils.hpp)
