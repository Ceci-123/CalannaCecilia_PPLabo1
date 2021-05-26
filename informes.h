#include "moto.h"
#include "cliente.h"
#include "trabajos.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

/** \brief Pregunta al usuario un color de moto. Muestra el listado de motos de ese color.
 *
 * \param El array de motos.
 * \param Un entero, el tamaño del array de motos.
 * \param El array de colores.
 * \param Un entero, el tamaño del array de colores.
 * \param El array de tipos de moto.
 * \param Un entero, el tamaño del array de tipos de moto
 * \param El array de clientes
 * \param Un entero, el tamaño del array de clientes
 *
 */
void mostrarMotoPorColor(eMoto listadoMotos[], int tamanioListaMotos, eColor listadoDeColores[], int tamanioListadoColores,
                         eTipoMoto listadoTipos[], int tamanioListadoTipos, eCliente listadoClientes[], int tamanioListaClientes);

/** \brief Pide al usuario un tipo de moto, muestra un listado de las motos de ese tipo.
 *
 * \param El array de motos
 * \param Un entero, el tamaño del array de motos
 * \param El array de colores
 * \param Un entero, el tamaño del array de colores
 * \param El array de tipos de moto
 * \param Un entero, el tamaño del array de tipos de moto
 * \param El array de clientes
 * \param Un entero, el tamaño del array de clientes
 *
 */
void mostrarMotoPorTipo(eMoto listadoMotos[], int tamanioListaMotos, eColor listadoDeColores[], int tamanioListadoColores,
                         eTipoMoto listadoTipos[], int tamanioListadoTipos, eCliente listadoClientes[], int tamanioListaClientes);
/** \brief Muestra las motos ingresadas de la mayor cilindrada
 *
 * \param El array de motos
 * \param Un entero, el tamaño del array de motos
 * \param El array de colores
 * \param Un entero, el tamaño del array de colores
 * \param El array de tipos de motos
 * \param Un entero, el tamaño del array de tipos de motos
 * \param El array de clientes
 * \param Un entero, el tamaño del array de clientes
 *
 */
void mostrarMotosMayorCilindrada(eMoto listadoMotos[], int tamanioListaMotos, eColor listadoDeColores[], int tamanioListadoColores,
                                 eTipoMoto listadoTipos[], int tamanioListadoTipos, eCliente listadoClientes[], int tamanioListaClientes);

/** \brief Ordena el listado de motos usando el tipo de moto como criterio de ordenamiento
 *
 * \param El array de motos
 * \param Un entero, el tamaño del array de motos
 *
 */
void ordenarPorTipo(eMoto listadoDeMotos[], int tamanioListadoMotos);

/** \brief Ordena el listado de motos usando el color como criterio de ordenamiento
 *
 * \param El array de motos
 * \param Un entero, el tamaño del array de motos
 *
 */
void ordenarPorColor(eMoto listadoDeMotos[], int tamanioListadoMotos);

/** \brief Informa cual es el color mas popular de los ingresados
 *
 * \param El array de motos
 * \param Un entero, el tamaño del array de motos
 *
 */
void colorMasPopular(eMoto listadoDeMotos[], int tamanioListadoMotos);

/** \brief
 *
 * \param El array de motos
 * \param  Un entero, el tamaño del array de motos
 * \param El array de colores
 * \param  Un entero, el tamaño del array de colores
 * \param El array de tipos de moto
 * \param  Un entero, el tamaño del array de tipos de moto
 * \param El array de trabajos
 * \param  Un entero, el tamaño del array de trabajos
 * \param El array de servicios
 * \param  Un entero, el tamaño del array de servicios
 * \param El array de clientes
 * \param  Un entero, el tamaño del array de clientes
 *
 */
void serviciosHechosAUnaMoto(eMoto listadoMotos[], int tamanioListadoMotos, eColor listadoDeColores[], int tamanioListadoColores,
                              eTipoMoto listadoTipos[], int tamanioListadoTipos, eTrabajo listadoTrabajos[],
                              int tamanioListadoTrabajos, eServicio listadoDeServicios[], int tamanioListadoServicios,
                              eCliente listadoClientes[], int tamanioListaClientes);
/** \brief Informa el total en $ de todos los servicios hechos a una moto
 *
 * \param El array de motos
 * \param Un entero, el tamaño del array de motos
 * \param El array de colores
 * \param Un entero, el tamaño del array de colores
 * \param El array de tipos de moto
 * \param Un entero, el tamaño del array de tipos de moto
 * \param El array de trabajos
 * \param Un entero, el tamaño del array de trabajos
 * \param El array de servicios
 * \param Un entero, el tamaño del array de servicios
 * \param El array de clientes
 * \param Un entero, el tamaño del array de clientes
 *
 */
void costoServiciosHechosAUnaMoto(eMoto listadoMotos[], int tamanioListadoMotos, eColor listadoDeColores[], int tamanioListadoColores,
                              eTipoMoto listadoTipos[], int tamanioListadoTipos, eTrabajo listadoTrabajos[],
                              int tamanioListadoTrabajos, eServicio listadoDeServicios[], int tamanioListadoServicios,
                               eCliente listadoClientes[], int tamanioListaClientes);

/** \brief Informa a que motos se les realizo un determinado servicio
 *
 * \param El array de servicios
 * \param Un entero, el tamaño del array de servicios
 * \param El array de trabajos
 * \param Un entero, el tamaño del array de trabajos
 * \param El array de motos
 * \param Un entero, el tamaño del array de motos
 * \param El array de colores
 * \param Un entero, el tamaño del array de colores
 * \param El array de tipos de moto
 * \param Un entero, el tamaño del array de tipos
 * \param El array de clientes
 * \param Un entero, el tamaño del array de clientes
 *
 */
void motosDeUnServicio(eServicio listadoDeServicios[], int tamanioListadoServicios, eTrabajo listadoDeTrabajos[],
                        int tamanioListadoTrabajos, eMoto listadoDeMotos[], int tamanioListaMotos,
                        eColor listadoDeColores[], int tamanioListadoColores,
                        eTipoMoto listadoTipos[], int tamanioListadoTipos,
                        eCliente listadoClientes[], int tamanioListaClientes);

/** \brief Compara dos fechas
 *
 * \param La primer fecha a comparar (del tipo de dato estructura fecha)
 * \param La segunda fecha a comparar (del tipo de dato estructura fecha)
 * \return Devuelve un entero, 1 si las fechas son iguales y 0 si no lo son
 *
 */
int comparaFechas(eFecha f1, eFecha f2);

/** \brief Muestra un trabajo
 *
 * \param El trabajo a mostrar
 * \param El array de servicios
 * \param El tamaño del array de servicios
 *
 */
void mostrarUnTrabajo(eTrabajo unTrabajo,eServicio listaDeServicios[], int tamanioListaServicios);

/** \brief Muestra los trabajos realizados en una determinada fecha
 *
 * \param El array de trabajos
 * \param Un entero, el tamaño del array de trabajos
 * \param El array de servicios
 * \param Un entero, el tamaño del array de servicios
 *
 */
void trabajosDeUnaFecha(eTrabajo listaDeTrabajos[], int tamanioListaTrabajos, eServicio listaDeServicios[],
                        int tamanioListaServicios);


                        /** \brief Cuenta que cantidad de motos de un tipo y color determinado se ingresaron
 *
 * \param El array de motos
 * \param Un entero, el tamaño del array de motos
 *
 */
void contadorDeColoresTipos(eMoto listadoDeMotos[], int tamanioListadoMotos);

#endif // INFORMES_H_INCLUDED
