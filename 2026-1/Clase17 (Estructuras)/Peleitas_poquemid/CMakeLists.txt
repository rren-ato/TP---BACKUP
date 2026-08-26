cmake_minimum_required(VERSION 4.1)
project(Peleitas_poquemid)

set(CMAKE_CXX_STANDARD 20)

add_executable(Peleitas_poquemid main.cpp
        Estructuras/Pokemon.hpp
        Estructuras/Estadisticas.hpp
        Source/Utils.hpp
        Source/FuncionesAuxiliares.cpp
        Source/FuncionesAuxiliares.hpp)
