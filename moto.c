#include "moto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cilindradaDataware[] = {50, 125, 500, 600, 750,50, 125, 500, 600, 750,50, 125, 500, 600, 750,
                            50, 125, 500, 600, 750};

char marcasDataware[20][20] = {"Yamaha", "Ducati", "Honda", "Gilera", "BMW", "Honda", "Kawasaki",
                               "Yamaha", "Ducati", "BMW", "Ducati", "Gilera", "Kawasaki",
                               "Ducati", "Honda", "Gilera", "BMW", "Ducati", "Gilera", "Kawasaki"};

int idColorDataware[] = {1,5,3,2,2,1,5,2,4,3,5,1,4,3,2,4,4,4,2,3};

int tipoCargaDataware[] = {1,4,2,2,3,4,3,2,1,4,3,1,2,2,3,1,4,4,3,2};



int menu(){
    int opcion;
    char ingreso[2];

    system("cls");
    printf("        *****************************\n");
    printf("        *****************************\n");
    printf("        *******    MOTOS      ******\n");
    printf("        *****************************\n");
    printf("        *****************************\n");
    printf(" 1. Alta de Moto  \n");
    printf(" 2. Modificar Moto  \n");
    printf(" 3. Baja de Moto  \n");
    printf(" 4. Listar Motos   \n");
    printf(" 5. Listar Tipos  \n");
    printf(" 6. Listar colores   \n");
    printf(" 7. Listar servicios                \n");
    printf(" 8. Alta de trabajos                 \n");
    printf(" 9. Listar trabajos                  \n");
    printf(" 10. Informes                 \n");
    printf(" 11. Ingrese para salir del menu \n");

    fflush(stdin);
    gets(ingreso);

    opcion = atoi(ingreso);

    return opcion;

}

void inicializarMoto(eMoto listaMotos[], int tamanioListaMotos){

    if(listaMotos != NULL && tamanioListaMotos > 0)
    {
        for(int i = 0; i < tamanioListaMotos; i++)
        {
        listaMotos[i].isEmpty = 1;
        }

    }
}

int altaMoto(eMoto listaMotos[], int tamanioListaMotos, int* nextIdMoto)
{
    int todoOk = 0;
    eMoto auxiliar;
    int respuestaLibre;
    int devolucion;

    if(listaMotos != NULL && tamanioListaMotos > 0 && nextIdMoto > 0)
    {
        respuestaLibre = buscarMotoLibre(listaMotos, tamanioListaMotos);
        if(respuestaLibre == -1)
        {
           // no hay lugar
           printf("No tiene posiciones disponibles en el array\n");
        }
        printf("Ingrese marca de la moto\n");
        fflush(stdin);
        gets(auxiliar.marca);
        printf("Ingrese el tipo de moto 1. Chopera , 2.Ciclomotor, 3.Enduro, 4.Scooter\n");
        scanf("%d", &auxiliar.idTipo);
        while(auxiliar.idTipo < 0 || auxiliar.idTipo > 4)
        {
            printf("Error reIngrese el tipo de moto 1. Chopera , 2.Ciclomotor, 3.Enduro, 4.Scooter\n");
            scanf("%d", &auxiliar.idTipo);
        }
        printf("Ingrese la cilindrada de la moto 50, 125, 500, 600, 750\n");
        scanf("%d", &auxiliar.cilindrada);
        devolucion = validarCilindrada(auxiliar.cilindrada);
        while(devolucion == 0)
        {
            printf("Error, reIngrese la cilindrada de la moto 50, 125, 500, 600, 750\n");
            scanf("%d", &auxiliar.cilindrada);
            devolucion = validarCilindrada(auxiliar.cilindrada);
        }
        printf("Ingrese el id del color 1.Azul, 2.Blanco, 3.Gris, 4.Negro, 5.Rojo \n");
        scanf("%d", &auxiliar.idColor);
        while(auxiliar.idColor < 0 || auxiliar.idColor > 5)
        {
            printf("Error, reIngrese el id del color 1.Azul, 2.Blanco, 3.Gris, 4.Negro, 5.Rojo \n");
            scanf("%d", &auxiliar.idColor);
        }
        auxiliar.isEmpty = 0;
        auxiliar.id = *nextIdMoto;
        (*nextIdMoto) ++;
        listaMotos[respuestaLibre] = auxiliar;
       todoOk = 1;
    }
    return todoOk;
}

