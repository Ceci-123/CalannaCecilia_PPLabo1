#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
        int id;
        char nombreColor[20];
        int isEmpty;

 }eColor;

/** \brief Ingresa en el array de colores un listado de colores
 *
 * \param El array de colores
 * \param Un entero, el tamaño del array de colores
 *
 */
void harcodearColor(eColor listadoDeColores[], int tamanioListadoColores);

/** \brief Carga en una cadena de caracteres el nombre del color que se pasa por id
 *
 * \param El array de colores
 * \param Un entero, el tamaño del array de colores
 * \param Un entero, el numero de id del color
 * \param La cadena de caracteres donde se escribe el nombre del color
 *
 */
void cargarNombreColor(eColor listadoDeColores[], int tamanioListadoColores, int identificador, char descripcion[]);

/** \brief Muestra un listado de los colores
 *
 * \param El array de colores
 * \param Un entero, el tamaño del array de colores
 *
 */
void mostrarColores(eColor listadoDeColores[], int tamanioListadoColores);


#endif // COLOR_H_INCLUDED
