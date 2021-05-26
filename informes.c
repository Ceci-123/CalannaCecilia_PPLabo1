#include "informes.h"
#include "moto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarMotoPorColor(eMoto listadoMotos[], int tamanioListaMotos, eColor listadoDeColores[], int tamanioListadoColores,
                          eTipoMoto listadoTipos[], int tamanioListadoTipos, eCliente listadoClientes[], int tamanioListaClientes)
{
    int opcion;

    printf("De que color desea el listado? 1.Azul, 2.Blanco, 3.Gris, 4.Negro, 5.Rojo\n");
    scanf("%d", &opcion);
    while(opcion < 1 || opcion > 5)
    {
         printf("De que color desea el listado? 1.Azul, 2.Blanco, 3.Gris, 4.Negro, 5.Rojo\n");
         scanf("%d", &opcion);
    }
    printf("Id de moto     Marca    Color   Cilindrada   Tipo de Moto\n");
    if(listadoMotos != NULL && tamanioListaMotos > 0 )
    {
        for(int i= 0; i < tamanioListaMotos; i++)
        {
            if(listadoMotos[i].idColor == opcion)
            {
               mostrarMoto(listadoMotos[i], listadoDeColores, tamanioListadoColores, listadoTipos, tamanioListadoTipos,
                           listadoClientes, tamanioListaClientes);    //muesrto
            }
        }

    }

}

void mostrarMotoPorTipo(eMoto listadoMotos[], int tamanioListaMotos, eColor listadoDeColores[], int tamanioListadoColores, eTipoMoto listadoTipos[],
                         int tamanioListadoTipos, eCliente listadoClientes[], int tamanioListaClientes)
{
    int opcion;

    printf("De que tipo de moto desea el listado?  1.Chopera, 2.Ciclomotor, 3.Enduro, 4.Scooter \n");
    scanf("%d", &opcion);
    while(opcion < 1 || opcion > 4)
    {
        printf("De que tipo de moto desea el listado?  1.Enduro, 2.Chopera, 3.Scooter, 4.Ciclomotor \n");
        scanf("%d", &opcion);
    }
    printf("Id de moto     Marca    Color  Cilindrada   Tipo de Moto\n");
    if(listadoMotos != NULL && tamanioListaMotos > 0 )
    {
        for(int i= 0; i < tamanioListaMotos; i++)
        {
            if(listadoMotos[i].idTipo == opcion)
            {
               mostrarMoto(listadoMotos[i], listadoDeColores, tamanioListadoColores, listadoTipos, tamanioListadoTipos, listadoClientes, tamanioListaClientes);    //muesrto
            }
        }

    }

}
void mostrarMotosMayorCilindrada(eMoto listadoMotos[], int tamanioListaMotos, eColor listadoDeColores[], int tamanioListadoColores, eTipoMoto listadoTipos[], int tamanioListadoTipos, eCliente listadoClientes[], int tamanioListaClientes)
{
    int mayorCilindrada = 1;

    if(listadoMotos != NULL && listadoDeColores != NULL && listadoTipos != NULL &&
       tamanioListaMotos > 0 && tamanioListadoColores > 0 && tamanioListadoTipos > 0)
    {
        for(int i = 0; i < tamanioListaMotos; i ++)
        {
            //busco cilindrada mas grande
            if(i == 0 || listadoMotos[i].cilindrada > mayorCilindrada)
            {
                mayorCilindrada = listadoMotos[i].cilindrada;
            }
        } // primera vuelta obtengo la mayor

        printf("------------ Motos con mayor cilindrada --------------\n");
        printf("Id de moto     Marca    Color  Cilindrada   Tipo de Moto\n");

        for(int i = 0; i < tamanioListaMotos; i++)
        {
            if(listadoMotos[i].cilindrada == mayorCilindrada)
            {
                // muestro
                mostrarMoto(listadoMotos[i], listadoDeColores, tamanioListadoColores, listadoTipos, tamanioListadoTipos,
                            listadoClientes, tamanioListaClientes);
            }
        } // segunda vuelta por si hay empate
    }
}

void ordenarPorTipo(eMoto listadoDeMotos[], int tamanioListadoMotos)
{
    eMoto auxiliar;

    if(listadoDeMotos != NULL && tamanioListadoMotos > 0)
    {
        //burbujeo
        for(int i= 0; i < tamanioListadoMotos -1; i++)
    {
        for(int j= i+1; j < tamanioListadoMotos; j++)
        {
            if(listadoDeMotos[i].idTipo > listadoDeMotos[j].idTipo)
            {
                //hacer swap
                auxiliar = listadoDeMotos[i];
                listadoDeMotos[i] = listadoDeMotos[j];
                listadoDeMotos[j] = auxiliar;

            }

        }  // segundo for

    }  // primer for
    }
}

