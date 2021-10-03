#include "funciones.h"


void imprimir_vertices(Vertice* vertice){

    if(vertice!= NULL){
        
        printf("Vertice: [%d]\n", vertice->id_vertice);

        imprimir_sublistas(vertice->subLista);

        imprimir_vertices(vertice->sigVertice); 
    
    }

}


void imprimir_sublistas(Subnodo* nodo){

    Subnodo* puntero = nodo;

    while (puntero != NULL){

        printf("\t->[%d]\n", puntero->id_conexion);
        puntero = puntero->sigConexion;
    }

}


void ejecutar_menu(Lista* lista){

    int opcion = -1;

    while (opcion != 0){

        imprimir_menu();
        
        printf("Ingrese la opcion elegida: ");
        scanf("%d", &opcion);

        if(opcion == 1){

            agregar_vertice(lista);

        } else if(opcion == 2){

            agregar_conexion(lista);

        } else if(opcion == 3){

            eliminar_vertice(lista);
        
        } else if(opcion == 4){

            eliminar_conexion(lista);

        } else if(opcion == 5){

            printf("\n---------- Imprimimos vertices y aristas ----------\n");

            imprimir_vertices(lista->cabeza);

        }

    }

}

void imprimir_menu(){

    printf("\n\n---------- Escoja una opcion del menu ----------\n\n");

    printf("1. Agregar vertice\n");
    printf("2. Agregar conexion\n");
    printf("3. Eliminar vertice\n");
    printf("4. Eliminar conexion\n");
    printf("5. Mostrar grafo\n");
    printf("0. Salir...\n");

    printf("\n");

}
