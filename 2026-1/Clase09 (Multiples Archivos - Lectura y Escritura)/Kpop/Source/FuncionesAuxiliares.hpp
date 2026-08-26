//
// Created by aml on 24/04/2026.
//

#ifndef KPOP_FUNCIONESAUXILIARES_HPP
#define KPOP_FUNCIONESAUXILIARES_HPP

#include "Utils.hpp"

int read_time();

void open_file_read(ifstream &, const char *);

void open_file_write(ofstream &, const char *);

void calculate_report(const char *file_name_artists,
                      const char *file_name_songs,
                      const char *file_name_plays,
                      const char *file_name_output);

void to_upper(char &c);

#endif //KPOP_FUNCIONESAUXILIARES_HPP