//
// Created by aml on 16/04/2026.
//

#include "FuncionesAuxiliares.hpp"

void leer_procesar_clientes_moviles(const char *file_name_entrada, const char *file_name_salida) {
    ifstream input;
    apertura_archivo_lectura(input, file_name_entrada);
    ofstream output;
    apertura_archivo_escritura(output, file_name_salida);

    imprime_titulo("REPORTE DE PLANES MOVILES", output);

    leer_imprimir_datos_moviles(output, monto_acumulado, monto_mayor, monto_mayor_usuario, id_monto_mayor_usuario, dni);

}

void apertura_archivo_lectura(ifstream& input, const char *file_name) {
    input.open(file_name, ios_base::in);
    if (!input.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
}

void leer_imprimir_datos_moviles(ifstream &input, ofstream &output, double monto_acumulado, double monto_mayor_usuario, int id_monto_mayor_usuario, int dni ) {
    int dni;
    char c;

    while (true) {
        input >> c;
        if (input.eof()) break;
        input.ignore(2); // input >> c >> c (se chanca el valor en el ultimo c)
        input >> dni;
        imprime_header(dni, input, output);
        leer_imprimir_planes(input, output);
    }
}

void apertura_archivo_escritura(ofstream& output, const char *file_name) {
    output.open(file_name, ios_base::out);
    if (!output.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
}

//////////////////////////////////////////////////////////
void impresion_estadisticos_finales(ofstream &output, double monto_acumulado, double monto_mayor, int id_monto_mayor_usuario) {
    print_line(ANCHO_REPORTE, '=', output);
    output << "Estadisticos Finales" << endl;
    output << "MontoAcumulado 2025: " << monto_acumulado << endl;
    output << "ID del Usuario con el Monto Mayor: "<< id_monto_mayor_usuario << endl;
    output << "Monto mayor por Usuario: " << monto_mayor << endl;
    print_line(ANCHO_REPORTE, '=', output);

}

//////////////////////////////////////////////////////////
void print_line(int size, char c, ofstream &output) {
for (int i=0 ; i < size; i++ ) output.put(c);
output << endl;
}

void imprime_titulo(const char *titulo, ofstream &output){
    output << setw((ANCHO_REPORTE + 25)/2) << titulo << endl; // output funciona como cout
    print_line(ANCHO_REPORTE, '*', output);
}

void to_uppercase(char &c) {
    if (c >= 'a' && c <= 'z') {
        c = c - ('a' - 'A');
    }
}

void leer_imprimir_nombre(ifstream &input, ofstream &output) {
    char c;

    int cont = 0, size = 0;
    input >> ws;
    while (true) {
        c = input.get();
        if (c == ' ')break;
        if (c == '-') {
            c = ' ';
            cont++;
        }
        if (cont == 2 and c != ' ') to_uppercase(c);
        output.put(c);
        size++;
    }
    int ancho = ANCHO_REPORTE / N_COLUMNS;
    for (int i = 0; i < ancho - size; i++)output.put(' ');
}

void print_date(int date, ofstream &output) { //20250904
    int anio = date / 10000;        // 2025
    int mes = (date / 100) % 100;  // 09
    int dia = date % 100;          // 04

    output << right;
    output << setw(2) << setfill('0') << dia;
    output << "/";
    output << setw(2) << setfill('0') << mes;
    output << "/";
    output << setw(4) << anio;

    output << setfill(' ');  // restaurar fill a espacio
}

int read_date(ifstream &input) {
    int dd, mm, yyyy, date;
    char c;
    input >> yyyy >> c >> mm >> c >> dd;
    date = yyyy * 10000 + mm * 100 + dd;
    return date;
}

void imprime_header_datos(ofstream& output){
    output<<setw(ANCHO_REPORTE/N_COLUMNS)<<"TELEFONO";
    output<<setw(ANCHO_REPORTE/N_COLUMNS)<<"PLAN";
    output<<setw(ANCHO_REPORTE/N_COLUMNS)<<"FECHA INICIO";
    output<<right<<setw(ANCHO_REPORTE/N_COLUMNS)<<"FECHA FIN";
    output<<right<<setw(ANCHO_REPORTE/N_COLUMNS)<<"MONTO"<<endl;
    print_line(ANCHO_REPORTE, '.', output);
}

void imprime_header(int dni, ifstream &input, ofstream &output) {
    output << left << setw(ANCHO_REPORTE / N_COLUMNS) << "DNI";
    output << left << setw(ANCHO_REPORTE / N_COLUMNS) << "NOMBRE" << endl;
    output << setw(ANCHO_REPORTE / N_COLUMNS) << left << dni;
    leer_imprimir_nombre(input, output);
    output << endl;
    print_line(ANCHO_REPORTE, '*', output);
}

void leer_imprimir_planes(ifstream &input, ofstream &output, double &monto_acumulado, double &monto_mayor, double &monto_mayor_usuario, int &id_monto_mayor_usuario, int dni) {
    char c;
    //932479584 PostpagoBasico 2025-08-07 2025-12-18 97.12
    int telefono, inicio_plan, fin_plan;
    double monto = 0.0;
    output << fixed;
    imprime_header_datos(output);
    //Estadistica inicial
    double monto_total = 0.0;
    //cout << dni;
    while (true) {
        input >> telefono; //1
        output << left << setw(ANCHO_REPORTE / N_COLUMNS) << telefono;
        leer_imprimir_nombre(input, output); //2
        inicio_plan = read_date(input); //3
        fin_plan = read_date(input); // 4
        input >> monto; //5
        //output << setw(ANCHO_REPORTE / N_COLUMNS) << "";
        print_date(inicio_plan, output);
        output << setw(ANCHO_REPORTE / N_COLUMNS) << "";
        print_date(fin_plan, output);
        output << setw(ANCHO_REPORTE / N_COLUMNS) << setprecision(2) << monto << endl;
        c = input.get(); //6 (analisis del caracter de espacio o salto de pagina)
        // input.get(c);
        if (c == '\n')break;
        monto_total = monto_total + monto; //monto total += monto;
    }
    print_line(ANCHO_REPORTE, '=', output);
    output << "Monto total por USUARIO" << monto_total << endl;
    print_line(ANCHO_REPORTE, '=', output);
    if (monto_mayor_usuario < monto_total) {
        monto_mayor_usuario = monto_total;
        id_monto_mayor_usuario = dni;
    }
    monto_acumulado = monto_acumulado + monto_total;
}
