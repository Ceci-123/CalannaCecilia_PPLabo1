#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

/** \brief Valida el valor que ingresa el usuario, que sea un numero de cilindrada correcto
 *
 * \param Un entero, el valor que el usuario ingresa
 * \return Un entero, 0 si es un valor incorrecto, 1 si es correcto
 *
 */
int validarCilindrada(int cilindrada);

/** \brief Cambia el valor de una bandera a true, escribe un 1 en la variable
*
* \param El puntero a la direccion de memoria de la variable
*
*/
void cambiarFlagATrue(int* bandera);

/** \brief Valida que la fecha ingresada sea una fecha valida
 *
 * \param Un entero, el dia que el usuario ingreso
 * \param Un entero, el mes que el usuario ingreso
 * \param Un entero, el año que el usuario ingreso
 * \return Un entero, 0 si la fecha no es valida y 1 si es una fecha valida
 *
 */
int validarFecha( int dia, int mes, int anio);

#endif // VALIDACIONES_H_INCLUDED
