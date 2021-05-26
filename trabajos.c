#include "trabajos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

eFecha fechasDataware[] = { {1,1,2021}, {1,1,2021}, {1,1,2021}, {1,1,2021},
                               {1,1,2021}, {1,1,2021}, {2,1,2021}, {2,1,2021},
                               {2,1,2021}, {2,1,2021}, {2,1,2021}, {2,1,2021},
                               {3,1,2021}, {3,1,2021}, {3,1,2021}, {3,1,2021},
                               {3,1,2021}, {3,1,2021},  {4,1,2021}, {4,1,2021},
                               {4,1,2021}, {4,1,2021} };   ;
int idMotosDataware[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
int idServiciosDataware[] = {20000, 20001, 20000, 20002, 20000, 20000, 20002, 20000, 20002, 20000,
                             20003, 20002, 20001, 20000, 20003, 20001, 20003, 20002, 20000, 20003};


void mostrarTrabajos(eTrabajo listadoDeTrabajos[], int tamanioListadoTrabajos, eServicio listadoDeServicios[], int tamanioListadoServicios)
{
    char descripcionServicio[20];

    printf("-------------Listado de trabajos ------------------\n");
    printf("Id      Fecha    Id de Moto   Id de servicio        Nombre       \n");
    for(int i= 0; i < tamanioListadoTrabajos; i++)
    {
        if(listadoDeTrabajos[i].isEmpty == 0)
        {
           cargarNombreServicios(listadoDeServicios, tamanioListadoServicios,listadoDeTrabajos[i].idServicio, descripcionServicio);

           printf(" %5d %d/%d/%d   %5d             %5d  %15s  ",listadoDeTrabajos[i].id , listadoDeTrabajos[i].fecha.dia, listadoDeTrabajos[i].fecha.mes,
                                  listadoDeTrabajos[i].fecha.anio, listadoDeTrabajos[i].idMoto, listadoDeTrabajos[i].idServicio,
                                  descripcionServicio);

           printf("\n");
        }
    }

}

int buscarTrabajoLibre(eTrabajo listaTrabajos[], int tamanioListaTrabajos)
{
    int libre = -1;

    if(listaTrabajos != NULL && tamanioListaTrabajos > 0)
    {
        for(int i= 0; i < tamanioListaTrabajos; i ++)
        {
            if(listaTrabajos[i].isEmpty == 1)
            {
                libre = i;
                break;
            }
        }
    }
    return libre;
}

int altaTrabajo(eTrabajo listaTrabajos[], int tamanioListaTrabajos, int* nextIdTrabajos, eMoto listadoMotos[], int tamanioListadoMoto,
                 eColor listadoColores[], int tamanioListadoColor, eTipoMoto listadoTipos[], int tamanioListaTipos,
                  eServicio listadoServicios[], int tamanioListaServicios, eCliente listadoClientes[], int tamanioListaClientes)
{
    int todoOk = 0;
    eTrabajo auxiliar;
    int respuestaLibre;
    int respuestaDeFecha;

    if(listaTrabajos != NULL && tamanioListaTrabajos > 0 && nextIdTrabajos > 0)
    {
        respuestaLibre = buscarTrabajoLibre(listaTrabajos, tamanioListaTrabajos);
        if(respuestaLibre == -1)
        {
           // no hay lugar
           printf("No tiene posiciones disponibles en el array\n");
        }
        mostrarMotos(listadoMotos, tamanioListadoMoto, listadoColores, tamanioListadoColor, listadoTipos, tamanioListaTipos, listadoClientes, tamanioListaClientes);
        printf("Ingrese id de la moto\n");
        scanf("%d", &auxiliar.idMoto);

        mostrarServicios(listadoServicios, tamanioListaServicios);
        printf("Ingrese el id del servicio\n");
        scanf("%d", &auxiliar.idServicio);
        while(auxiliar.idServicio < 20000 || auxiliar.idServicio > 20003)
        {
            printf("Error, reingrese el id del servicio\n");
            scanf("%d", &auxiliar.idServicio);
        }

        printf("Ingrese fecha dd/mm/aaaa \n");
        scanf("%d/%d/%d", &auxiliar.fecha.dia, &auxiliar.fecha.mes, &auxiliar.fecha.anio);
        respuestaDeFecha = validarFecha(auxiliar.fecha.dia, auxiliar.fecha.mes, auxiliar.fecha.anio);
        while(respuestaDeFecha == 0)
        {
            printf("Error, reingrese fecha dd/mm/aaaa \n");
            scanf("%d/%d/%d", &auxiliar.fecha.dia, &auxiliar.fecha.mes, &auxiliar.fecha.anio);
            respuestaDeFecha = validarFecha(auxiliar.fecha.dia, auxiliar.fecha.mes, auxiliar.fecha.anio);
        }
        auxiliar.isEmpty = 0;
        auxiliar.id = *nextIdTrabajos;

        (*nextIdTrabajos) ++;
        listaTrabajos[respuestaLibre] = auxiliar;
        todoOk = 1;
    }
    return todoOk;
}


void inicializarTrabajos(eTrabajo listaTrabajos[], int tamanioListaTrabajos){

    if(listaTrabajos != NULL && tamanioListaTrabajos > 0)
    {
        for(int i = 0; i < tamanioListaTrabajos; i++)
        {
        listaTrabajos[i].isEmpty = 1;
        }

    }
}


void harcodearTrabajos(eTrabajo listadoDeTrabajos[], int tamanioListadoTrabajos, int *nextIdTrabajo)
{

    if(listadoDeTrabajos != NULL && tamanioListadoTrabajos > 0 && nextIdTrabajo != NULL)
    {
       for(int i= 0; i < tamanioListadoTrabajos; i++)
       {

           listadoDeTrabajos[i].fecha = fechasDataware[i];
           listadoDeTrabajos[i].idMoto = idMotosDataware[i];
           listadoDeTrabajos[i].idServicio = idServiciosDataware[i];
           listadoDeTrabajos[i].id = *nextIdTrabajo;
           (*nextIdTrabajo) ++;
           listadoDeTrabajos[i].isEmpty = 0;

       }
    }
}

