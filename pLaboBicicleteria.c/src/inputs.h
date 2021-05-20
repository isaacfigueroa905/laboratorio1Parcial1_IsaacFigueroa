/*
 * inputs.h
 *
 *  Created on: 13 may. 2021
 *      Author: Isaac
 */

#ifndef INPUTS_H_
#define INPUTS_H_





/**
 * @fn int utn_getCaracter(int*, char*, char*, int, int, int)
 * @brief pide un caracter y verifica que cumpla los parametros
 *
 * @param int* direccion de memoria del caracter a analizar
 * @param char* mensaje que pide el caracter
 * @param char* mensaje de error
 * @param int minimo de caracter
 * @param int maximo de caracter
 * @param int intentos maximos
 * @return
 */
int utn_getCaracter(int*, char* , char* , int, int,int);



/**
 * @fn int myGets(char*, int)
 * @brief lee stdin hasta que encuentra "\n" o hasta que haya copiado en cadena un maximo de longuitud -1 caracteres.
 *
 * @param char* puntero a direccion de memoria donde se obtendra la cadena
 * @param int define el tamaño de la cadena
 * @return 0 si se obtuvo una cadena; -1 si no
 */
 int myGets(char*,int);


 /**
   * @fn int esNumerica(char*)
  * @brief verifica si la cadena ingresada es numerica
  *
  * @param char* cadena a analizar
  * @return 1 si es numerica; 0 si nno
  */
 int esNumerica(char*);


 /**
   * @fn int genInt(int*)
  * @brief verifica si la cadena ingresada es numerica
  *
  * @param int* puntero al espacio de memoria donde se dejara el resultado de la funcion
  * @return 0 si se obtiene numero; -1 si no
  */
 int genInt(int*);


 /**
   * @fn int utn_getNumero(int*, char*, char*, int, int, int)
  * @brief int* valida si un numero ingresado cumple los parametros
  *
  * @param int* direccion de memoria con el numero que se debe analizar
  * @param char* el mensaje creado por el usuario
  * @param char* mensaje de error
  * @param int minimo permitido
  * @param int maximo permitido
  * @param int intentos permitidos
  * @param 0 si se cumple; -1 si no.

  * @return
  */
int utn_getNumero(int*, char*, char*, int,int,int);


int esSoloLetras(char str[]);

#endif /* INPUTS_H_ */
