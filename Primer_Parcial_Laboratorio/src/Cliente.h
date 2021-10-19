/*
 * Cliente.h
 *
 *  Created on: 11 oct 2021
 *      Author: Raffi
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "Input.h"
#include "Localidad.h"

#define TRUE 1
#define FALSE 0

struct {
	int idEmpresa; //PK
	char nombreEmpresa[51];
	char cuit[12];
	char direccion[51];
	int idLocalidad;
	int isEmpty;
} typedef eCliente;

struct {
	int idAuxiliar;
	int contador;
} typedef eAuxiliar;


/// @brief Inicializa todos los campos -isEmpty- de todas las posiciones del array en 1 (TRUE)
///
/// @param list
/// @param len
/// @return Retorna ERROR (-1) [Puntero NULO o tamaño de array inválido], (0) si la operación sale bien.
int InitCliente(eCliente list[], int len);

/// @brief Agrega un cliente al array junto con los valores recibidos en los parámetros de esta función.
///
/// @param listaEmpresa
/// @param tamEmpresa
/// @param id
/// @param nombreEmpresa
/// @param cuit
/// @param direccion
/// @param localidad
/// @return Retorna ERROR (-1) [Puntero NULO, tamaño de array inválido o array sin espacio], (0) si la operación sale bien.
int AddEmpresa(eCliente listaEmpresa[], int tamEmpresa, int id, char nombreEmpresa[], char cuit[], char direccion[], int localidad);

/// @brief Pide los datos del nuevo cliente a cargar y lo agrega al array de clientes. Se encarga del incremento del contador de ID de clientes.
///
/// @param listaEmpresa
/// @param tamEmpresa
/// @param listaLocalidad
/// @param tamLocalidad
/// @param contadorIdMain
/// @return Retorna ERROR (-1) [Puntero NULO o tamaño de array inválido], (0) si la operación sale bien.
int AltaEmpresa (eCliente listaEmpresa[], int tamEmpresa, eLocalidad listaLocalidad[], int tamLocalidad, int *contadorIdMain);

/// @brief Pregunta al usuario qué cliente quiere modificar a través de un pedido de ID y se muestran las opciones de los datos disponibles a modificar.
///
/// @param listaEmpresa
/// @param tamEmpresa
/// @param listaLocalidad
/// @param tamLocalidad
/// @return Retorna ERROR (-1) [Puntero NULO o tamaño de array inválido], (0) si la operación sale bien.
int EditEmpresa(eCliente listaEmpresa[], int tamEmpresa, eLocalidad listaLocalidad[], int tamLocalidad);


/// @brief Despliega un sub menú donde el usuario puede modificar el cliente que encontró ingresando su ID.
///
/// @param listaEmpresa
/// @param tamEmpresa
/// @param listaLocalidad
/// @param tamLocalidad
/// @param posicionAEditar
/// @return Retorna ERROR (-1) [Puntero NULO o tamaño de array inválido], (0) si la operación sale bien.
int MostrarSubMenuEditEmpresa(eCliente listaEmpresa[], int tamEmpresa, eLocalidad listaLocalidad[], int tamLocalidad, int posicionAEditar);

/// @brief Borra un cliente especificado de la lista a través el ID recibido por parámetro.
///
/// @param list
/// @param len
/// @param id
/// @return Retorna ERROR (-1) [Puntero NULO, tamaño de array inválido o no se encontró el cliente], (0) si la operación sale bien.
int RemoveEmpresa(eCliente list[], int len, int id);

/// @brief Imprime la lista de clientes que se encuentra en el array.
///
/// @param listEmpresa
/// @param tamEmpresa
/// @param listaLocalidad
/// @param tamLocalidad
/// @return Retorna ERROR (-1) [Puntero NULO o tamaño de array inválido], (0) si la operación sale bien.
int PrintEmpresas(eCliente listEmpresa[], int tamEmpresa, eLocalidad listaLocalidad[], int tamLocalidad);

/// @brief Imprime un empleado individualmente.
///
/// @param empresa
/// @param listaLocalidad
/// @param tamLocalidad
void PrintEmpresaIndividual(eCliente empresa, eLocalidad listaLocalidad[], int tamLocalidad);

/// @brief Imprime un mensaje junto con el ID numérico correspondiente a una localidad.
///
/// @param idLocalidad
/// @param listaLocalidad
/// @param tamLocalidad
/// @param mensaje
void PrintLocalidadDeUnCliente (int idLocalidad, eLocalidad listaLocalidad[], int tamLocalidad, char mensaje[]);

/// @brief Busca un cliente por ID dentro del array y retorna la posición correspondiente, si existe.
///
/// @param list
/// @param len
/// @param id
/// @return Retorna ERROR (-1) [Puntero NULO, tamaño de lista inválido o cliente no encontrado], (POSICION) si encuentra al empleado.
int FindEmpresaById(eCliente list[], int len, int id);

/// @brief Busca una posición libre en el array de la lista de clientes.
///
/// @param list
/// @param len
/// @return Retorna ERROR (-1) [Puntero NULO, tamaño de lista inválido o sin posiciones libres], (POSICION) si hay una posición libre.
int BuscarEspacioLibreEmpresa (eCliente list[], int len);

/// @brief Busca y verifica que exista un cliente con el campo isEmpty (0) dentro del array.
///
/// @param list
/// @param len
/// @return Retorna (1) si encuentra un cliente, (0) si no existen.
int VerificarArrayCargadoEmpresa(eCliente list[], int len);

/// @brief Función auxiliar. Hardcodea clientes a la lista.
///
/// @param lista
void HardcodearEmpresa (eCliente lista[]);

#endif /* CLIENTE_H_ */
