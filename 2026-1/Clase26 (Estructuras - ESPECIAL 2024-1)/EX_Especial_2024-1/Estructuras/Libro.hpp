//
// Created by aml on 26/06/2026.
//

#ifndef EX_ESPECIAL_2024_1_LIBRO_HPP
#define EX_ESPECIAL_2024_1_LIBRO_HPP

struct Libro {
  char* codigo;
  char* titulo;
  char* autor;
  double precio;
  struct Libreria *librerias; //maximo 5 librerias por libro
  int cantidadLibrerias;
  double totalVentas;
  int unidadVendidas;
  int cantidadBuenasCalificaciones;
  double sumaBuenasCalificaciones;
  int cantidadMalasCalificaciones;
  dobule sumaMalasCalificaciones;

};

#endif //EX_ESPECIAL_2024_1_LIBRO_HPP