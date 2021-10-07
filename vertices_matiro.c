#include "funciones.h"


Vertice* crear_vertice(Lista* lista){

    Vertice* vertice = (Vertice*)malloc(sizeof(Vertice));
    vertice->id_vertice = lista->cont_id_vertices;
    vertice->sigVertice = NULL;
    vertice->subLista = NULL;
    vertice->grado_vertice = 0;

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


void es_eureliano(Lista* lista){

    int vertices_grado_impar = 0;
    Vertice* puntero = lista->cabeza;

    while (puntero != NULL){
        
        if(puntero->grado_vertice % 2 != 0){
            vertices_grado_impar++;            
        }

        puntero = puntero->sigVertice;

    }

    if(lista->cabeza == NULL){
        printf("El grafo no tiene vertices...");
    } else if(vertices_grado_impar == 2){
        printf("El grafo tiene un ciclo eureliano.");
    } else if(vertices_grado_impar == 0){
        printf("El grafo tiene un camino eureliano.");
    } else {
        printf("El grafo no es eureliano.");
    }
    
}


//////////////////////////////////////////////////////////////////////////////////////////////
/*
void inicializar_vector_adyacencias(int vec[], int len,int inicio){

    for(int i = 0; i < len; i++){
        if(inicio==i+1){
        vec[i] = 1;
        }
        else{
            vec[i] = 0;
        }
    }

}


int verificarVisitados(int id, int vertices_visitados[],int cant_vertices){
    for(int i=0;i<cant_vertices;i++){
        if(id==i && 1==vertices_visitados[i]){
            return 0;
        }
    }
    return 1;
}


void cargarAdyacencias(Pila *pila,Subnodo *adyacencias,int vertices_visitados[],int cant_vertices){
    
    Subnodo* puntero = adyacencias;

    while (puntero!=NULL)
    {   
        int confirmacion=verificarVisitados(puntero->id_conexion,vertices_visitados,cant_vertices);

        if(confirmacion==1){
            apilar(puntero->id_conexion,pila);
        }

        puntero = puntero->sigConexion;

    }
    
}


void tiene_ciclo(Lista* lista){

    Vertice* puntero = lista->cabeza;
    int inicio;
    printf("Ingrese el vertice inicial: ");
    scanf("%d", &inicio);
    printf("\n OBTENEMOS EL VERTICE INICIAL\n");
    Vertice* vertice = obtener_vertice(lista, inicio);
    int cant_vertices=lista->cant_vertices;
    int visitados[cant_vertices];
    printf("\n INICIALIZAMOS EL VECTOR\n");
    inicializar_vector_adyacencias(visitados,cant_vertices,vertice->id_vertice);
    printf("\n INICIALIZAMOS LA PILA\n");
    Pila* pila = newPila(); //Inicializo la pila
    cargarAdyacencias(pila,puntero->subLista,visitados,cant_vertices);

    int nodo_a_visitar = getNextNodo(pila);
    despilar(pila);
    dfs(lista, pila, visitados, vertice->id_vertice, nodo_a_visitar);


}


void dfs(Lista* lista, Pila* pila, int visitados[], int ultimo_visitado, int vertice_a_buscar){

    

}
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cargarVerticesPrincipales(Vertice *vertice,int vectoresPrin[100],int verticeInicial){
    int i=0;
    while(vertice->id_vertice!=verticeInicial){
        vertice=vertice->sigVertice;
    }
    
    while(vertice->subLista->sigConexion!=NULL){
        if(vertice->subLista->id_conexion==verticeInicial){
            vertice->subLista=vertice->subLista->sigConexion;
        }
        else{
        vectoresPrin[i]=vertice->subLista->id_conexion;
        i++;
        vertice->subLista=vertice->subLista->sigConexion;
        }
    }

    if(vertice->subLista->id_conexion!=verticeInicial){
            vectoresPrin[i]=vertice->subLista->id_conexion;
    }

    return i;
}


void limpiarVector (int verticeRecor[100],int i){
    int j;
    for (j=0;j<i+1;j++){
        verticeRecor[j]=-1;
    }
}


int encontrarCiclosAdy(Subnodo *adyacencia,int verticesPrin[100],int verticesRecor[100],int verticeBuscar,int i,int max){
    int j,confirmacion=1;
    for(j=0;j<i;j++){

        /* Comparo mi lista adyacencias con los recorridos si puedo caminar */
        if(verticesRecor[j]==adyacencia->id_conexion && adyacencia->sigConexion!=NULL){
            
            adyacencia=adyacencia->sigConexion;

        /* Si no hay mas para caminar comparo nomas */
        } else if(verticesRecor[j]==adyacencia->id_conexion) {

            confirmacion==0;

        }

    }

    
    if(confirmacion==1){

        for(j=0;j<=max;j++){

            if(verticesPrin[j]==adyacencia->id_conexion){
               
                return -1;
            
            }

        }

        return adyacencia->id_conexion;
        
    } else {
        return 0;
    }

}


