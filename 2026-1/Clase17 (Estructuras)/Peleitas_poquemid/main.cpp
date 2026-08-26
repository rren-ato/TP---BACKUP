#include "Source/FuncionesAuxiliares.hpp"

int main() {
    Pokemon pokemones[160];
    //  Pokemon pokemones[MAX_POKEMON]
    int cantidad_pokemones =0;

    leer_pokemones("ArchivosDeDatos/", int &cantidad_pokemones);
    return 0;
}