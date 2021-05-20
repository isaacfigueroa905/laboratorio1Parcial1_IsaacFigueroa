/*
 * Bicicletas.c
 *
 *  Created on: 20 may. 2021
 *      Author: Isaac
 */


#include "Bicicletas.h"

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"

#include <string.h>

#define OCUPADO 1
#define VACIO 0
#define ELIMINADO -1

int  MostrarUnaBici(eBicicleta unaBici, char* marB)
{
    printf("\n\%10d  %18s %10d %10s \n", unaBici.idBici, unaBici.marca,unaBici.rodado,unaBici.color);
    printf("\t__________________________________________________________________________________\n");


    return 0;
}




void MostrarBicicletas(eBicicleta listaBicis[], int tamB)
{
    int i;

    printf("\n\t CODIGO------MARCA-------RODADO-----------COLOR\n");


    for(i=0;i<tamB;i++)
    {
    	 printf("\n\%10d  %18s %10d %10s \n ", listaBicis[i] .idBici, listaBicis[i].marca,listaBicis[i].rodado,listaBicis[i].color);


    }

}






int BuscarBiciPorId(eBicicleta listaBicis[], int tamB, int ID)
{
	int retorno = -1;
	int i;



	if (listaBicis != NULL && tamB > 0)
	{

		for (i = 0; i < tamB; i++)
		{

			if (listaBicis[i].idBici == ID && listaBicis[i].isEmpty == OCUPADO)
			{

				retorno=i;//encontre id
				break;
			}
		}
	}

	return retorno;
}


int ObtenerDescripcionBici(eBicicleta listaBicis[], int tamB, int buscar, char* descripcionEncontrada)
{
	int i;

	for(i=0;i<tamB;i++)
	{
		if(listaBicis[i].idBici==buscar&& listaBicis[i].isEmpty==OCUPADO)
		{
			strcpy(descripcionEncontrada,listaBicis[i].marca);
		}

	}

	return 0;
}












