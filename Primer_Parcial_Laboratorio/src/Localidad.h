/*
 * Localidades.h
 *
 *  Created on: 13 oct 2021
 *      Author: Raffi
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

#include "Input.h"

#define TRUE 1
#define FALSE 0

struct {
	int idLocalidad;
	char descripcion[51];
	int isEmpty;
} typedef eLocalidad;


/// @brief Inicializa todos los campos -isEmpty- de todas las posiciones del array en 0 (VACIO)
///
/// @param lista
/// @param tam
/// @return Retorna ERROR (-1) [Puntero NULO o tamaño de array inválido], (0) si la operación sale bien.
int InitLocalidad(eLocalidad lista[], int tam);

/// @brief Agrega una localidad al array junto con los valores recibidos en los parámetros de esta función.
///
/// @param lista
/// @param tam
/// @param id
/// @param descripcion
/// @return Retorna ERROR (-1) [Puntero NULO, tamaño de array inválido o array hay espacio], (0) si la operación sale bien.
int AddLocalidad(eLocalidad lista[], int tam, int id, char descripcion[]);

/// @brief Borra una localidad especificada de la lista a través el ID recibido por parámetro.
///
/// @param lista
/// @param tam
/// @param id
/// @return Retorna ERROR (-1) [Puntero NULO, tamaño de array inválido o no se encontró la localidad], (0) si la operación sale bien.
int RemoveLocalidad(eLocalidad lista[], int tam, int id);

/// @brief Pide los datos de la nueva localidad a cargar y lo agrega al array de pedidos. Se encarga del incremento del contador de ID de localidades.
///
/// @param lista
/// @param tam
/// @param idMainLocalidad
/// @return Retorna ERROR (-1) [Puntero NULO o tamaño de array inválido], (0) si la operación sale bien.
int AltaLocalidad(eLocalidad lista[], int tam, int *idMainLocalidad);

/// @brief Pide el ID de una localidad al usuario para modificar su descripción.
///
/// @param lista
/// @param tam
/// @return Retorna ERROR (-1) [Puntero NULO o tamaño de array inválido], (0) si la operación sale bien.
int EditLocalidad(eLocalidad lista[], int tam);

/// @brief Imprime la lista de localidades junto con los números ordenados de 1 a n.
///
/// @param lista
/// @param tam
/// @param contadorLocalidades
/// @return Retorna ERROR (-1) [Puntero NULO o tamaño de array inválido], (0) si la operación sale bien.
int PrintListaLocalidadesConPosicion(eLocalidad lista[], int tam, int *contadorLocalidades);

/// @brief Busca una posición libre en el array de la lista de localidades.
///
/// @param lista
/// @param tam
/// @return Retorna ERROR (-1) [Puntero NULO, tamaño de lista inválido o sin posiciones libres], (POSICION) si hay una posición libre.
int BuscarEspacioLibreLocalidad (eLocalidad lista[], int tam);

/// @brief Ordena la lista de localidades de manera ascendente. Las que tenga el campo "isEmpty" en (0) se ordenan antes que las que tienen "isEmpty" en (1).
///
/// @param lista
/// @param tam
/// @return Retorna ERROR (-1) [Puntero NULO o tamaño de array inválido], (0) si la operación sale bien.
int SortLocalidadesPorEstado(eLocalidad lista[], int tam);

/// @brief Imprime una localidad ingresada por parámetro, junto con un número entero que represente su posición en la lista, también ingresado por parámetro.
///
/// @param localidad
/// @param posicion
void PrintLocalidadIndividualConPosicion (eLocalidad localidad, int posicion);

/// @brief Imprime la lista de localidades con su ID correspondiente.
///
/// @param lista
/// @param tam
/// @return Retorna ERROR (-1) [Puntero NULO o tamaño de array inválido], (0) si la operación sale bien.
int PrintListaLocalidades(eLocalidad lista[], int tam);

/// @brief Imprime una localidad individual ingresada por parámetro, con su ID correspondiente.
///
/// @param localidad
void PrintLocalidadIndividual (eLocalidad localidad);

/// @brief Busca una localidad por ID dentro del array y retorna la posición correspondiente, si existe.
///
/// @param lista
/// @param tam
/// @param id
/// @return Retorna ERROR (-1) [Puntero NULO, tamaño de lista inválido o cliente no encontrado], (POSICION) si encuentra al empleado.
int FindLocalidadById(eLocalidad lista[], int tam, int id);

/// @brief Busca y verifica que exista un pedido con el campo "isEmpty" con valor (0) dentro del array.
///
/// @param lista
/// @param tam
/// @return Retorna (1) si encuentra un cliente, (0) si no existen.
int VerificarArrayCargadoLocalidades(eLocalidad lista[], int tam);

/// @brief Función auxiliar. Hardcodea localidaes a la lista.
///
/// @param lista
void HardcodearLocalidades (eLocalidad lista[]);


#endif /* LOCALIDAD_H_ */
