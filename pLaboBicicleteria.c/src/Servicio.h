/*
 * Servicio.h
 *
 *  Created on: 17 may. 2021
 *      Author: Isaac
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_




#endif /* SERVICIO_H_ */



#define OCUPADO 1
#define VACIO 0
#define ELIMINADO -1

typedef struct
{
	int idServicios;
	char descripcion[25];
	float precio;
	int isEmpty;

}eServicio;

/**
 * @fn int BuscarServicioPorId(eServicio[], int, int)
 * @brief Encuentra un servicio al pasarle un id.
 *
 * @param eServicio array de servicio.
 * @param int tamaño del array.
 * @param int id del servicio a buscar
 * @return la posicion en el array.
 */
int BuscarServicioPorId(eServicio [], int, int);

/**
 * @fn int ObtenerDescripcionServicio(eServicio[], int, int, char*)
 * @brief Consigue la descripcion del servicio, del id ingresado.
 *
 * @param  eServicio Array de servicios.
 * @param int tamaño del array.
 * @param int el id a buscar
 * @param descripcionEncontrada
 * @return 0
 */
int ObtenerDescripcionServicio(eServicio listaServicios[], int tamS, int buscar, char* descripcionEncontrada);


/**
 * @fn void MostrarServicios(eServicio[], int)
 * @brief Muestra lista de servicios.
 *
 * @param eServicio Array de servicios.
 * @param int tamaño array
 *
 */
void MostrarServicios(eServicio[],int);

