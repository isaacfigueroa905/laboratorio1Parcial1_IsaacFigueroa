/*
 * Trabajo.h
 *
 *  Created on: 17 may. 2021
 *      Author: Isaac
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_






#endif /* TRABAJO_H_ */



typedef struct
{
	int dia;
	int mes;
	int anio;

}eFechas;




typedef struct
{
	int idTrabajo;
	char marcaBicicleta[25] ;
	int rodadoBicicleta;
	int idServicio;
	int idBici;
	eFechas fecha;
	int isEmpty;

}eTrabajo;

/**
 * @fn eFechas IngresarFecha(char[])
 * @brief Estructura anidada del tipo fecha
 *
 * @param array de char mensaje
 * @return fecha
 */
eFechas IngresarFecha(char[]);



/**
 * @fn void InicializadorTrabajos(eTrabajo[], int)
 * @brief Inicializa los trabajos, asignando el estado VACIO a al campo isEmpty del array
 *
 * @param eTrabajo Array de trabajos.
 * @param int tamaño del array
 */
void InicializadorTrabajos(eTrabajo [] ,int);

/**
 * @fn int BuscarTrabajoPorId(eTrabajo[], int, int)
 * @brief Busca un trabajo a travez del ingreso de un is.
 *
 * @param eTrabajo Array de trabajos.
 * @param int tamaño del array.
 * @param int id a buscar
 * @return la posicion.
 */
int BuscarTrabajoPorId(eTrabajo [], int, int);

/**
 * @fn int BuscarLibre(eTrabajo[], int)
 * @brief Encuentr lugar libre dentro del array.
 *
 * @param eTrabajo array de trabajos.
 * @param int tamaño del array.
 * @return posicion libre.
 */
int BuscarLibre(eTrabajo[], int);



/**
 * @fn int MostrarUnTrabajo(eTrabajo, char*)
 * @brief Muestra un trabajo
 *
 * @param eTrabajo array de trabajos.
 * @param int tamaño del array.
 * @return 0
 */
int MostrarUnTrabajo(eTrabajo,char*);

/**
 * @fn int OrdenarTrabajosPorAnio(eTrabajo[], int)
 * @brief Ordena trabajos por año en orden decreciente, del mas nuevo al mas viejo.
 *
 * @param eTrabajo array de trabajos.
 * @param int tamaño del array.
 * @return 1 si no son iguales/ -1si son del mismo año
 */
int OrdenarTrabajosPorAnio(eTrabajo[], int);


/**
 * @fn void OrdenarPorMarcaBici(eTrabajo[], int)
 * @brief Ordena alfabeticamente de A a Z las marcas de las bicis.
 *
 ** @param eTrabajo array de trabajos.
 * @param int tamaño del array.
 * @void sin retorno
 */
void OrdenarPorMarcaBici(eTrabajo [], int);


/**
 * @fn void Ordenar(eTrabajo[], int)
 * @brief Ordenamiento doble, por año y marca, teniendo en cuenta si son del mismo año ordenara por marca.
 *
 * @param eTrabajo Array de trabajos.
 * @param int tamaño del array.
 */
void Ordenar(eTrabajo listaTrabajos[], int tamT);











/////

/**
 * @fn int GenerarId()
 * @brief Asigna un id automaticamente a cada trabajo.
 *
 * @return el id.
 */
int GenerarId();


/**
 * @fn float AcumularGanancia(eServicio[], int, eTrabajo[], int)
 * @brief Suma los precios en pesos de los trabajos realizados.
 *
 * @param eServicio Array de servicios.
 * @param int Tamaño del Array servicio.
 * @param eTrabajo Array de trabajos.
 * @param int Tamaño del array trabajo.
 * @return int el acumulador.
 */
float AcumularGanancia(eServicio [],int , eTrabajo [], int);


/**
 * @fn eTrabajo ingreso(eServicio[], int)
 * @brief La carga de datos de los trabajos.
 *
 * @param eServicio Array de servicios.
 * @param int tamaño del array servicio.
 * @return eTrabajo Los datos cargados de un trabajo, pedidos al usuario.
 */
eTrabajo ingreso(eServicio [] , int );

/**
 * @fn int EliminarTrabajo(eTrabajo[], int, eServicio[], int)
 * @brief Elimina un trabajo de la lista, haciendo una baja logica.
 *
 * @param eTrabajo Array de trabajos.
 * @param int tamaño del array de trabajo.
 * @param eServicio Array de servicios.
 * @param int tamaño del array servicio.
 * @return 0 si elimina; -1 si niega; 1 si no se encuentra id.
 */
int EliminarTrabajo(eTrabajo[], int, eServicio[],int);



/**
 * @fn int MostrarTodosLosTrabajos(eTrabajo[], int, eServicio[], int)
 * @brief Muestra todos los trabajos, junto a las descripciones del servicio a relizar.
 *
 * @param eTrabajo Array de trabajos.
 * @param int tamaño del array.
 * @param int Array de servicios.
 * @param int tamaño del array servicio.
 * @return 0
 */
int MostrarTodosLosTrabajos(eTrabajo[], int, eServicio[],int);

/**
 * @fn int CargarTrabajos(eTrabajo[], int, eServicio[], int)
 * @brief Carga los datos ingresados al sistema definitivamente.
 *
 * @param eTrabajo Array de trabajos.
 * @param int tamaño del array trabajos.
 * @param eServicio Array de servicios.
 * @param int tamaño del array servicio.
 * @return 0 si la carga fue exitosa; -1 si no.
 */
int CargarTrabajos(eTrabajo [] , int, eServicio [], int);

/**
 * @fn int ModificarTrabajo(eTrabajo[], int, eServicio[], int)
 * @brief Modifica los datos de un trabajo; los campos modificables, "marca bici" y "servicio".
 *
 * @param eTrabajo Array de trabajos.
 * @param int tamaño array trabajo.
 * @param eServicio Array de servicios.
 * @param int tamaño del array servicios.
 * @return 0 en el caso de una modificacion exitosa; -1 en caso contrario.
 */
int ModificarTrabajo(eTrabajo [], int , eServicio [], int);













