OBJS = main.o vertices.o aristas.o imprimir.o
BINARY = main

all: program

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
 
clean:
	rm -f $(BINARY) $(OBJS)

