#include <stdio.h>
#include <string.h>
#include "funciones.h"


void leerCadena(char cadena[], int n){
    fgets(cadena,n,stdin);
    int len = strlen(cadena) - 1;
    cadena[len] = '\0';
}


float validarFlotanteRango(float min, float max){
    int val = 0;
    float aux = 0;
    do{
        val = scanf("%f",&aux);
        while((getchar())!='\n');
        if (aux < min || aux > max || val != 1)
        {
            printf("Error: Valor ingresado incorrecto\n");
        }
    }while(aux < min || aux > max || val != 1);
    return aux;
}

void notasAltasBajas(float mat1[5], float mat2[5], float mat3[5], int cont,
                     float maxminC[3][2])
{
    float min = 10;
    float max = 0;
    for (int i = 0; i < cont; i++)
    {
        if (mat1[i] <= min)
        {
            min = mat1[i];
        }
        if (mat1[i] > max)
        {
            max = mat1[i];
        }
    }
    maxminC[0][0] = min;
    maxminC[0][1] = max;

    min = 10;
    max = 0;
    for (int i = 0; i < cont; i++)
    {
        if (mat2[i] <= min)
        {
            min = mat2[i];
        }
        if (mat2[i] > max)
        {
            max = mat2[i];
        }
    }
    maxminC[1][0] = min;
    maxminC[1][1] = max;

    min = 10;
    max = 0;
    for (int i = 0; i < cont; i++)
    {
        if (mat3[i] <= min)
        {
            min = mat3[i];
        }
        if (mat3[i] > max)
        {
            max = mat3[i];
        }
    }
    maxminC[2][0] = min;
    maxminC[2][1] = max;
}