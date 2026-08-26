//
// Created by aml on 11/06/2026.
//

#include "FuncionesAuxiliares.hpp"

void open_read_file (ifstream &input, const char* file_name) {
    input.open(file_name, ios::in);
        if (not input.is_open()) {
            cout << "El archivo " << file_name << " no existe" << endl;
        }
}

char* leer_cadena_exacta(ifstream& input, char delim) {
    char *str, buffer[30];
    input.getline(buffer, 30, delim);

    str = new char[strlen(buffer)+1];
    strcpy(str, buffer);

    return str;
}

Estadisticas leer_estadisticas(ifstream& input) {
    Estadisticas stats;
    input >> stats.hp;
    input.ignore();
    input >> stats.ataque;
    input.ignore();
    input >> stats.defensa;
    input.ignore();
    input >> stats.ataque_especial;
    input.ignore();
    input >> stats.defensa_special;
    input.ignore();
    input >> stats.velocidad;
}

Pokemon leer_entero(ifstream& input) {
    Pokemon pok;
    input >> pok.generacion;
}

Pokemon leer_boolean(ifstream& input) {
    Pokemon pok;
    input >> pok.es_legendario;
}

void leer_pokemones(const char* file_name,
                    Pokemon *&pokemones,
                    int &cantidad_pokemones) {
    ifstream input; open_read_file(input, file_name);
    int numero_pokemon =0;

    while (true) {
        input >> numero_pokemon;
        if (input.eof())break;
        pokemones[cantidad_pokemones].numero = numero_pokemon;
        pokemones[cantidad_pokemones].nombre = leer_cadena_exacta(input, ',');
        pokemones[cantidad_pokemones].type_1 = leer_cadena_exacta(input, ',');
        pokemones[cantidad_pokemones].type_2 = leer_cadena_exacta(input, ',');
        pokemones[cantidad_pokemones].estadisticas = leer_estadisticas(input);
        pokemones[cantidad_pokemones].generacion = leer_entero(input);
        pokemones[cantidad_pokemones].es_legendario = leer_boolean(input);
        cantidad_pokemones++;
    }

}