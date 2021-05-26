#ifndef TIPOSDEMOTO_H_INCLUDED
#define TIPOSDEMOTO_H_INCLUDED

typedef struct{
        int id;
        char descripcion[20];
        int isEmpty;

 }eTipoMoto;

 /** \brief Hardcodea el listado de tipos de motos
 *
 * \param El array de tipos de motos
 * \param Un entero, el tamaño del array
 *
 */
void harcodearTipo(eTipoMoto listadoDeTipos[], int tamanioListadoTipos);

/** \brief Carga el nombre del tipo de moto que se pasa por id en una cadena de caracteres
 *
 * \param El array de tipos de moto
 * \param Un entero, el tamaño del array de tipos de moto
 * \param Un entero, el numero de id del tipo de moto que se busca
 * \param La cadena de caracteres donde se escribe el nombre del tipo de moto
 *
 */
void cargarNombreTipo(eTipoMoto listadoDeTipos[], int tamanioListadoTipos, int identificador, char descripcion[]);

/** \brief Muestra un listado de tipos de moto
 *
 * \param El array de tipos de moto
 * \param Un entero, el tamaño del array de tipos de moto
 *
 */
void mostrarTipos(eTipoMoto listadoDeTipos[], int tamanioListadoTipos);

#endif // TIPOSDEMOTO_H_INCLUDED
