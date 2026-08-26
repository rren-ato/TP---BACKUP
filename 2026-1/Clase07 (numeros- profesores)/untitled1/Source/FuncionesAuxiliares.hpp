//
// Created by aml on 16/04/2026.
//

#ifndef UNTITLED1_FUNCIONESAUXILIARES_HPP
#define UNTITLED1_FUNCIONESAUXILIARES_HPP

#include "Utils.hpp"
void print_line(int size, char c, ofstream &output);
void imprime_titulo(const char *titulo, ofstream &output);
void to_uppercase(char &c);
void print_date(int date, ofstream &output);
int read_date(ifstream &input);

void leer_imprimir_nombre(ifstream &input, ofstream &output);
void imprime_header_datos(ofstream& output);
void imprime_header(int dni, ifstream &input, ofstream &output);
void leer_imprimir_planes(ifstream &input, ofstream &output);

void leer_procesar_clientes_moviles(const char* file_name_entrada, const char* file_name_salida);
void leer_imprimir_datos_moviles(ifstream &input, ofstream &output);
void apertura_archivo_lectura(ifstream& input, const char *file_name);
void apertura_archivo_escritura(ofstream& output, const char *file_name);
void impresion_estadisticos_finales(ofstream &output, double monto_acumulado, double monto_mayor);


#endif //UNTITLED1_FUNCIONESAUXILIARES_HPP