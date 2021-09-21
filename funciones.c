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


Vertice* crear_vertice(Lista* lista){

    Vertice* vertice = (Vertice*)malloc(sizeof(Vertice));
    vertice->id_vertice = lista->cont_id_vertices;
    vertice->sigVertice = NULL;
    vertice->subLista = NULL;

    lista->cant_vertices++;
    lista->cont_id_vertices++;

    return vertice;

}


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


Vertice* obtener_vertice(Lista* lista, int n){

    Vertice* puntero = lista->cabeza;

    if(puntero == NULL){
    
        printf("\nError: No existe ningun vertice");
        return NULL;

    } else {

        while (puntero->id_vertice != n && puntero != NULL){
            puntero = puntero->sigVertice;
        }

        return puntero;
        
    }
    
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


void eliminar_primer_vertice(Lista* lista){

    if(lista->cabeza != NULL){

        Vertice* eliminado = lista->cabeza;
        lista->cabeza = lista->cabeza->sigVertice;

        printf("\nSe ha eliminado el vertice en la posicion [%d]!\n", eliminado->id_vertice);

        free(eliminado);
        lista->cant_vertices--;

    } else printf("Error: No existe ningun vertice");

}

void eliminar_vertice(Lista* lista){

    int posicion = 0;
    printf("Ingrese la posicion del vertice a eliminar: ");
    scanf("%d", &posicion);

    if(posicion == 0){

        eliminar_primer_vertice(lista);

    } else if (posicion > 0 && posicion < lista->cant_vertices) {
        
        Vertice* puntero = lista->cabeza;

        while(puntero->id_vertice != posicion-1){
            puntero = puntero->sigVertice;    
        }

        Vertice* eliminado = puntero->sigVertice;
        puntero->sigVertice = eliminado->sigVertice;

        free(eliminado);
        lista->cant_vertices--;
    
    } else printf("\nError: No se pudo eliminar el vertice");
    
}