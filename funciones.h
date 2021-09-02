#ifndef _FUNCIONES_H
#define _FUNCIONES_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Libro{
    char titulo[50];
} Libro;

typedef struct Nodo{
    Libro libro;
    struct Nodo* sig;
} Nodo;

typedef struct Lista{
    Nodo* cabeza;
    int longitud;
}Lista;

Nodo* crear_nodo(Libro* libro);
void destruir_nodo(Nodo* nodo);
void insertar_principio(Lista* lista, Libro* libro);
void insertar_final(Lista* lista, Libro* libro);
void insertar_despues(int n, Lista* lista, Libro* libro);
Libro* obtener(int n, Lista* lista);
int contar(Lista* lista);
void eliminar_principio(Lista* lista);
void eliminar_ultimo(Lista* lista);
void eliminar_elemento(int n, Lista* lista);

#endif