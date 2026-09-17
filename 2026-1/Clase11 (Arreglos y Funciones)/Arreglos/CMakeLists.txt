cmake_minimum_required(VERSION 4.1)
project(Arreglos)

set(CMAKE_CXX_STANDARD 20)

add_executable(Arreglos main.cpp
        Source/FuncionesAuxiliares.cpp
        Source/FuncionesAuxiliares.hpp
        Source/Utils.hpp)
