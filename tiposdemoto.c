#include "tiposdemoto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char tipoDataware[4][15] = {"Chopera", "Ciclomotor","Enduro", "Scooter"};

void cargarNombreTipo(eTipoMoto listadoDeTipos[], int tamanioListadoTipos, int identificador, char descripcion[])
{
        if(listadoDeTipos != NULL && tamanioListadoTipos > 0 )
    {
        for(int i= 0; i < tamanioListadoTipos; i++)
        {
            if(listadoDeTipos[i].id == identificador + 999)
            {
                strcpy(descripcion, listadoDeTipos[i].descripcion);
                break;
            }
        }
    }
}

void harcodearTipo(eTipoMoto listadoDeTipos[], int tamanioListadoTipos)
{
    int identificador = 1000;
    if(listadoDeTipos != NULL)
    {
       for(int i= 0; i < tamanioListadoTipos; i++)
       {
           strcpy(listadoDeTipos[i].descripcion,tipoDataware[i]);

           listadoDeTipos[i].id = identificador;
           identificador ++;
           listadoDeTipos[i].isEmpty = 0;

       }
    }
}

void mostrarTipos(eTipoMoto listadoDeTipos[], int tamanioListadoTipos)
{
    printf("Identificador       Tipo de moto\n");
    for(int i= 0; i < tamanioListadoTipos; i++)
    {

        printf(" %d               %15s   ",listadoDeTipos[i].id , listadoDeTipos[i].descripcion  );

         printf("\n");
    }

}
