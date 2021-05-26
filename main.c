#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moto.h"
#include "servicios.h"
#include "trabajos.h"
#include "informes.h"
#include "cliente.h"

#define TAMOTO 20
#define TAMCOL 5
#define TAMTIPO 4
#define TAMSERV 4
#define TAMTRAB 20
#define TAMCLI 20

int main()
{

  // variables
   char salir = 'n';
   int flagAlta = 0;
   int flagTrabajo = 0;
   eMoto nominaDeMotos[TAMOTO];
   eColor nominaDeColores[TAMCOL];
   eTipoMoto nominaDeTipos[TAMTIPO];
   eServicio nominaDeServicios[TAMSERV];
   eTrabajo nominaDeTrabajos[TAMTRAB];
   int nextIdMoto = 1;
   int devolucionDeAlta;
   int devolucionDeBaja;
   int devolucionDeModificar;
   int nextIdTrabajo = 1;
   int numeroInforme;

   // inicializaciones
    inicializarMoto(nominaDeMotos, TAMOTO);
    harcodearColor(nominaDeColores, TAMCOL);
    harcodearTipo(nominaDeTipos, TAMTIPO);
    harcodearServicios(nominaDeServicios, TAMSERV);
    inicializarTrabajos(nominaDeTrabajos, TAMTRAB);
    harcodearTrabajos(nominaDeTrabajos, TAMTRAB, &nextIdTrabajo);
    harcodearMotos(nominaDeMotos, TAMOTO, &nextIdMoto);
    // como hardcodeo cambio las flags manualmente
    cambiarFlagATrue(&flagAlta);
    cambiarFlagATrue(&flagTrabajo);
    // clientes
    eCliente nominaDeClientes[TAMCLI];
    harcodearClientes(nominaDeClientes, TAMCLI);
    harcodearIdDeClientes(nominaDeMotos, TAMOTO);

      do {

	        switch(menu())
	        {
	            case 1:
	            printf("------ALTA DE Moto-----------\n");
	            devolucionDeAlta = altaMoto(nominaDeMotos, TAMOTO, &nextIdMoto);
	            if(devolucionDeAlta == 1)
                {
                    cambiarFlagATrue(&flagAlta);
                    printf("Alta de moto exitosa\n");
                    system("pause");
                }
	            break;
	            case 2:
	            printf("---------MODIFICAR Moto-----------\n");
	            if(!flagAlta)
                {

                    printf("No pueden realizarse modificaciones hasta que no se realizen altas\n");
	                system("pause");
	                break;
                }
                devolucionDeModificar = modificarMoto(nominaDeMotos, TAMOTO, nominaDeColores, TAMCOL, nominaDeTipos, TAMTIPO, nominaDeClientes, TAMCLI);
	            if(devolucionDeModificar == 0)
                {
                    printf("Modificacion realizada exitosamente\n");
                    system("pause");
                }
                else
                {
                    printf("Ocurrio un  error en la modificacion");
                    system("pause");
                }
	            break;
	            case 3:
	            printf("---------BAJA DE Moto-----------\n");
	            if(!flagAlta)
                {
                    printf("No pueden realizarse bajas hasta que no se realizen altas\n");
	                system("pause");
	                break;
                }
                devolucionDeBaja = bajaMoto(nominaDeMotos, TAMOTO, nominaDeColores, TAMCOL, nominaDeTipos, TAMTIPO,nominaDeClientes, TAMCLI);
                if(devolucionDeBaja == 1)
                {
                    printf("Baja realizada exitosamente\n");
                    system("pause");
                }
                else
                {
                    printf("Ocurrio un  error en la baja");
                }
	            break;
	            case 4:
	            printf("----------------LISTAR MOTOS-----------------\n");
	            if(!flagAlta)
                {
                    printf("No pueden realizarse informes hasta que no se realizen altas\n");
	                system("pause");
	                break;
                }
                ordenarMotos(nominaDeMotos, TAMOTO);
                mostrarMotos(nominaDeMotos, TAMOTO, nominaDeColores, TAMCOL, nominaDeTipos, TAMTIPO, nominaDeClientes, TAMCLI);
                system("pause");

	            break;
	            case 5:
	            printf("--------- Tipos de motos--------\n");
                mostrarTipos(nominaDeTipos, TAMTIPO);
	            system("pause");

	            break;
                case 6:
	            printf("---------Listar colores --------\n");

	            mostrarColores(nominaDeColores, TAMCOL);
                system("pause");
                break;
                case 7:
	            printf("---------Listar servicios --------\n");
                mostrarServicios(nominaDeServicios, TAMSERV);
                system("pause");
	            break;
	            case 8:
	            printf("---------Alta de trabajos --------\n");
	            if(!flagAlta)
                {

                    printf("No pueden realizarse altas de trabajos hasta que no se ingresen motos\n");
	                system("pause");
	                break;
                }
                altaTrabajo(nominaDeTrabajos, TAMTRAB, &nextIdTrabajo, nominaDeMotos, TAMOTO, nominaDeColores, TAMCOL, nominaDeTipos, TAMTIPO, nominaDeServicios, TAMSERV, nominaDeClientes, TAMCLI);
                system("pause");
                cambiarFlagATrue(&flagTrabajo);
	            break;
	            case 9:
	            printf("--------------Listar trabajos --------------\n");
	            if(!flagTrabajo)
                {
                    printf("No pueden realizarse informes hasta que no se realizen altas\n");
	                system("pause");
	                break;
                }
                mostrarTrabajos(nominaDeTrabajos, TAMTRAB, nominaDeServicios, TAMSERV);
                system("pause");
	            break;
	            case 10:
	                printf("------ Informes ---------\n");
	                if(!flagTrabajo)
                    {
                    printf("No pueden realizarse informes hasta que no se realizen altas\n");
	                system("pause");
                    }
	                printf(" 1. Mostrar todas las motos de un color seleccionado por el usuario\n");
                    printf(" 2. Mostrar todas las motos de un tipo seleccionado por el usuario\n");
                    printf("3. Mostrar motos de mayor cilindrada\n");
                    printf("4. Ordenar por tipo\n");
                    printf("5. Cantidad de ciclomotores azules\n");
                    printf("6. Color mas popular\n");
                    printf("7. Pedir una moto y mostrar que trabajos le hicieron\n");
                    printf("8. Pedir una moto y mostrar cuanto suman sus trabajos\n");
                    printf("9. Pedir un servicio, mostrar todas las motos que tuvieron ese servicio\n");
                    printf("10. Pedir una fecha y mostrar los trabajos de esa fecha\n");
                    scanf("%d", &numeroInforme);
                    switch(numeroInforme)
                    {
                        case 1:
                        mostrarMotoPorColor(nominaDeMotos, TAMOTO, nominaDeColores, TAMCOL, nominaDeTipos, TAMTIPO, nominaDeClientes, TAMCLI);
                        system("pause");
                    break;
                    case 2:
                        mostrarMotoPorTipo(nominaDeMotos, TAMOTO, nominaDeColores, TAMCOL, nominaDeTipos, TAMTIPO, nominaDeClientes, TAMCLI);
                        system("pause");
                    break;
                    case 3:
                        mostrarMotosMayorCilindrada(nominaDeMotos, TAMOTO, nominaDeColores, TAMCOL, nominaDeTipos, TAMTIPO, nominaDeClientes, TAMCLI);
                        system("pause");
                    break;
                    case 4:
                        ordenarPorTipo(nominaDeMotos, TAMOTO);
                        mostrarMotos(nominaDeMotos, TAMOTO, nominaDeColores, TAMCOL, nominaDeTipos, TAMTIPO, nominaDeClientes, TAMCLI);
                        system("pause");
                    break;
                    case 5:
                        contadorDeColoresTipos(nominaDeMotos, TAMOTO);
                        system("pause");
                    break;
                    case 6:
                        colorMasPopular(nominaDeMotos, TAMOTO);
                        system("pause");
                    break;
                    case 7:
                        serviciosHechosAUnaMoto(nominaDeMotos, TAMOTO, nominaDeColores, TAMCOL, nominaDeTipos, TAMTIPO,
                                                nominaDeTrabajos, TAMTRAB, nominaDeServicios, TAMSERV, nominaDeClientes, TAMCLI);
                        system("pause");
                    break;
                    case 8:
                        costoServiciosHechosAUnaMoto(nominaDeMotos, TAMOTO, nominaDeColores, TAMCOL, nominaDeTipos, TAMTIPO,
                                                nominaDeTrabajos, TAMTRAB, nominaDeServicios, TAMSERV, nominaDeClientes, TAMCLI);
                        system("pause");
                    break;
                    case 9:
                        motosDeUnServicio(nominaDeServicios, TAMSERV, nominaDeTrabajos, TAMTRAB, nominaDeMotos, TAMOTO,
                                          nominaDeColores, TAMCOL, nominaDeTipos, TAMTIPO, nominaDeClientes, TAMCLI);
                        system("pause");
                    break;
                    case 10:
                        trabajosDeUnaFecha(nominaDeTrabajos, TAMTRAB, nominaDeServicios, TAMSERV);
                        system("pause");
                    break;
                    }  // fin swich informes
	                break;

	            case 11:
	            printf("seguro que quiere salir? s / n\n");
	            fflush(stdin);
	            scanf("%c", &salir);
	            break;
                default:
	            printf("Opcion no valida, reingrese opcion\n");
	            system("pause");
	            break;
            }

      }while(salir == 'n'); // fin del do while del menu

    return 0;
}
