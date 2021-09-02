#ifndef _FUNCIONES_H
#define _FUNCIONES_H

#include <stdlib.h>
#include <stdio.h>

typedef struct conexion{
    int id_conexion;
    struct conexion *sigConexion;
    
}subnodo;

typedef struct vertice{
    int id_vertice;
    struct subnodo *subLista;
    struct vertice  *sigVertice;
}vertice;

int cant_vertices = 0;

void agregar_vertice(vertice* registro);
void ingresar_sublista(subnodo* registro);
void imprimir_vertices(vertice* registro);
void imprimir_subListas(subnodo* registro);
vertice* buscar_vertice(vertice* registro, int n);

#endif