void ordenarPorColor(eMoto listadoDeMotos[], int tamanioListadoMotos)
{
    eMoto auxiliar;

    if(listadoDeMotos != NULL && tamanioListadoMotos > 0)
    {
        //burbujeo
        for(int i= 0; i < tamanioListadoMotos -1; i++)
    {
        for(int j= i+1; j < tamanioListadoMotos; j++)
        {
            if(listadoDeMotos[i].idColor > listadoDeMotos[j].idColor)
            {
                //hacer swap
                auxiliar = listadoDeMotos[i];
                listadoDeMotos[i] = listadoDeMotos[j];
                listadoDeMotos[j] = auxiliar;

            }

        }  // segundo for

    }  // primer for
    }
}
void colorMasPopular(eMoto listadoDeMotos[], int tamanioListadoMotos)
{
    int arrayDeContadores[5];
    int mayor= 0;
    int flag = 0;
    int datoIndice= 0;
    // 12345 Gris, Negro, Blanco, Azul, Rojo

    for(int i=0; i <= 4; i++)
    {
        arrayDeContadores[i]= 0;
    }
    for(int i= 0; i < tamanioListadoMotos; i++)
    {
        switch(listadoDeMotos[i].idColor)
        {
        case 1:
            arrayDeContadores[0]++;
            break;
        case 2:
            arrayDeContadores[1]++;
            break;
        case 3:
            arrayDeContadores[2]++;
            break;
        case 4:
            arrayDeContadores[3]++;
            break;
        case 5:
            arrayDeContadores[4]++;
            break;
        } // fin del switch
    }  // fin del for

    for(int i= 0; i <= 5; i++)
    {
        //cual es mayor?
        if(flag == 0 || arrayDeContadores[i] > mayor)
        {
            mayor = arrayDeContadores[i];
            flag = 1;
            datoIndice = i;
        }
    }
    switch(datoIndice)
    {
    case 0:
        printf("Gris");
        break;
    case 1:
        printf("Negro");
        break;
    case 2:
    printf("Blanco");
        break;
    case 3:
    printf("Azul");
        break;
    case 4:
    printf("Rojo");
        break;
    }
    printf(" es el color mas popular entre nuestros clientes.\n");
}


void serviciosHechosAUnaMoto(eMoto listadoMotos[], int tamanioListadoMotos, eColor listadoDeColores[], int tamanioListadoColores,
                              eTipoMoto listadoTipos[], int tamanioListadoTipos, eTrabajo listadoTrabajos[],
                              int tamanioListadoTrabajos, eServicio listadoDeServicios[], int tamanioListadoServicios,
                              eCliente listadoClientes[], int tamanioListaClientes)
{
    int eleccion;
    int servicio;

    mostrarMotos(listadoMotos, tamanioListadoMotos, listadoDeColores, tamanioListadoColores, listadoTipos, tamanioListadoTipos,
                 listadoClientes, tamanioListaClientes);
    printf("Elija id de la moto de la cual desea el listado de trabajos");
    scanf("%d", &eleccion);

    for(int i= 0; i < tamanioListadoTrabajos; i++)
    {
        if(listadoTrabajos[i].idMoto == eleccion)
        {
            //este trabajo va
            servicio = listadoTrabajos[i].idServicio;
            for(int j= 0; j < tamanioListadoServicios; j++)
            {
                if(listadoDeServicios[j].id == servicio)
                {
                    printf("%s ,", listadoDeServicios[j].descripcion);

                }
            }
        }

    }
     printf("fue realizados a esta moto.\n");
}

void costoServiciosHechosAUnaMoto(eMoto listadoMotos[], int tamanioListadoMotos, eColor listadoDeColores[], int tamanioListadoColores,
                              eTipoMoto listadoTipos[], int tamanioListadoTipos, eTrabajo listadoTrabajos[],
                              int tamanioListadoTrabajos, eServicio listadoDeServicios[], int tamanioListadoServicios,
                               eCliente listadoClientes[], int tamanioListaClientes)
{
    int eleccion;
    int servicio;
    float acumulador = 0;

    mostrarMotos(listadoMotos, tamanioListadoMotos, listadoDeColores, tamanioListadoColores, listadoTipos, tamanioListadoTipos, listadoClientes, tamanioListaClientes);
    printf("Elija id de la moto de la cual desea saber el costo de trabajos");
    scanf("%d", &eleccion);

    for(int i= 0; i < tamanioListadoTrabajos; i++)
    {
        if(listadoTrabajos[i].idMoto == eleccion)
        {
            //este trabajo va
            servicio = listadoTrabajos[i].idServicio;
            for(int j= 0; j < tamanioListadoServicios; j++)
            {
                if(listadoDeServicios[j].id == servicio)
                {
                   acumulador = acumulador + listadoDeServicios[j].precio;

                }
            }
        }

    }
     printf("El costo de servicios de esta moto asciende a $ %.2f .\n", acumulador);
}


