#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct{
        int id;
        char descripcion[20];
        float precio;
       int isEmpty;

 }eServicio;


/** \brief Hardcodea los servicios en el listado
 *
 * \param El array de servicios
 * \param El tamaño del listado del array
 *
 */
void harcodearServicios(eServicio listadoDeServicios[], int tamanioListadoServicios);

/** \brief Muestra un listado de los servicios ingresados
 *
 * \param El array de servicios
 * \param Un entero, el tamaño del array de servicios
 *
 */
void mostrarServicios(eServicio listadoDeServicios[], int tamanioListadoServicios);

/** \brief Carga el nombre del servicio, dado su id
 *
 * \param El array de servicios
 * \param El tamaño del array de servicios
 * \param Un entero, el numero de identificacion del trabajo
 * \param La cadena de caracteres donde escribe el nombre del servicio
 *
 */
void cargarNombreServicios(eServicio listadoDeServicios[], int tamanioListadoServicios, int identificador, char descripServ[]);

#endif // SERVICIOS_H_INCLUDED
