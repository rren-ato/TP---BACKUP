#include "Source/FuncionesAuxiliares.hpp"

int main() {
    int codigos[MAX_CODIGOS]{};
    int n = 0;
    leer_codigos(codigos, n, "ArchivosDeEntrada/codigos.txt");
    cout << "La Cantidad de codigos es: " << n << endl;
    printArray(codigos, n);
    int pos = linearSearch(codigos, n, 20082031);
    if (pos != -1) {
        cout << "Codigo Encontrado: " << codigos[pos] << endl;
        cout << pos << endl;
    } else
        cout << "Codigo no Encontrado" << endl;
    // cout << "Arreglo de codigos invertido: "<<endl;
    // reverseArray(codigos, n);
    // printArray(codigos, n);
    //
    // cout << "Arreglo de codigos ordenado por Burbuja: "<<endl;
    // bubbleSort(codigos, n);
    // printArray(codigos, n);
    //
    // cout << "Arreglo de codigos ordenado por Seleccion: "<<endl;
    // selectionSort(codigos, n);
    // printArray(codigos, n);
    return 0;
}