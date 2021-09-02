# Primero se declararlian las dependencias
# program: numeros.o funciones.o
#	gcc -o numeros.o funciones

all: main

main : main.c funciones.h funciones.c funciones.o
	gcc -o main main.c funciones.o 

funciones.o : funciones.h funciones.c
	gcc -c funciones.c

output: main.c
	gcc main.c -o main
 
clean:
	rm -rf *o main *~

