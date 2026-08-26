//
// Created by aml on 26/06/2026.
//

#ifndef EX_ESPECIAL_2024_1_LISTACLIENTE_HPP
#define EX_ESPECIAL_2024_1_LISTACLIENTE_HPP

struct ListaCliente {
  struct NodoCliente* inicio;
  struct NodoCliente* limite;
  struct NodoCliente* fin;
    int cantidad_pares;
    int cantidad_impares;
    int cantidad_clientes;
};

#endif //EX_ESPECIAL_2024_1_LISTACLIENTE_HPP