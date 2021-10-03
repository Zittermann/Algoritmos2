#include "funciones.h"

int main(){

    Lista* lista = (Lista*)malloc(sizeof(lista));
    lista->cant_vertices = 0;
    lista->cont_id_vertices = 1;

    ejecutar_menu(lista);

    return 0;
}
