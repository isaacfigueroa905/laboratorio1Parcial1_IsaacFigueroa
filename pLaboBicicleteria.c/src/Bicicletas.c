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


#define OCUPADO 1
#define VACIO 0
#define ELIMINADO -1

int  MostrarUnaBici(eBicicleta unaBici, char* marB)
{
    printf("\n\%10d  %18s %10d %10s% \n", unaBici.id, unaBici.marca,unaBici.rodado,unaBici.color);
    printf("\t__________________________________________________________________________________\n");


    return 0;
}




void MostrarBicicletas(eBicicleta listaBicis[], int tamB)
{
    int i;

    printf("\n\t CODIGO------MARCA-------RODADO-----------COLOR\n");


    for(i=0;i<tamB;i++)
    {
    	 printf("\n\%10d  %18s %10d %10s% ", listaBicis[i] .id, listaBicis[i].marca,listaBicis[i].rodado,listaBicis[i].color);


    }

}
