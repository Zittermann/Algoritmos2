#include "funciones.h"

Nodo * crear_nodo(int id){
    Nodo *nodo=(Nodo *)malloc(sizeof(nodo));
    nodo->vertice_a_visitar=id;
    nodo->sig=NULL;
    return nodo;
}

void destruir_nodo(Nodo *nodo){
    nodo->sig=NULL;
    free(nodo);
}


void apilar(int id, Pila* pila ){
    Nodo* nodo=crear_nodo(id);
    nodo->sig=pila->tope;
    pila->tope=nodo;
}
void despilar( Pila* pila ){
    if(pila->tope!=NULL){
        Nodo* eliminar_nodo=pila->tope;
        pila->tope=pila->tope->sig;
        destruir_nodo(eliminar_nodo);
    }
}

int getNextNodo(Pila* pila ){
    if(pila->tope==NULL){
        return 0;
    }
    else{
        return pila->tope->vertice_a_visitar;
    }
}

Pila *newPila(){
    Pila* pila= (Pila*)malloc(sizeof(Pila));
    pila->tope=NULL;
    return pila;

}