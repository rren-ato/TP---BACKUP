//
// Created by aml on 11/06/2026.
//

#ifndef PELEITAS_POQUEMID_POKEMON_H
#define PELEITAS_POQUEMID_POKEMON_H
#include "Estadisticas.hpp"

struct Pokemon {
    //por pokemon
    int numero;
    char* nombre;
    char* type_1;
    char* type_2;;
    Estadisticas estadisticas;
    int generacion;
    bool es_legendario;
};

#endif //PELEITAS_POQUEMID_POKEMON_H