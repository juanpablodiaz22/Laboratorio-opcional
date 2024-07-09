#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Primeramente se define una estructura Persona con los requisitos solicitados 
typedef struct Persona{
    char name[50];
    int age;
    double height;
    
}Persona;

//A continuacion, se implementan tres funciones de comparacion para qsort 

// Comparacion para ordenar por nombre
int compare_by_name(const void *a, const void *b) {
    Persona *persona1 = (Persona *)a;
    Persona *persona2 = (Persona *)b;
    return strcmp(persona1->name, persona2->name);
}

// Comparacion para ordenar por edad
int compare_by_age(const void *a, const void *b) {
    Persona *persona1 = (Persona *)a;
    Persona *persona2 = (Persona *)b;
    return (persona1->age - persona2->age);
}

// Comparacion para ordenar por altura
int compare_by_height(const void *a, const void *b) {
    Persona *persona1 = (Persona *)a;
    Persona *persona2 = (Persona *)b;
    return (persona1->height > persona2->height) - (persona1->height < persona2->height);
}

// Se crea una funcion para imprimir el arreglo de personas

// Esta es como la forma predeterminada que se va a seguir para mostrar los resultados
void print_personas(Persona personas[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Nombre : %s, Edad: %d, Altura(cm): %.2f\n", personas[i].name, personas[i].age, personas[i].height);
    }
}