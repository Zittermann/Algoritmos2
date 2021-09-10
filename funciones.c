#include "funciones.h"


void imprimir_vertices(Vertice* vertice){

    if(vertice!= NULL){
        
        printf("Vertice: [%d]\n", vertice->id_vertice);

        imprimir_sublistas(vertice->subLista);

        imprimir_vertices(vertice->sigVertice); 
    
    }

}

/*
void imprimir_sublistas(Subnodo* nodo){

    if(nodo != NULL){
        printf("\t->[%d]\n", nodo->id_conexion);
        imprimir_sublistas(nodo->sigConexion);
    }

}
*/

Vertice* crear_vertice(Lista* lista){

    Vertice* vertice = (Vertice*)malloc(sizeof(Vertice));
    vertice->id_vertice = lista->cant_vertices;
    vertice->sigVertice = NULL;
    vertice->subLista = NULL;

    lista->cant_vertices++;

    return vertice;

}



void agregar_conexion(Lista* lista){

    printf("\n\n---------- Agregaremos una nueva conexion ----------");

    int primer_vertice, segundo_vertice;
    printf("\nIngrese el primer vertice: ");
    scanf("%d", &primer_vertice);
    Vertice* vertice1 = obtener_vertice(lista, primer_vertice);


    printf("Ingrese el segundo vertice: ");
    scanf("%d", &segundo_vertice);
    Vertice* vertice2 = obtener_vertice(lista, segundo_vertice);

        
    establecer_conexion(vertice1, segundo_vertice);
    establecer_conexion(vertice2, primer_vertice);

    printf("\nSe agregado una conexion correctamente!\n");

}



Vertice* obtener_vertice(Lista* lista, int n){

    Vertice* puntero = lista->cabeza;

    if(puntero == NULL){
    
        printf("\nError: No existe ningun vertice");
        return NULL;

    } else {

        while (puntero->id_vertice != 1 && puntero != NULL){
            puntero = puntero->sigVertice;
        }

        return puntero;

    }
    

}


void establecer_conexion(Vertice* vertice, int nodo){

    Subnodo* conectar = vertice->subLista;

    if(conectar == NULL){

        conectar = (Subnodo*)malloc(sizeof(Subnodo));
        conectar->id_conexion = nodo;

    } else {

        while (conectar != NULL){
            conectar = conectar->sigConexion;
        }
        
        conectar = (Subnodo*)malloc(sizeof(Subnodo));
        conectar->id_conexion = nodo;
        conectar->sigConexion = NULL;
    }

}


void agregar_vertice(Lista* lista){
    
    Vertice* nuevo_vertice = crear_vertice(lista);
    Vertice* puntero = lista->cabeza;

    if(lista->cabeza == NULL){
        
        lista->cabeza = nuevo_vertice;
        printf("CREO PRIMER NODO [%d]", lista->cabeza->id_vertice);

    } else {

        while(puntero->sigVertice != NULL){
            puntero = puntero->sigVertice;
        }

        puntero->sigVertice = nuevo_vertice;

        printf("\nAGREGO NUEVO NODO [%d]", nuevo_vertice->id_vertice);

    }
}