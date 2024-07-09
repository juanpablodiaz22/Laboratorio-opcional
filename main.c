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

//Se crea la funcion principal
int main() {
    // Arreglo de personas
    Persona personas[10] = {
        {"Esteban", 33, 165},
        {"David", 41, 196},
        {"Carlos", 22, 175},
        {"Benjamin", 28, 160},
        {"Alejandro", 14, 140},
        {"Leo", 68, 170},
        {"Valeria", 21, 188},
        {"Rosa", 77, 155},
        {"Tatiana", 28, 161},
        {"Maria", 6, 100}
    };

    //Para obtener el tamano del arreglo
    int size = sizeof(personas) / sizeof(personas[0]);

    // Se ordenan las personas por nombre alfabeticamente y se muestra el resultado
    qsort(personas, size, sizeof(Persona), compare_by_name);
    printf("Se ordenan las personas por nombre alfabeticamente:\n");
    print_personas(personas, size);

    // Se ordenan las personas por edad, de menor a mayor y se muestra el resultado
    qsort(personas, size, sizeof(Persona), compare_by_age);
    printf("\nSe ordenan las personas por edad, de menor a mayor:\n");
    print_personas(personas, size);

    // Se ordenan las personas por altura, de menor a mayor y se muestra el resultado
    qsort(personas, size, sizeof(Persona), compare_by_height);
    printf("\nSe ordenan las personas por altura, de menor a mayor:\n");
    print_personas(personas, size);

    return 0;
}