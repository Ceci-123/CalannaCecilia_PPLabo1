#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


typedef struct{
            int idCliente;
            char nombre[20];
            char sexo;
            int isEmpty;

} eCliente;

/** \brief  Harcodea un listado de clientes
 *
 * \param El array de clientes
 * \param Un entero, el tamaño del array de clientes
 *
 */
void harcodearClientes(eCliente listadoClientes[], int tamanioListadoClientes);

/** \brief Muestra una lista con los clientes ingresados
 *
 * \param El array de clientes
 * \param Un entero, el tamaño del array de clientes
 *
 */
void mostrarClientes(eCliente listaClientes[], int tamanioListaClientes);


/** \brief Carga el nombre de un cliente dado por su identificador en una cadena de caracteres
 *
 * \param El array de clientes
 * \param Un entero, el tamaño del array de clientes
 * \param Un entero, numero de id de cliente
 * \param La cadena sobre la cual se quiere escribir el nombre
 *
 */
void cargarNombreCliente(eCliente listadoClientes[], int tamanioListaClientes, int identificador, char cadena[]);


#endif // CLIENTE_H_INCLUDED
