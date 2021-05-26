#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarCilindrada(int cilindrada)
{
    int todoOk = 0;
    if(cilindrada == 50 || cilindrada == 125 || cilindrada == 500 || cilindrada == 600 ||cilindrada ==  750 )
    {
        todoOk = 1;
    }
    return todoOk;
}

void cambiarFlagATrue(int* bandera){

     if(bandera != NULL)
     {
        *bandera = 1;
     }

}

int validarFecha( int dia, int mes, int anio)
{
    int todoOk = 0;
    if(anio > 2000 && anio < 2030 && mes > 0 && mes < 13)
    {
        switch(mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(dia > 0 && dia < 32)
            {
                todoOk= 1;
            }
        break;
        case 2:
            if(dia > 0 && dia < 30)
            {
                todoOk= 1;
            }
        break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(dia > 0 && dia < 31)
            {
                todoOk= 1;
            }
        break;
        }

    }

    return todoOk;
}
