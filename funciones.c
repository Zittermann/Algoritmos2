#include "funciones.h"

void agregar_vertice(vertice* registro){

    int nuevo_vertice = 0;
    printf("Si quiere agregar un nuevo vertice ingrese: [1] de lo contrario: [0]\n");
    scanf("%d\n", nuevo_vertice);

    if(nuevo_vertice == 1){
        cant_vertices++; //Aumenta el contador para agregar el id automaticamente
        registro->id_vertice = cant_vertices;

        registro->subLista = (subnodo*)malloc(sizeof(subnodo));
        ingresar_sublista(registro->subLista);

        registro->sigVertice = (vertice*)malloc(sizeof(vertice));
        agregar_vertice(registro->sigVertice);
    } else registro->sigVertice = NULL;

}

void ingresar_sublista(subnodo* registro){

    int nueva_conexion = 0;
    printf("Si quiere agregar una nueva conexion al vertice creado ingrese: [1] de lo contrario: [0]\n");
    scanf("%d\n", nueva_conexion);
    
    if(nueva_conexion == 1){

        int vertice_conectar;
        printf("Ingrese el vertice con el que se tiene una conexion: ");
        scanf("%d", &vertice_conectar);

        registro->id_conexion = vertice_conectar;
        registro->sigConexion = (subnodo*)malloc(sizeof(subnodo));
        ingresar_sublista(registro->sigConexion);

    } else registro->sigConexion = NULL;
    
}

void imprimir_vertices(vertice* registro){
    if(registro->sigVertice != NULL){
        printf("--------------------------------------------------------------\n");
        printf("Vertice: [%d]\t", registro->id_vertice);
        imprimir_subListas(registro->subLista); // Mostramos las conexiones del vertice


        imprimir_vertices(registro->sigVertice); // Mostramos el siguiente vertice
    }
}

void imprimir_subListas(subnodo* registro){
    if(registro->sigConexion != NULL){
      
        printf("\t ->[%d]", registro->id_conexion);
        imprimir_subListas(registro->sigConexion);
    
    }
}

vertice* buscar_vertice(vertice* registro, int n){

    if(registro->sigVertice == NULL){
    
        printf("No existe dicho vertice\n");
        return NULL;

    } else {

        if(registro->id_vertice == n) return registro;
        else return buscar_vertice(registro->sigVertice, n);

    }
}