void motosDeUnServicio(eServicio listadoDeServicios[], int tamanioListadoServicios, eTrabajo listadoDeTrabajos[],
                        int tamanioListadoTrabajos, eMoto listadoDeMotos[], int tamanioListaMotos,
                        eColor listadoDeColores[], int tamanioListadoColores,
                              eTipoMoto listadoTipos[], int tamanioListadoTipos,
                            eCliente listadoClientes[], int tamanioListaClientes)
{
    int eleccion;
    int idMoto;
    int flag = 0;
    eFecha auxiliar;

    mostrarServicios(listadoDeServicios, tamanioListadoServicios);
    printf("Ingrese el id del servicio que quiere el informe");
    scanf("%d", &eleccion);

    printf("-------------Motos que tuvieron este servicio---------------\n");
    printf("id de moto marca cilindrada color tipo de moto\n");
    for(int i= 0; i < tamanioListadoTrabajos; i++)
    {
        if(listadoDeTrabajos[i].idServicio == eleccion)
        {
           idMoto = listadoDeTrabajos[i].idMoto;
           auxiliar = listadoDeTrabajos[i].fecha;
           // esta moto tuvo este servicio
           for(int j= 0; j < tamanioListaMotos; j++)
           {
               if(listadoDeMotos[j].id == idMoto)
               {
                 printf("%d/%d/%d", auxiliar.dia, auxiliar.mes, auxiliar.anio);
                 mostrarMoto(listadoDeMotos[j], listadoDeColores, tamanioListadoColores, listadoTipos, tamanioListadoTipos, listadoClientes, tamanioListaClientes);
                 flag = 1;
               }
           }
        }
    }
    if(flag == 0)
    {
        printf("Ninguna moto solicito este servicio\n");
    }
}
int comparaFechas(eFecha f1, eFecha f2)
{
    int igual = 0;
    if(f1.dia == f2.dia && f1.mes == f2.mes && f1.anio == f2.anio)
    {
        igual = 1;
    }
    return igual;
}


void mostrarUnTrabajo(eTrabajo unTrabajo,eServicio listaDeServicios[], int tamanioListaServicios)
{
    char auxiliarChar[20];

    for(int i= 0; i < tamanioListaServicios; i++)
    {
        if(listaDeServicios[i].id == unTrabajo.idServicio)
        {
           strcpy(auxiliarChar,listaDeServicios[i].descripcion );
        }
    }
    printf("%5d               %5d             %5d %15s\n", unTrabajo.id, unTrabajo.idMoto, unTrabajo.idServicio, auxiliarChar);
}
void trabajosDeUnaFecha(eTrabajo listaDeTrabajos[], int tamanioListaTrabajos, eServicio listaDeServicios[], int tamanioListaServicios)
{
    eFecha auxiliarFecha;
    int resultadoComparacion;
    int flagNoHay = 1;

    printf("Ingrese la fecha de la que desea conocer los trabajos, dd/mm/aaaa\n");
    scanf("%d/%d/%d", &auxiliarFecha.dia, &auxiliarFecha.mes, &auxiliarFecha.anio);
    printf("id de trabajo id de moto        Servicio\n");

    for(int i= 0; i < tamanioListaTrabajos; i++)
    {
        resultadoComparacion = comparaFechas(listaDeTrabajos[i].fecha,auxiliarFecha );
        if(resultadoComparacion == 1)
           {
               //es igual
               mostrarUnTrabajo(listaDeTrabajos[i],listaDeServicios, tamanioListaServicios);
               flagNoHay = 0;

           }

    }
    if(flagNoHay == 1)
    {
        printf("No hay trabajos en esa fecha\n");
    }

}

void contadorDeColoresTipos(eMoto listadoDeMotos[], int tamanioListadoMotos)
{
    int contador = 0;
    // 12345 Gris, Negro, Blanco, Azul, Rojo
    // 1234 "Enduro", "Chopera", "Scooter", "Ciclomotor"
    if(listadoDeMotos != NULL && tamanioListadoMotos > 0)
    {
        for(int i = 0; i < tamanioListadoMotos; i++)
        {
            if(listadoDeMotos[i].idColor == 4 && listadoDeMotos[i].idTipo == 4)
            {
                contador++;
            }
        }
    }

    printf("El total de motos ciclomotores de color azul es %d\n", contador);

}
