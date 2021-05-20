/*
 * inputs.c
 *
 *  Created on: 13 may. 2021
 *      Author: Isaac
 */

#include "inputs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo,int maximo,int reintentos)
{
    int bufferInt;
    int retorno=-1;


    while(reintentos>0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(genInt(&bufferInt)==0)
        {
            if(bufferInt>= minimo && bufferInt<= maximo)
           {
               *pResultado=bufferInt;
                retorno=0;
                break;
           }

        }
        printf("%s",mensajeError);

    }
    return retorno;


}
 int genInt(int* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado!=NULL)
    {
        if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
        {
           *pResultado=atoi(buffer);
            retorno=0;
        }

    }


    return retorno;
}

 int esNumerica(char* cadena)
{
    int i=0;
    int retorno=1;
    if(cadena!=NULL && strlen(cadena)>0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena [i] <'0' || cadena[i]>'9')
            {
                retorno=0;
                break;
            }
            i++;

        }
    }
    return retorno;
}

 int myGets(char* cadena,int longuitud)
{
    if(cadena != NULL && longuitud>0 && fgets(cadena,longuitud,stdin)==cadena)
    {
        fflush(stdin);
        if(cadena[strlen(cadena)-1]=='\n')
        {
            cadena[strlen(cadena)-1]='\0';
        }
        return 0;
    }
    return -1;

}



int utn_getCaracter(int* pResultado, char* mensaje, char* mensajeError, int minimo,int maximo,int reintentos)
{
    int retorno =-1;
    char buffer;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%c", &buffer);
            if(buffer>=minimo && buffer<=maximo)
            {
                *pResultado=buffer;
                retorno= 0;
                break;
            }


                printf("%s", mensajeError);
                reintentos --;


        }while(reintentos>=0);


    }


    return retorno;
}


int esSoloLetras(char str[])
{
	int i=0;
	//int retorno;
	while(str[i]!= '\0')
	{
		if((str[i]<'a' || str[i]>'z' ) && (str[i]<'A' || str[i]>'Z'))
		{

			return 0;
			i++;

		}


	}

	return 1;


}
