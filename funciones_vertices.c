#include "funciones.h"


Vertice* crear_vertice(Lista* lista){

    Vertice* vertice = (Vertice*)malloc(sizeof(Vertice));
    vertice->id_vertice = lista->cont_id_vertices;
    vertice->sigVertice = NULL;
    vertice->subLista = NULL;

    lista->cant_vertices++;
    lista->cont_id_vertices++;

    return vertice;

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

        if(puntero == NULL){
            printf("Error: No existe tal vertice");
            puntero = NULL;
        }

        return puntero;
        
    }
    
}

void agregar_vertice(Lista* lista){

    printf("---------- Agregamos un nuevo vertice ----------\n");
    
    Vertice* nuevo_vertice = crear_vertice(lista);
    Vertice* puntero = lista->cabeza;

    if(lista->cabeza == NULL){
       
        lista->cabeza = nuevo_vertice;

    } else {

        while(puntero->sigVertice != NULL){
            puntero = puntero->sigVertice;
        }

        puntero->sigVertice = nuevo_vertice;

    }

    printf("\nAGREGO NUEVO NODO [%d]", nuevo_vertice->id_vertice);

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

    printf("---------- Eliminamos vertices ----------\n");

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

        printf("\nSe ha eliminado el vertice en la posicion [%d]!\n", eliminado->id_vertice);

        free(eliminado);
        lista->cant_vertices--;
    
    } else printf("\nError: Ese vertice no existe\n");
    
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

                free(puntero);

            }
            
        }

    }

}
