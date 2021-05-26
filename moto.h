#include "color.h"
#include "fecha.h"
#include "tiposdemoto.h"
#include "validaciones.h"
#include "cliente.h"

#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED


typedef struct{
        int id;
        char marca[20];
        int idTipo;
        int idColor;
        int idCliente;
        int cilindrada;
        int isEmpty;

 }eMoto;

/** \brief Muestra un menu con opciones al usuario
*
* \return Devuelve un entero, la opcion que el usuario elijio
*
*/
int menu();

/** \brief Busca en el array de motos una posicion libre
 *
 * \param El array de motos
 * \param Un entero, el tamaño del array
 * \return Un entero, la posicion libre
 *
 */
int buscarMotoLibre(eMoto listaMotos[], int tamanioListaMotos);

/** \brief Realiza el alta de una moto
 *
 * \param El array de motos
 * \param Un entero, el tamaño del array
 * \param El puntero a la variable de id de motos
 * \return Un entero, 0 si hubo error o 1 si realizo el alta
 *
 */
int altaMoto(eMoto listaMotos[], int tamanioListaMotos, int* nextIdMoto);

/** \brief Realiza una baja logica en el array de motos, escribe 1 en el campo isEmpty
 *
 * \param El array de motos
 * \param Un entero, el tamaño del array de motos
 * \param El array de colores
 * \param Un entero, el tamaño del array de colores
 * \param El array de tipos
 * \param Un entero, el tamaño del array de tipos
 * \param El array de clientes
 * \param Un entero, el tamaño del array de clientes
 * \return Un entero, 0 si hubo error o 1 si realizo la baja
 *
 */
int bajaMoto(eMoto listaMotos[], int tamanioListaMotos, eColor listadoDeColores[], int tamanioListadoColores,
             eTipoMoto listadoDeTipos[], int tamanioListaTipos, eCliente listadoDeClientes[], int tamanioListaClientes);

/** \brief Muestra una lista de motos en pantalla
 *
 * \param El array de motos
 * \param Un entero, el tamaño del array de motos
 * \param El array de colores
 * \param Un entero, el tamaño del array de colores
 * \param El array de tipos
 * \param Un entero, el tamaño del array de tipos
 * \param El array de clientes
 * \param Un entero, el tamaño del array de clientes
 *
 */
void mostrarMotos(eMoto listaMotos[], int tamanioListaMotos, eColor listadoDeColores[],
                   int tamanioListadoColores, eTipoMoto listadoTipos[], int tamanioListadoTipos,
                   eCliente listadoClientes[], int tamanioListaClientes);

/** \brief Muestra los datos de una sola moto
 *
 * \param La moto a mostrar
 * \param El array de colores
 * \param Un entero, el tamaño del array de colores
 * \param El array de tipos
 * \param El tamaño del array de tipos
 * \param El array de clientes
 * \param El tamaño del array de clientes
 *
 */
void mostrarMoto(eMoto unaMoto, eColor listadoDeColores[], int tamanioListadoColores, eTipoMoto listadoTipos[],
                 int tamanioListadoTipos, eCliente listadoClientes[], int tamanioListaClientes);


/** \brief Busca la ubicacion en el array de motos de una moto dada por su id
 *
 * \param El array de motos
 * \param Un entero, el tamaño del array de motos
 * \param Un entero, el numero de id de la moto que se busca
 * \return Un entero, la ubicacion de la moto en el array
 *
 */
int buscarMotoXId(eMoto listaMotos[], int tamanioListaMoto, int idABuscar);

/** \brief Inicializa el array de motos, llenando el campo isEmpty con el valor 1
 *
 * \param El array de motos
 * \param Un entero, el tamaño del array de motos
 *
 */
void inicializarMoto(eMoto listaMotos[], int tamanioListaMotos);

/** \brief Modifica el valor de cilindrada o el color de una moto ya ingresada
 *
 * \param El array de motos
 * \param Un entero, el tamaño del array de motos
 * \param El array de colores
 * \param Un entero, el tamaño del array de colores
 * \param El array de tipos de moto
 * \param Un entero, el tamaño del array de tipos de moto
 * \param El array de clientes
 * \param Un entero, el tamaño del array de clientes
 * \return Un entero, 0 si hubo error o 1 si se modifico exitosamente
 *
 */
int modificarMoto(eMoto listadeMotos[], int tamanioListaMoto, eColor listadoDeColores[], int tamanioListadoColor,
                   eTipoMoto listadoTipos[], int tamanioListadoTipos,eCliente listadoClientes[], int tamanioListaClientes);


/** \brief Ordena el listado de motos
 *
 * \param El array de motos
 * \param Un entero, el tamaño del array de motos
 * \return Un entero, 1 si logro ordenar o 0 si hubo un error
 *
 */
int ordenarMotos(eMoto listadeMotos[], int tamanioListaMotos);

/** \brief Harcodea los numeros de id de clientes
 *
 * \param El array de clientes
 * \param Un entero, el tamaño del array de clientes
 *
 */
void harcodearIdDeClientes(eMoto listadoDeMotos[], int tamanioListadoMotos);

/** \brief Hardcodea un listado de motos
 *
 * \param El array de motos
 * \param Un entero, el tamaño del array de motos
 * \param El puntero a la variable donde esta el id de motos
 *
 */
void harcodearMotos(eMoto listadoDeMotos[], int tamanioListadoMotos, int *nextIdMoto);

#endif // MOTO_H_INCLUDED
