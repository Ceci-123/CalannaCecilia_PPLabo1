#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicios.h"

char serviciosDataware[4][15] = {"Limpieza", "Ajuste", "Balanceo" , "Cadena" };
int preciosDataware[4] = {250,300,17,190};

void mostrarServicios(eServicio listadoDeServicios[], int tamanioListadoServicios)
{
    printf(" Identificador    Servicio    Precio    \n");
    for(int i= 0; i < tamanioListadoServicios; i++)
    {

        printf(" %d         %10s       %.2f  ",listadoDeServicios[i].id , listadoDeServicios[i].descripcion, listadoDeServicios[i].precio  );

         printf("\n");
    }

}

void harcodearServicios(eServicio listadoDeServicios[], int tamanioListadoServicios)
{
    int identificador = 20000;
    if(listadoDeServicios != NULL)
    {
       for(int i= 0; i < tamanioListadoServicios; i++)
       {
           strcpy(listadoDeServicios[i].descripcion, serviciosDataware[i]);
           listadoDeServicios[i].precio = preciosDataware[i];
           listadoDeServicios[i].id = identificador;
           identificador ++;
           listadoDeServicios[i].isEmpty = 0;

       }
    }
}

void cargarNombreServicios(eServicio listadoDeServicios[], int tamanioListadoServicios, int identificador, char descripServ[])
{
        if(listadoDeServicios != NULL && tamanioListadoServicios > 0 )
    {
        for(int i= 0; i < tamanioListadoServicios; i++)
        {
            if(listadoDeServicios[i].id == identificador)
            {
                strcpy(descripServ, listadoDeServicios[i].descripcion);
                break;
            }
        }
    }

}
