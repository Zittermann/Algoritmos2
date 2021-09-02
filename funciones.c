#include "funciones.h"

Nodo* crear_nodo(Libro* libro){
    Nodo* nodo = (Nodo *)malloc(sizeof(Nodo));
    strncpy(nodo->libro.titulo, libro->titulo, 50);
    nodo->sig = NULL;

    return nodo;

}

void destruir_nodo(Nodo* nodo){
    free(nodo);
}

void insertar_principio(Lista* lista, Libro* libro){
    Nodo* nodo = crear_nodo(libro);
    nodo->sig = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++;
}

void insertar_final(Lista* lista, Libro* libro){
    Nodo* nodo = crear_nodo(libro);
    Nodo* puntero = lista->cabeza;

    if(lista->cabeza == NULL){
        lista->cabeza = nodo;
    } else {
        while(puntero->sig != NULL){
            puntero = puntero->sig;
            puntero->sig = nodo;
        }
    }
    lista->longitud++;
}

void insertar_despues(int n, Lista* lista, Libro* libro){
    Nodo* nodo = crear_nodo(libro);
    if(lista->cabeza == NULL){
        lista->cabeza = nodo;
    } else {
        Nodo* puntero = lista->cabeza;
        int posicion = 0;
        while(posicion < n && puntero->sig != NULL){
            puntero = puntero->sig;
            posicion++;
        }

        nodo->sig = puntero->sig;
        puntero->sig = nodo;

    }
    lista->longitud++;
}

Libro* obtener(int n, Lista* lista){
    if(lista->cabeza == NULL){
        return NULL;
    } else {
        Nodo* puntero = lista->cabeza;
        int posicion = 0;
        while (puntero->sig != NULL && posicion < n){
            puntero = puntero->sig;
            posicion++;
        }
        
        if(posicion != n){
            return NULL;
        } else return &puntero->libro;

    }
}

int contar(Lista* lista){
    return lista->longitud;
}

void eliminar_principio(Lista* lista){
    if(lista->cabeza != NULL){
        Nodo* eliminado = lista->cabeza;
        lista->cabeza = lista->cabeza->sig;
        destruir_nodo(eliminado);
        lista->longitud--;
    }
    
}

void eliminar_ultimo(Lista* lista){
    if(lista->cabeza){

        if(lista->cabeza->sig != NULL){
            
            Nodo* puntero = lista->cabeza;
            while(puntero->sig->sig != NULL){
                puntero = puntero->sig;
            }

            Nodo* eliminado = puntero->sig;
            puntero->sig = NULL;
            destruir_nodo(eliminado);
            lista->longitud--;

        } else {
            Nodo* eliminado = lista->cabeza;
            lista->cabeza = NULL;
            destruir_nodo(eliminado);
            lista->longitud--;
        }

    }
}

void eliminar_elemento(int n, Lista* lista){

    if(lista->cabeza){

        if(n == 0){

            eliminar_principio(lista);

        } else if (n < lista->longitud) {
           
            Nodo* puntero = lista->cabeza;
            int posicion = 0;
            while(puntero->sig && posicion < (n-1)){
                puntero = puntero->sig;
                posicion++;
            }

            Nodo* eliminado = puntero->sig;
            puntero->sig = eliminado->sig;
            destruir_nodo(eliminado);
            lista->longitud--;
        
        }
   
    }

}