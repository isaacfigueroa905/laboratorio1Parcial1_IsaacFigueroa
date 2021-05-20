/*
 * Servicio.c
 *
 *  Created on: 17 may. 2021
 *      Author: Isaac
 */


#include <string.h>
#include <stdio.h>
#include "Servicio.h"

#define OCUPADO 1
#define VACIO 0
#define ELIMINADO -1





int BuscarServicioPorId(eServicio listaServicios[], int tamS, int ID)
{
	int retorno = -1;
	int i;



	if (listaServicios != NULL && tamS > 0)
	{

		for (i = 0; i < tamS; i++)
		{

			if (listaServicios[i].idServicios == ID && listaServicios[i].isEmpty == OCUPADO)
			{

				retorno=i;//encontre id
				break;
			}
		}
	}

	return retorno;
}


int ObtenerDescripcionServicio(eServicio listaServicios[], int tamS, int buscar, char* descripcionEncontrada)
{
	int i;

	for(i=0;i<tamS;i++)
	{
		if(listaServicios[i].idServicios==buscar&& listaServicios[i].isEmpty==OCUPADO)
		{
			strcpy(descripcionEncontrada,listaServicios[i].descripcion);
		}

	}

	return 0;
}




void MostrarServicios(eServicio listaServicios[],int tamS)
{
    int i;

    printf("\n\t CODIGO------SERVICIO-------PRECIO\n");


    for(i=0;i<tamS;i++)
    {
        printf("\n\t%3d \t%12s \t%10.2f \n",listaServicios[i].idServicios,listaServicios[i].descripcion,listaServicios[i].precio);
        printf("\t_________________________________\n");
    }
}




