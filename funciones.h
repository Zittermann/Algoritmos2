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
    int grado_vertice;
}Vertice;

typedef struct Lista{
    Vertice* cabeza;
    int cant_vertices;
    int cont_id_vertices;
}Lista;


typedef struct nodo
{
    int vertice_a_visitar;
    struct nodo* sig;
}Nodo;

typedef struct pila
{
    Nodo *tope;
}Pila;


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
void es_eureliano(Lista* lista);
int inicializar_vector(int vec[], int len);
void adjuntar_conexiones(Vertice* vertice, int vec[]);
void tiene_ciclo(Lista* lista);
void dfs(Lista* lista, Pila* pila, int visitados[], int ultimo_visitado, int vertice_a_buscar);

int cargarVerticesPrincipales(Vertice* vertice,int vectoresPrin[100],int verticeInicial);
void limpiarVector (int verticeRecor[100],int i);
int encontrarCiclosAdy(Subnodo* adyacencia,int verticesPrin[100],int verticesRecor[100],int verticeBuscar,int i,int max);
int encontrarCiclos(Vertice *vertice,int verticesPrin[100],int verticesRecor[100],int verticeBuscar,int i,int max);
void tiene_ciclos(Lista* lista);

Nodo * crear_nodo(int id);
void destruir_nodo(Nodo *nodo);
void apilar(int id, Pila* pila );
void despilar( Pila* pila );
int getNextNodo(Pila* pila );
Pila *newPila();

#endif