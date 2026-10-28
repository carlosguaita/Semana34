#include <stdio.h>
#include "funciones.h"
int main (int argc, char *argv[]) {
    char nombre[50];
    int edad;
    printf("Ingrese el nombre de la persona: ");
    leerCadena(nombre,50);
    printf("Ingrese la edad:");
    edad = validarFlotanteRango(1,80);
    printf("%s tiene la edad de %d\n",nombre,edad);


    return 0;
}