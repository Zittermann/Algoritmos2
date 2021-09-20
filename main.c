#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

int main(){

    Lista* lista = (Lista*)malloc(sizeof(lista));
    lista->cant_vertices = 0;


    agregar_vertice(lista);
    agregar_vertice(lista);
    agregar_vertice(lista);
    
    agregar_conexion(lista);
    agregar_conexion(lista);

    printf("---------- Imprimimos vertices y aristas ----------\n");
    imprimir_vertices(lista->cabeza);

    return 0;
}
