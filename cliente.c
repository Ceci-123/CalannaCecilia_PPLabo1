#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void harcodearClientes(eCliente listadoClientes[], int tamanioListadoClientes)
{
    eCliente auxiliar;
    int id = 1;
    char sexos[20]= {'f','m','f','m','m','m','f','f','f','m','f','m','f','m','m','m','f','f','f','m'};
    char nombres[20][15] = {"Marcela","Carlos","Jazmin","Bruno","Horacio","German","Johana","Milagros",
                     "Morena","Leandro","Soraya","Daniel","Carina","Juan","Martin","Pablo","Roxana",
                      "Carla","Ximena","Walter"};

    for(int i = 0; i < tamanioListadoClientes; i ++)
    {
        auxiliar.idCliente = id;
        id++;
        strcpy(auxiliar.nombre, nombres[i]);
        auxiliar.isEmpty = 1;
        auxiliar.sexo = sexos[i];
        listadoClientes[i] = auxiliar;
    }

}

void mostrarClientes(eCliente listaClientes[], int tamanioListaClientes)
{
    for(int i= 0; i < tamanioListaClientes; i++)
    {
        printf("%5d %15s %c \n", listaClientes[i].idCliente, listaClientes[i].nombre, listaClientes[i].sexo);
    }
}



void cargarNombreCliente(eCliente listadoClientes[], int tamanioListaClientes, int identificador, char cadena[])
{
    if(listadoClientes != NULL && cadena != NULL && tamanioListaClientes > 0)
    {
        for(int i= 0; i < tamanioListaClientes; i++)
        {
            if(listadoClientes[i].idCliente == identificador)
            {
                strcpy(cadena, listadoClientes[i].nombre);
                break;
            }
        }
    }
}
