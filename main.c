#include "funciones.h"

int main(){

    Lista* lista = (Lista*)malloc(sizeof(lista));
    lista->cant_vertices = 0;
    lista->cont_id_vertices = 0;


    agregar_vertice(lista);
    agregar_vertice(lista);
    agregar_vertice(lista);
    agregar_vertice(lista);

    printf("\n---------- Imprimimos vertices y aristas ----------\n");

    agregar_conexion(lista);
    agregar_conexion(lista);
    agregar_conexion(lista);

    printf("---------- Eliminamos conexiones ----------\n");
    imprimir_vertices(lista->cabeza);
    
    eliminar_conexion(lista);

    imprimir_vertices(lista->cabeza);

    return 0;
}
