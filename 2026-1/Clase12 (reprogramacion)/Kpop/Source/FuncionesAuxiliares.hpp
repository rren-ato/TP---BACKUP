//
// Created by aml on 24/04/2026.
//

#ifndef KPOP_FUNCIONESAUXILIARES_HPP
#define KPOP_FUNCIONESAUXILIARES_HPP

#include "Utils.hpp"


int read_time();

void open_file_read(ifstream &, const char *);

void open_file_write(ofstream &, const char *);

void cargar_artistas(const char *file_name, int *fechas_artistas, char *codigos_char_artistas,
                     int *codigos_int_artistas, double *ratings_artistas, int &n_artistas);

void probar_artistas(const char *file_name, int *fechas_artistas, char *codigos_char_artistas,
                     int *codigos_int_artistas, double *ratings_artistas, int n_artistas);


void cargar_canciones(const char *file_name, int *codigos_canciones, int *duraciones_canciones, int &n_canciones);

void probar_canciones(const char *file_name, int *codigos_canciones, int *duraciones_canciones, int n_canciones);

void procesar_reproducciones(const char *file_name, int *codigos_int_artistas,
                             int *codigos_canciones, int *duraciones_canciones,
                             int *replays_total_time, double *revenue_total, int *total_replays,
                             int n_artistas, int n_canciones, double precio_mil);

void generar_reporte(const char *file_name, int *fechas_artistas, char *codigos_char_artistas,
                     int *codigos_int_artistas, double *ratings_artistas, int *codigos_canciones,
                     int *duraciones_canciones, int *replays_total_time, double *revenue_total,
                     int *total_replays, int n_artistas, int n_canciones);


#endif //KPOP_FUNCIONESAUXILIARES_HPP