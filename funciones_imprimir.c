#include "funciones.h"


void imprimir_menu(){

    printf("\n\n---------- Escoja una opcion del menu ----------\n\n");

    printf("1. Agregar vertice\n");
    printf("2. Agregar conexion\n");
    printf("3. Eliminar vertice\n");
    printf("4. Eliminar conexion\n");
    printf("5. Mostrar grafo\n");
    printf("6. Preguntar si el grafo es eureliano\n");
    printf("7. Preguntar si tiene un ciclos.\n");
    printf("0. Salir...\n");

    printf("\n");

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

        } else if(opcion == 6){
            es_eureliano(lista);

        } else if(opcion == 7){
            tiene_ciclos(lista);

        }

    }

}


void imprimir_vertices(Vertice* vertice){

    if(vertice!= NULL){
        
        printf("Vertice: [%d] ", vertice->id_vertice);
        printf("Grado: %d\n", vertice->grado_vertice);

        imprimir_sublistas(vertice->subLista);
        imprimir_vertices(vertice->sigVertice); 
    
    }

}


void imprimir_sublistas(Subnodo* nodo){

    Subnodo* puntero = nodo;

    while (puntero != NULL){

        printf(" ->[%d]", puntero->id_conexion);
        puntero = puntero->sigConexion;
    }

    printf("\n\n");

}
