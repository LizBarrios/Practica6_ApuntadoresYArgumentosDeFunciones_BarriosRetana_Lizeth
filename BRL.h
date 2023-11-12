#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validarnumeros(char mensaje[], int ri, int rf);
int contador(char cadena[]);

int validarnumeros(char mensaje[], int ri, int rf)
{
    char menu[100];
    int num, salida = 0, con, i;
    do
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(menu);
        con = contador(menu);
        for (i = 0; i < con; i++)
        {
            if (menu[i] >= '0' && menu[i] <= '9')
            {
                salida = 1;
                break;
            }
            else
            {
                salida = 0;
                break;
            }
        }
        num = atoi(menu);
        if (num < ri || num > rf)
        {
            printf("INGRESE EL NUMERO OTRA VEZ PORFAVOR\n");
        }
    } while (num < ri || num > rf || salida == 0);
    return num;
}
int contador(char cadena[])
{
    int i;
    i = 0;
    while (cadena[i] != 0)
    {
        i++;
    }
    return i;
}