int encontrarCiclos(Vertice *vertice,int verticesPrin[100],int verticesRecor[100],int verticeBuscar,int i,int max){
    int encontrado,confirmacion=1;
    verticesRecor[i]=verticeBuscar;
    while (vertice->sigVertice!=NULL && vertice->id_vertice!=verticeBuscar){
        vertice=vertice->sigVertice;
    }
    if(vertice->id_vertice==verticeBuscar){

        encontrado=encontrarCiclosAdy(vertice->subLista,verticesPrin,verticesRecor,verticeBuscar,i,max);
        if(encontrado==0){
            return 0;
        } else if(encontrado==-1){
            return 1;
        } else {
            encontrarCiclos(vertice,verticesPrin,verticesRecor,encontrado,i=i+1,max);
        }
    }
    else{
        return 0;
    }
}

/*
int inicializar_vector(int vec[], int len){

    for(int i = 0; i < len; i++){
        vec[i] = 0;
    }

}

void adjuntar_adyacentes(Vertice* vertice, int vec[]){

    Subnodo* puntero = vertice->subLista;
    int cont = 0;

    while(puntero != NULL){
        
        vec[cont] = puntero->id_conexion;
        cont++;
        puntero = puntero->sigConexion;

    }

}


void tiene_ciclo(Lista* lista){

    Vertice* puntero = lista->cabeza;
    int inicio;
    int hay_ciclo = 0;

    printf("Ingrese el vertice inicial: ");
    scanf("%d", &inicio);

    Vertice* vertice = obtener_vertice(lista, inicio);

    int visitados[lista->cant_vertices];
    inicializar_vector(visitados, lista->cant_vertices);
    visitados[inicio-1] = 1;
    
    int inicio_adyascentes[vertice->grado_vertice];
    adjuntar_adyacentes(vertice, inicio_adyascentes);  // Llenamos el array con las adyacencias del inicio


    int primer_paso = 1;
    for(int i = 0; i < vertice->grado_vertice; i++){

        
        // busqueda_ciclo(inicio_adyascentes[i], visitados, inicio_adyascentes, lista);

    }

    dfs(lista, vertice, visitados);

}


void busqueda_ciclo(int v_adyascente, int visitados[], int inicio_adyascentes[], Lista* lista, int primer_paso){

    Vertice* puntero = lista->cabeza;
    

}

/*
adyascente_inicio(Vertice vertice, int visitados[]){

    int es_adyascente;

    for(int i = 0, )

}


void dfs(Lista* cabeza, Vertice* vertice, int visitados[]){

    int cant_adyacentes = vertice->grado_vertice;

    /* Creamos array con las conexiones adyacentes 
    int vertices_adyacentes[cant_adyacentes];
    inicializar_vector(vertices_adyacentes, cant_adyacentes);
    adjuntar_adyacentes(vertice, vertices_adyacentes);


    visitados[vertice->id_vertice-1] = 1;
     
}
*/