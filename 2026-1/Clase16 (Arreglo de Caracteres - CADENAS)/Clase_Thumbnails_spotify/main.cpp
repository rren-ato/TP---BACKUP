#include "Source/FuncionesAuxiliares.hpp"

int main() {
    //Sisqo,Thong_Song,253733,hiphop-pop-R&B,0.706
    char *arr_nombre_artistas[MAX_DATOS]{};
    char *arr_nombre_temas[MAX_DATOS]{};
    int arr_duraciones[MAX_DATOS]{};
    char *arr_generos[MAX_DATOS]{};
    double arr_danceabilidad[MAX_DATOS]{};

    int cant_datos = 0;

    lectura_arch_canciones("ArchivosDeDatos/music_dataset_2.csv",arr_nombre_artistas,
                           arr_nombre_temas,
                           arr_duraciones,
                           arr_generos,
                           arr_danceabilidad,
                           cant_datos);

    imprimir_canciones("ArchivosDeReportes/reporte_parcial_canciones.txt", arr_nombre_artistas,
                           arr_nombre_temas,
                           arr_duraciones,
                           arr_generos,
                           arr_danceabilidad,
                           cant_datos,
                           true);

    ordenar_canciones(arr_nombre_artistas,
                           arr_nombre_temas,
                           arr_duraciones,
                           arr_generos,
                           arr_danceabilidad,
                           cant_datos);

    imprimir_canciones("ArchivosDeReportes/canciones_ordenado.txt", arr_nombre_artistas,
                       arr_nombre_temas,
                       arr_duraciones,
                       arr_generos,
                       arr_danceabilidad,
                       cant_datos,
                       false);

    int frecuencias[MAX_GENEROS]{};
    char* generos_sin_repeticion[MAX_GENEROS]{};
    int n_generos =0;
    calcular_frecuencias(arr_generos, cant_datos, frecuencias,
                         generos_sin_repeticion, n_generos);
    cout << n_generos << endl;
    imprimir_frecuencias("ArchivosDeReportes/generos_frecuencias.txt",
                         generos_sin_repeticion, frecuencias, n_generos);

    return 0;
}