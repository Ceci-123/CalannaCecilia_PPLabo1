#include "fecha.h"
#include "servicios.h"
#include "moto.h"
#include "color.h"
#include "tiposdemoto.h"

#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED

typedef struct{
        int id;
        eFecha fecha;
        int idMoto;
        int idServicio;
        int isEmpty;

 }eTrabajo;

 /** \brief Busca en el array de trabajos una posicion libre, con isEmpty en 1
 *
 * \param El array de trabajos
 * \param Un entero, el tamaño del array
 * \return Un entero, el indice de la posicion libre
 *
 */
int buscarTrabajoLibre(eTrabajo listaTrabajos[], int tamanioListaTrabajos);

/** \brief Muestra una lista con los trabajos ingresados
 *
 * \param El array de trabajos
 * \param Un entero, el tamaño del array de trabajos
 * \param El array de servicios
 * \param Un entero, el tamaño del array de servicios
 *
 */
void mostrarTrabajos(eTrabajo listadoDeTrabajos[], int tamanioListadoTrabajos, eServicio listadoDeServicios[], int tamanioListadoServicios);

/** \brief Da de alta un trabajo
 *
 * \param El array de trabajos
 * \param Un entero, el tamaño del array de trabajos
 * \param El puntero a la direccion de memoria donde esta el id de trabajos
 * \param El array de motos
 * \param Un entero, el tamaño del array de motos
 * \param El array de colores
 * \param Un entero, el tamaño del array de colores
 * \param El array de tipos de moto
 * \param Un entero, el tamaño del array de tipos de moto
 * \param El array de servicios
 * \param Un entero, el tamaño del array de servicios
 * \param El array de clientes
 * \param Un entero, el tamaño del array de clientes
 * \return Un entero, 0 si hubo error, 1 si logra dar el alta
 *
 */
int altaTrabajo(eTrabajo listaTrabajos[], int tamanioListaTrabajos, int* nextIdTrabajos, eMoto listadoMotos[],
                 int tamanioListadoMoto, eColor listadoColores[], int tamanioListadoColor, eTipoMoto listadoTipos[],
                  int tamanioListaTipos, eServicio listadoServicios[], int tamanioListaServicios, eCliente listadoClientes[], int tamanioListaClientes);

/** \brief Inicializa la lista de trabajos poniendo el campo de isEmpty en 1
 *
 * \param El array con la lista de trabajos
 * \param El tamaño del array
 *
 */
void inicializarTrabajos(eTrabajo listaTrabajos[], int tamanioListaTrabajos);

/** \brief Harcodea un listado de trabajos
 *
 * \param El array de trabajos
 * \param Un entero, el tamaño del array
 * \param El puntero a la variable donde se guarda el id de trabajos
 *
 */
void harcodearTrabajos(eTrabajo listadoDeTrabajos[], int tamanioListadoTrabajos, int *nextIdTrabajo);

#endif // TRABAJOS_H_INCLUDED
