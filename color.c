#include "color.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char colorDataware[5][15] = {"Azul", "Blanco", "Gris", "Negro", "Rojo"};

void harcodearColor(eColor listadoDeColores[], int tamanioListadoColores)
{
    int identificador = 10000;
    if(listadoDeColores != NULL)
    {
       for(int i= 0; i < tamanioListadoColores; i++)
       {
           strcpy(listadoDeColores[i].nombreColor,colorDataware[i]);

           listadoDeColores[i].id = identificador;
           identificador ++;
           listadoDeColores[i].isEmpty = 0;

       }
    }
}

void cargarNombreColor(eColor listadoDeColores[], int tamanioListadoColores, int identificador, char descripcion[])
{
       if(listadoDeColores != NULL && tamanioListadoColores > 0 )
    {
        for(int i= 0; i < tamanioListadoColores; i++)
        {
            if(listadoDeColores[i].id  == identificador + 9999 )
            {
                strcpy(descripcion, listadoDeColores[i].nombreColor);

                break;
            }
        }
    }
}

void mostrarColores(eColor listadoDeColores[], int tamanioListadoColores)
{
    printf("Identificador    Color de Moto\n");
    for(int i= 0; i < tamanioListadoColores; i++)
    {
        printf(" %d      %15s   ",listadoDeColores[i].id , listadoDeColores[i].nombreColor  );

         printf("\n");
    }

}
