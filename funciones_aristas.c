#include "funciones.h"


Subnodo* crear_subnodo(int n){

    Subnodo* conectar = (Subnodo*)malloc(sizeof(Subnodo));
    conectar->id_conexion = n;
    conectar->sigConexion = NULL;

    return conectar;

}


void agregar_conexion(Lista* lista){

    printf("\n\n---------- Agregaremos una nueva conexion ----------");

    int id_primero, id_segundo;
    printf("\nIngrese el primer vertice: ");
    scanf("%d", &id_primero);
    Vertice* vertice1 = obtener_vertice(lista, id_primero);


    printf("Ingrese el segundo vertice: ");
    scanf("%d", &id_segundo);
    Vertice* vertice2 = obtener_vertice(lista, id_segundo);


    establecer_conexion(vertice1, id_segundo);
    establecer_conexion(vertice2, id_primero);

    printf("\nSe agregado una conexion correctamente!\n");

}


void establecer_conexion(Vertice* vertice, int id_nodo){

    Subnodo* conectar = vertice->subLista;
    Subnodo* nuevo_subnodo = crear_subnodo(id_nodo); 

    if(vertice->subLista == NULL){

        vertice->subLista = nuevo_subnodo;

    } else {

        while (conectar->sigConexion != NULL){
            conectar = conectar->sigConexion;
        }

        conectar->sigConexion = nuevo_subnodo;

    }

    vertice->grado_vertice++;

}


void eliminar_conexion(Lista* lista){

    printf("---------- Eliminamos conexiones ----------\n");

    int id_primero, id_segundo;
    printf("\nIngrese el primer vertice: ");
    scanf("%d", &id_primero);
    Vertice* vertice1 = obtener_vertice(lista, id_primero);


    printf("Ingrese el segundo vertice: ");
    scanf("%d", &id_segundo);
    Vertice* vertice2 = obtener_vertice(lista, id_segundo);

    desconectar_vertices(vertice2, id_primero);
    desconectar_vertices(vertice1, id_segundo);

    printf("Se ha eliminado la conexion entre el vertice [%d] y el [%d]\n", id_primero, id_segundo);

}


void desconectar_vertices(Vertice* vertice, int id_nodo){

    Subnodo* puntero = vertice->subLista;
    Subnodo* anterior = puntero;
    

    if(vertice->subLista == NULL){

        printf("\nError: El vertice [%d] no tiene ninguna conexion\n\n", vertice->id_vertice);

    } else {
        
        // Salgo si, y solo si, encontre la conexion ó ya no hay mas conexiones 
        while (puntero->id_conexion != id_nodo && puntero->sigConexion != NULL){
            anterior = puntero;
            puntero = puntero->sigConexion;
        }

         // Si la conexion donde paro el loop no es la que buscaba entonces la conexion no existe 
        if(puntero->id_conexion != id_nodo){

            printf("\nError: El vertice [%d] no tiene conexion con el [%d]\n\n", vertice->id_vertice, id_nodo);

        // Las siguientes condiciones solo se cumpliran si la conexion que buscamos existe
        } else {
            /*
             * La cabeza de la sublista es la conexion que estamos buscando
             */
            if(puntero == vertice->subLista){
                vertice->subLista = puntero->sigConexion;
            } else {
                /*
                 * La ultima sublista es conexion la que estamos buscando
                 */
                if(puntero->sigConexion == NULL){
                    anterior->sigConexion = NULL;
                /*
                 * La sublista que buscamos no es la primera ni la ultima conexion
                 */
                } else {
                    
                    anterior->sigConexion = puntero->sigConexion;

                }
                //vertice->grado_vertice -= 1;
                free(puntero);

            }
            
        }

    }

}