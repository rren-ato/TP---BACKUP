//
// Created by Renato on 7/06/2026.
//

#include "FuncionesAuxiliares.hpp"

#include <set>

void apertura_archivo_lectura(ifstream &input, const char *nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (!input.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombre_archivo << endl;
        exit(0);
    }
}

void apertura_archivo_escritura(ofstream &output, const char *nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (!output.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombre_archivo << endl;
        exit(0);
    }
}

void imprimir_linea(ofstream &output, char c) {
    for (int i = 0; i < ANCHO_REPORTE; i++)
        output.put(c);
    output << endl;
}

void impresion_titulo(ofstream &output, const char *titulo) {
    output << setw((ANCHO_REPORTE + strlen(titulo)) / 2) << titulo << endl;
    imprimir_linea(output, '=');
}

char *leer_cadena(ifstream &input, char until) {
    char buffer[MAX_TAM_CADENA];
    char *cadena; //Arr Dinamico
    input.getline(buffer, MAX_TAM_CADENA, until);
    //DESIGNAR MEMORIA (asignar)
    cadena = new char[strlen(buffer) +1];
    strcpy(cadena, buffer);
    return cadena;
}

int leer_entero(ifstream &input) {
    int dato;
    input >> dato;
    input.get(); //Se coma la "," (coma)
    return dato;
}

double leer_double(ifstream &input) {
    double dato;
    input >> dato;
    input.get(); //Se coma la "\n" (fin de datta)
    return dato;
}

void lectura_arch_canciones(const char* file_name, char **artistas, char **titulos,
                            int *reproducciones, char **generos, double *bailables,
                            int &n_canciones) {

    ifstream input; apertura_archivo_lectura(input, file_name);
    //Sisqo,Thong_Song,253733,hiphop-pop-R&B,0.706
    char *artista; //Activo cadena (memoria dinamica)
    while (true) {
        //Sisqo,Thong_Song,253733,hiphop-pop-R&B,0.706
        artista = leer_cadena(input, ',');
        if (input.eof()) {
            delete[] artista;
            break;
        }
        titulos[n_canciones] = leer_cadena(input, ',');
        reproducciones[n_canciones] = leer_entero(input); //recordar input.get()
        generos[n_canciones] = leer_cadena(input, ',');
        bailables[n_canciones] = leer_double(input);
        //DECLARACION DE ARREGLO (PRIMERO DEBE PASAR EL .eof)
        artistas[n_canciones] = artista;
        n_canciones++;
    }
}

void swap_int (int &a, int &b) {
    int aux;
    aux = a;
    a=b;            // a = b -->   b = a
    b = aux;
}

void swap_double (double &a, double &b) {
    double aux;
    aux = a;
    a = b;
    b = aux;
}

void swap_str( char*& a, char*& b) {
    char* aux;
    aux = a;
    a = b;
    b= aux;
}

void ordenar_canciones(char **artistas, char **titulos,
                            int *reproducciones, char **generos, double *bailables,
                            int n_canciones) {
    for (int i = 0; i < n_canciones - 1; i++) {
        for (int j = i+1; j < n_canciones; j++) {
            // artista(i) > artista(j) Y pueden ser IGUALES / titulos(i) > titulos(j)
            if (strcmp(artistas[i], artistas[j]) > 0 or strcmp(artistas[i], artistas[j]) == 0 and
                strcmp(titulos[i], titulos[j]) > 0) {
                swap_str(artistas[i], artistas[j]);
                swap_str(titulos[i], titulos[j]);
                swap_int(reproducciones[i], reproducciones[j]);
                swap_str(generos[i], generos[j]);
                swap_double(bailables[i], bailables[j]);
            }
        }
    }
}

void imprimir_canciones(const char* file_name, char **artistas, char **titulos,
                            int *reproducciones, char **generos, double *bailables,
                            int n_canciones, bool es_parcial) {
    ofstream output; apertura_archivo_escritura(output, file_name);
    //HEADERS
    if (es_parcial == true) {
        output << setw(ANCHO_REPORTE / 2) << "REPORTE PARCIAL DE CANCIONES" << endl;
    }
    else {
        output << setw(ANCHO_REPORTE / 2) << "REPORTE FINAL" << endl;
    }
    output << setw(ANCHO_REPORTE / 5) << "ARTISTAS";
    output << setw(ANCHO_REPORTE / 5) << "TITULOS";
    output << setw(ANCHO_REPORTE / 5) << "REPRODUCCIONES";
    output << setw(ANCHO_REPORTE / 5) << "GENEROS";
    output << setw(ANCHO_REPORTE / 5) << "BAILABLES";
    output << endl;
    for (int i=0; i < n_canciones; i++) {
        //DATOS
        output << setw(ANCHO_REPORTE / 5) << artistas[i];
        output << setw(ANCHO_REPORTE / 5) << titulos[i];
        output << setw(ANCHO_REPORTE / 5) << reproducciones[i];
        output << setw(ANCHO_REPORTE / 5) << generos[i];
        output << setw(ANCHO_REPORTE / 5) << bailables[i];
        output << endl;
    }
}

int buscar_cadena(char* genero, char** genero_sin_repeticion, int n_generos) {
    for (int i=0; i< n_generos; i++) {
        if (strcmp(genero,genero_sin_repeticion[i]) == 0) return i;
    }
    return -1;
}

char* asignar_cadena(char* cadena) {
    char* str;
    str = new char[strlen(cadena) + 1];
    strcpy(str, cadena);
    return str;
}

void insertar_genero(char* genero, char** genero_sin_repeticion, int* frecuencias, int &n_generos) {
    int pos;
    pos = buscar_cadena(genero, genero_sin_repeticion, n_generos);
    if (pos == -1) {
        genero_sin_repeticion[n_generos] = asignar_cadena(genero);
        frecuencias[n_generos] = 1;
        n_generos++;
    }
    else {
        frecuencias[pos]++;
    }
}

void calcular_frecuencias(char** arr_generos_totales, int cant_datos, int* frecuencias,
                          char** genero_sin_repeticion, int &n_generos) {
    char genero[40]{};
    int k=0;

    cout << cant_datos << endl;
    for (int i=0; i < cant_datos; i++) {
        char* generos;
        generos = asignar_cadena(arr_generos_totales[i]);
        //hiphop-pop-R&B
        for (int j=0; j<strlen(generos)+1; j++) {
            if (generos[j] == '-' or generos[j] == '\0') {
                //hiphop
                genero[k] = '\0';
                insertar_genero(genero, genero_sin_repeticion, frecuencias, n_generos);
                k=0; //reseteo por palabra (genero)
            }
            else {
                genero[k] = generos[j];
                k++;
            }
        }
    }
}

void imprimir_frecuencias(const char* file_name, char** genero_sin_repeticion, int *frecuencias,
                          int n_generos) {
    ofstream output; apertura_archivo_escritura(output, file_name);
    for (int i=0; i< n_generos; i++) {
        output << setw(40) << genero_sin_repeticion[i];
        output << setw(10) << frecuencias[i] << endl;
    }
}
