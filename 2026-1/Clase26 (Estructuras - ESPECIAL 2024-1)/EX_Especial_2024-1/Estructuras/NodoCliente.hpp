//
// Created by aml on 26/06/2026.
//

#ifndef EX_ESPECIAL_2024_1_NODOCLIENTE_HPP
#define EX_ESPECIAL_2024_1_NODOCLIENTE_HPP
#include "Cliente.hpp"

struct NodoCliente {
    struct Cliente dato;
    struct NodoCliente *siguiente;
};

#endif //EX_ESPECIAL_2024_1_NODOCLIENTE_HPP