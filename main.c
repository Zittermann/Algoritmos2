#include "funciones.h"

int main(){

    Lista* lista = (Lista*)malloc(sizeof(lista));
    lista->cant_vertices = 0;
    lista->cont_id_vertices = 0;


    agregar_vertice(lista);
    agregar_vertice(lista);
    agregar_vertice(lista);

    printf("\n---------- Imprimimos vertices y aristas ----------\n");
    imprimir_vertices(lista->cabeza);

    printf("---------- Eliminamos vertice ----------\n");
    eliminar_vertice(lista);

    imprimir_vertices(lista->cabeza);

    return 0;
}
