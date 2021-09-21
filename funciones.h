#ifndef _FUNCIONES_H
#define _FUNCIONES_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Conexion{
    int id_conexion;
    struct Conexion *sigConexion;
    
}Subnodo;

typedef struct Vertice{
    int id_vertice;
    struct Subnodo *subLista;
    struct Vertice  *sigVertice;
}Vertice;

typedef struct Lista{
    Vertice* cabeza;
    int cant_vertices;
    int cont_id_vertices;
}Lista;

void imprimir_vertices(Vertice* vertice);
void imprimir_sublistas(Subnodo* nodo);
Vertice* crear_vertice(Lista* lista);
void agregar_conexion(Lista* lista);
Vertice* obtener_vertice(Lista* lista, int n);
void establecer_conexion(Vertice* vertice, int nodo);
void agregar_vertice(Lista* lista);
void eliminar_primer_vertice(Lista* lista);
void eliminar_vertice(Lista* lista);
void eliminar_conexion(Lista* lista);
void desconectar_vertices(Vertice* vertice, int id_nodo);
void imprimir_menu();
void ejecutar_menu(Lista* lista);
#endif