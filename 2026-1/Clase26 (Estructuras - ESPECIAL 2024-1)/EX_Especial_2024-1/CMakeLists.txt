cmake_minimum_required(VERSION 4.1)
project(EX_Especial_2024_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(EX_Especial_2024_1 main.cpp
        Estructuras/Cliente.hpp
        Estructuras/Libreria.hpp
        Source/FuncionesAuxiliares.cpp
        Source/FuncionesAuxiliares.hpp
        Source/Utils.hpp
        Estructuras/Venta.hpp
        Estructuras/Libro.hpp
        Estructuras/NodoCliente.hpp
        Estructuras/ListaCliente.hpp)
