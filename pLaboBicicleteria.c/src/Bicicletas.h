/*
 * Bicicletas.h
 *
 *  Created on: 20 may. 2021
 *      Author: Isaac

*/
#ifndef BICICLETAS_H_

#define BICICLETAS_H_



#endif /* BICICLETAS_H_*/


#define OCUPADO 1
#define VACIO 0
#define ELIMINADO -1

typedef struct
{
	int idBici;
	char marca[25] ;
	int rodado;
	char color[25]  ;
	int isEmpty;


}eBicicleta;



void MostrarBicicletas(eBicicleta listaBicis[], int tamB);

int BuscarBiciPorId(eBicicleta listaBicis[], int tamB, int ID);

int ObtenerDescripcionBici(eBicicleta listaBicis[], int tamB, int buscar, char* descripcionEncontrada);


