//
// Created by aml on 26/06/2026.
//

#include "FuncionesAuxiliares.hpp"

#include "../Estructuras/Cliente.hpp"
#include "../Estructuras/ListaCliente.hpp"
#include "../Estructuras/NodoCliente.hpp"


void apertura_archivo_lectura(ifstream &input, const char *nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (!input.is_open()) {
        cout << "Fue pe" << endl;
        exit(0);
    }
}

void apertura_archivo_escritura(ofstream &output, const char *nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (!output.is_open()) {
        cout << "Fue pe" << endl;
        exit(0);
    }
}

char* leer_cadena(ifstream &input, int n, char delim) {
    char *str, buffer[n];

    input.getline(buffer, n, delim);
    str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;
}

struct Cliente asignar_struct_cliente(struct Cliente &cliente) {
    struct Cliente c;

}


void inicializar_lista_clientes(struct ListaCliente &lista_clientes) {
    lista_clientes.cantidad_clientes =0;
    lista_clientes.cantidad_impares =0;
    lista_clientes.cantidad_impares =0;
    lista_clientes.inicio = nullptr;
    lista_clientes.limite = nullptr;
    lista_clientes.fin = nullptr;

}

bool es_lista_vacia( struct ListaCliente &lista_clientes) {
    return lista_clientes.inicio == nullptr and lista_clientes.fin == nullptr;
}

void insertar_nodo_cliente_inicio(struct ListaCliente &lista_clientes, struct Cliente &c) {

    struct NodoCliente *nuevo_nodo;
    nuevo_nodo = new struct NodoCliente;
    nuevo_nodo->dato = asignar_struct_cliente(c);

}

void leer_lista_clientes(struct ListaCliente &lista_clientes, const char* file_name,
                         const char* opt) {
    //ANTES QUE NADA
    inicializar_lista_clientes(lista_clientes);
    ifstream input; apertura_archivo_lectura(input, file_name);
    struct Cliente c;
    int dni_cliente;
    while (true) {
        input >> dni_cliente;
        if (input.eof()) break;
        input.get();
        c.dni = dni_cliente;
        c.nombre = leer_cadena(input, 40, '\n'):

        if (dni_cliente %2 == 0) {
            insertar_nodo_cliente_inicio(lista_clientes, c);
        }
        else {
            insertar_nodo_cliente_fin(lista_clientes, c);
        }
    }


}


