int buscarMotoLibre(eMoto listaMotos[], int tamanioListaMotos)
{
    int libre = -1;

    if(listaMotos != NULL && tamanioListaMotos > 0)
    {
        for(int i= 0; i < tamanioListaMotos; i ++)
        {
            if(listaMotos[i].isEmpty == 1)
            {
                libre = i;
                break;
            }
        }
    }
    return libre;
}

int bajaMoto(eMoto listaMotos[], int tamanioListaMotos, eColor listadoDeColores[], int tamanioListadoColores, eTipoMoto listadoDeTipos[],
             int tamanioListaTipos, eCliente listadoDeClientes[], int tamanioListaClientes)
{
    int todoOk= -1;
    int idBaja;
    int indiceBaja;

    if(listaMotos != NULL && tamanioListaMotos > 0)
    {
        mostrarMotos(listaMotos, tamanioListaMotos, listadoDeColores, tamanioListadoColores, listadoDeTipos, tamanioListaTipos, listadoDeClientes, tamanioListaClientes);
        printf("Ingrese id de la moto para dar la baja");
        scanf("%d", &idBaja);
        indiceBaja = buscarMotoXId(listaMotos, tamanioListaMotos, idBaja);
        for(int i= 0; i < tamanioListaMotos; i++)
        {
            listaMotos[indiceBaja].isEmpty = 1;
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}
int buscarMotoXId(eMoto listaMotos[], int tamanioListaMoto, int idABuscar)
{
    int indice;

    if(listaMotos != NULL && tamanioListaMoto > 0)
    {
        for(int i= 0; i < tamanioListaMoto; i ++)
        {
            if(listaMotos[i].id == idABuscar )
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

void mostrarMotos(eMoto listaMotos[], int tamanioListaMotos, eColor listadoDeColores[], int tamanioListadoColores,
                  eTipoMoto listadoTipos[], int tamanioListadoTipos, eCliente listadoClientes[], int tamanioListaClientes)
{

    int flag = 1;

    printf("--------------- MOTOS INGRESADAS ------------------\n");
    printf("Id moto     Marca         Cilindrada      Color          Tipo de Moto   Nombre del cliente\n");
    for(int i=0; i< tamanioListaMotos; i++)
    {
        if(!listaMotos[i].isEmpty)
        {
           mostrarMoto(listaMotos[i], listadoDeColores, tamanioListadoColores, listadoTipos, tamanioListadoTipos, listadoClientes, tamanioListaClientes);
           flag = 0;
        }

    }
    if(flag)
        {
            printf("No hay motos ingresadas\n");
        }


}

void mostrarMoto(eMoto unaMoto, eColor listadoDeColores[], int tamanioListadoColores, eTipoMoto listadoTipos[],
                  int tamanioListadoTipos, eCliente listadoClientes[], int tamanioListaClientes)
{
    char descripcion[20];
    char descripTipo[20];
    char nombreCliente[20];

    cargarNombreColor(listadoDeColores, tamanioListadoColores, unaMoto.idColor, descripcion );
    cargarNombreTipo(listadoTipos, tamanioListadoTipos, unaMoto.idTipo, descripTipo);
    cargarNombreCliente(listadoClientes, tamanioListaClientes, unaMoto.idCliente, nombreCliente);

    printf(" %5d %15s      %5d  %15s  %15s  %15s  ", unaMoto.id , unaMoto.marca, unaMoto.cilindrada,
                                    descripcion, descripTipo, nombreCliente);

    printf("\n");
}


int modificarMoto(eMoto listadeMotos[], int tamanioListaMoto, eColor listadoDeColores[], int tamanioListadoColor,
                  eTipoMoto listadoTipos[], int tamanioListadoTipos, eCliente listadoClientes[], int tamanioListaClientes)
{
 int todoOk = -1;
 int indice;
 int id;
 int opcion;
 int auxiliarInt = 0;
 int devolucion;

    if(listadeMotos != NULL && tamanioListaMoto > 0)
    {
        mostrarMotos(listadeMotos, tamanioListaMoto, listadoDeColores, tamanioListadoColor, listadoTipos, tamanioListadoTipos,
                     listadoClientes, tamanioListaClientes);
        printf("Ingrese id de la moto a modificar\n");
        scanf("%d", &id);
        indice = buscarMotoXId(listadeMotos, tamanioListaMoto, id);
        if(indice != -1)
        {
               // encontre el que quiero modificar
                printf("Si desea modificar color ingrese 1\n");
                printf("Si desea modificar cilindrada ingrese 2\n");

                scanf("%d", &opcion);

                switch(opcion)
                {
                case 1:
                    printf("Ingrese el id del color 1.Azul, 2.Blanco, 3.Gris, 4.Negro, 5.Rojo \n");
                    scanf("%d", &auxiliarInt);
                    while(auxiliarInt < 0 || auxiliarInt > 5)
                      {
                        printf("Error, reIngrese el id del color 1.Azul, 2.Blanco, 3.Gris, 4.Negro, 5.Rojo \n");
                        scanf("%d", &auxiliarInt);
                      }
                    listadeMotos[indice].idColor = auxiliarInt;
                    todoOk = 0;
                    break;
                case 2:
                    printf("Ingrese cilindrada de la moto 50, 125, 500, 600, 750: ");
                    scanf("%d", &auxiliarInt);
                    devolucion = validarCilindrada(auxiliarInt);
                       while(devolucion == 0)
                     {
                   printf("Error, reIngrese la cilindrada de la moto 50, 125, 500, 600, 750\n");
                  scanf("%d", &auxiliarInt);
                 devolucion = validarCilindrada(auxiliarInt);
                       }
                    listadeMotos[indice].cilindrada = auxiliarInt;

                    todoOk = 0;
                    break;
                    default:
                    printf("opcion no valida");
                    system("pause");
                    break;
                }

        }
     }

    return todoOk;
}

int ordenarMotos(eMoto listadeMotos[], int tamanioListaMotos)
{
    int todoOk = 0;

    eMoto auxiliarMoto;

    for(int i= 0; i < tamanioListaMotos -1; i++)
    {
        for(int j= i+1; j < tamanioListaMotos; j++)
        {
            if(listadeMotos[i].idTipo < listadeMotos[j].idTipo || (listadeMotos[i].idTipo == listadeMotos[j].idTipo &&  listadeMotos[i].id > listadeMotos[j].id  ))
            {
                //hacer swap
                auxiliarMoto = listadeMotos[i];
                listadeMotos[i] = listadeMotos[j];
                listadeMotos[j] = auxiliarMoto;
                 todoOk = 1;
            }

        }  // segundo for

    }  // primer for
    return todoOk;
}

void harcodearIdDeClientes(eMoto listadoDeMotos[], int tamanioListadoMotos)
{
    int numero = 1;

    if(listadoDeMotos != NULL && tamanioListadoMotos > 0)
    {
        for(int i= 0; i < tamanioListadoMotos; i++)
        {
            listadoDeMotos[i].idCliente = numero;
            numero ++;
        }
    }
}

void harcodearMotos(eMoto listadoDeMotos[], int tamanioListadoMotos, int *nextIdMoto)
{

    if(listadoDeMotos != NULL && nextIdMoto != NULL && tamanioListadoMotos > 0)
    {
       for(int i= 0; i < tamanioListadoMotos; i++)
       {
           strcpy(listadoDeMotos[i].marca,marcasDataware[i]);
           listadoDeMotos[i].cilindrada = cilindradaDataware[i];
           listadoDeMotos[i].id = *nextIdMoto;
           (*nextIdMoto) ++;
           listadoDeMotos[i].isEmpty = 0;
           listadoDeMotos[i].idColor = idColorDataware[i];
           listadoDeMotos[i].idTipo = tipoCargaDataware[i];
       }
    }
}

