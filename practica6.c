/*  
   Nombre del archivo: practica6.c 
   Autor: Lizeth Barrios Retana 
   Fecha de creación: 20 de Octubre de 2023 
   Descripción: El codigo realiza operaciones con arreglos, incluyendo la suma de elementos, copia de arreglos, concatenación, comparación, 
   y encuentra el elemento máximo, con un menú interactivo para seleccionar estas acciones.  
*/
#include <stdio.h>
#include "BRL.h"

int suma_de_areglo(int *arreglo, int largo);
void copiar_arreglo(int *arreglo_destino, int *arreglo_origen, int largo);
void concatenar_arreglo(int *arreglo_destino, int *arreglo1, int largo1, int *arreglo2, int largo_2);
void comparar_arreglo(int *arreglo1, int largo, int *areglo2, int largo_2);
void elemento_maximo(int *arreglo, int largo);


int main()
{
    int numero[] = {10, 8, 9, 4, 5};
    int numeros[] = {6, 7, 8, 9, 10};
    int largo = sizeof(numero) / sizeof(numero[0]);
    int largo_2 = sizeof(numeros) / sizeof(numeros[0]);
    int largo_total = largo + largo_2;
    int numeros2[largo_total];
    int numeros_copia[largo];
    int op, menu;
    int i,j, suma;
    do
    {
        menu = 1;
        op = validarnumeros("\n    Menu\n0. Salir\n1. Suma de elementos en un arreglo\n2. Copia de arreglos\n3. Concatenacion de arreglos\n4. Comparacion de arreglos\n5. Encontrar el elemento maximo\n", 0, 5);
        switch (op)
        {
        case 0:
            system("cls");
            printf("FIN DEL PROGRAMA");
            menu = 0;
            break;
        case 1:
            suma = suma_de_areglo(numero, largo);
            printf("suma del arreglo =%d\n", suma);
            break;
        case 2:
            copiar_arreglo(numeros_copia, numero, largo);
            printf("     origen------destino\n");
            for (i = 0; i < largo; i++)
            {
                printf("%9d %10d\n", numero[i], numeros_copia[i]);
            }
            break;
        case 3:
            concatenar_arreglo(numeros2, numero, largo, numeros, largo_2);
            printf("Concatenacion de arreglos: ");
            for ( j = 0; j < largo_total; j++)
            {
                printf("%d ", numeros2[j]);
            }
            break;
        case 4:
            comparar_arreglo(numero, largo, numeros, largo_2);
            break;
        case 5:
            elemento_maximo(numero, largo);
            break;
        }
    } while (menu == 1);
    return 0;
}

/*
Función: suma_de_areglo
Descripción: Calcula la suma de los elementos en un arreglo.
Parámetros:
  - arreglo: Puntero al arreglo de enteros.
  - largo: Tamaño del arreglo.
Valor de retorno: La suma de los elementos en el arreglo.
*/
int suma_de_areglo(int *arreglo, int largo)
{
    int acu = 0;
    int *ptr = arreglo;
    int i;

    for ( i = 0; i < largo; i++)
    {
        acu += *ptr;
        ptr++;
    }

    return acu;
}

/*
Función: copiar_arreglo
Descripción: Copia los elementos de un arreglo de origen a un arreglo de destino.
Parámetros:
  - arreglo_destino: Puntero al arreglo de destino.
  - arreglo_origen: Puntero al arreglo de origen.
  - largo: Tamaño del arreglo.
*/
void copiar_arreglo(int *arreglo_destino, int *arreglo_origen, int largo)
{
    int *ptr = arreglo_destino;
    int *ptr2 = arreglo_origen;
    int i;

    for ( i = 0; i < largo; i++)
    {
        *ptr = *ptr2;
        ptr++;
        ptr2++;
    }
}

/*
Función: concatenar_arreglo
Descripción: Concatena dos arreglos en un tercer arreglo.
Parámetros:
  - arreglo_destino: Puntero al arreglo de destino.
  - arreglo1: Puntero al primer arreglo.
  - largo1: Tamaño del primer arreglo.
  - arreglo2: Puntero al segundo arreglo.
  - largo_2: Tamaño del segundo arreglo.
*/
void concatenar_arreglo(int *arreglo_destino, int *arreglo1, int largo1, int *arreglo2, int largo_2)
{
    int *ptr = arreglo_destino;
    int *ptr2 = arreglo1;
    int *ptr3 = arreglo2;
    int i;

    for (i = 0; i < largo1; i++)
    {
        *ptr = *ptr2;
        ptr++;
        ptr2++;
    }

    for (i = 0; i < largo_2; i++)
    {
        *ptr = *ptr3;
        ptr++;
        ptr3++;
    }
}

/*
Función: comparar_arreglo
Descripción: Compara dos arreglos para determinar si son iguales.
Parámetros:
  - arreglo1: Puntero al primer arreglo.
  - largo: Tamaño del primer arreglo.
  - arreglo2: Puntero al segundo arreglo.
  - largo_2: Tamaño del segundo arreglo.
*/
void comparar_arreglo(int *arreglo1, int largo, int *arreglo2, int largo_2)
{
    int *ptr = arreglo1;
    int *ptr2 = arreglo2;
    int i;

    if (largo != largo_2)
    {
        printf("NO SON IGUALES");
        return;
    }

    for (i = 0; i < largo; i++)
    {
        if (*ptr != *ptr2)
        {
            printf("NO SON IGUALES");
            return;
        }
        ptr++;
        ptr2++;
    }

    printf("SON IGUALES");
}

/*
Función: elemento_maximo
Descripción: Encuentra el elemento máximo en un arreglo.
Parámetros:
  - arreglo: Puntero al arreglo.
  - largo: Tamaño del arreglo.
*/
void elemento_maximo(int *arreglo, int largo)
{
    int *ptr = arreglo;
    int maximo = *ptr;
    int i;

    for ( i = 1; i < largo; i++)
    {
        if (*ptr > maximo)
        {
            maximo = *ptr;
        }
        ptr++;
    }

    printf("El elemento maximo en el arreglo es: %d\n", maximo);
}
