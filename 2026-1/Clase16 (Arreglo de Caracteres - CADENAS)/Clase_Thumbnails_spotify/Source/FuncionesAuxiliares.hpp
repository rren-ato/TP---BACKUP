//
// Created by Renato on 7/06/2026.
//

#ifndef CLASE_THUMBNAILS_SPOTIFY_FUNCIONESAUXILIARES_HPP
#define CLASE_THUMBNAILS_SPOTIFY_FUNCIONESAUXILIARES_HPP

#include "Utils.hpp"

void apertura_archivo_lectura(ifstream &input, const char *nombre_archivo);
void apertura_archivo_escritura(ofstream &output, const char *nombre_archivo);

void imprimir_linea(ofstream &output, char c);
void impresion_titulo(ofstream &output, const char *titulo);

char *leer_cadena(ifstream &input, char del);
int leer_entero(ifstream &input);
double leer_double(ifstream &input);

void lectura_arch_canciones(const char* file_name, char **artistas, char **titulos,
                            int *reproducciones, char **generos, double *bailables,
                            int &n_canciones);

void swap_int (int &a, int &b);
void swap_double (double &a, double &b);
void swap_str( char*& a, char*& b);

void imprimir_canciones(const char* file_name, char **artistas, char **titulos,
                            int *reproducciones, char **generos, double *bailables,
                            int n_canciones, bool es_parcial);

void ordenar_canciones(char **artistas, char **titulos,
                            int *reproducciones, char **generos, double *bailables,
                            int n_canciones);

int buscar_cadena(char* genero, char** genero_sin_repeticion, int n_generos);
char* asignar_cadena(char* cadena);

void insertar_genero(char* genero, char** genero_sin_repeticion, int* frecuencias, int &n_generos);
void calcular_frecuencias(char** arr_generos_totales, int cant_datos, int* frecuencias,
                          char** genero_sin_repeticion, int &n_generos);
void imprimir_frecuencias(const char* file_name, char** genero_sin_repeticion, int *frecuencias,
                          int n_generos);

#endif //CLASE_THUMBNAILS_SPOTIFY_FUNCIONESAUXILIARES_HPP