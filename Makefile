OBJS = main.o funciones_vertices.o funciones_aristas.o funciones_imprimir.o funciones_pilas.o funciones_ciclos.o
BINARY = main

# all: program

program: $(OBJS)
	gcc -o $(BINARY) $(OBJS) 

main.o: main.c funciones.h
	gcc -c main.c

vertices.o: funciones_vertices.c funciones.h
	gcc -c funciones_vertices.c

aristas.o: funciones_aristas.c funciones.h
	gcc -c funciones_aristas.c

imprimir.o: funciones_imprimir.c funciones.h
	gcc -c funciones_imprimir.c
 
pilas.o: funciones_pilas.c funciones.h
	gcc -c funciones_pilas.c

ciclos.o: funciones_ciclos.c funciones.h
	gcc -c funciones_ciclos.c

clean:
	rm -f $(BINARY) $(OBJS)
