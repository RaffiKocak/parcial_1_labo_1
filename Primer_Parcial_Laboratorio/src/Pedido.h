/*
 * Pedido.h
 *
 *  Created on: 11 oct 2021
 *      Author: Raffi
 */

#ifndef PEDIDO_H_
#define PEDIDO_H_

#include "Input.h"
#include "Cliente.h"

#define COMPLETADO 1
#define PENDIENTE -1
#define VACIO 0

struct {
	int idPedido; //PK
	float kilosTotales;
	float kilosHDPE;
	float kilosLDPE;
	float kilosPP;
	int idCliente; //FK
	int isEmpty;
} typedef ePedido;

/// @brief Inicializa todos los campos -isEmpty- de todas las posiciones del array en 0 (VACIO)
///
/// @param list
/// @param len
/// @return Retorna ERROR (-1) [Puntero NULO o tama�o de array inv�lido], (0) si la operaci�n sale bien.
int InitPedido(ePedido list[], int len);

/// @brief Agrega un pedido al array junto con los valores recibidos en los par�metros de esta funci�n.
///
/// @param lista
/// @param tam
/// @param id
/// @param kilosTotales
/// @param idCliente
/// @return Retorna ERROR (-1) [Puntero NULO, tama�o de array inv�lido o array sin espacio], (0) si la operaci�n sale bien.
int AddPedido(ePedido lista[], int tam, int id, float kilosTotales, int idCliente);

/// @brief Borra un pedido especificado de la lista a trav�s el ID recibido por par�metro.
///
/// @param lista
/// @param tam
/// @param id
/// @return Retorna ERROR (-1) [Puntero NULO, tama�o de array inv�lido o no se encontr� el pedido], (0) si la operaci�n sale bien.
int RemovePedido(ePedido lista[], int tam, int id);

/// @brief Pide los datos del nuevo pedido a cargar y lo agrega al array de pedidos. Se encarga del incremento del contador de ID de pedidos.
///
/// @param listaPedidos
/// @param tamPedidos
/// @param listaClientes
/// @param tamClientes
/// @param listaLocalidades
/// @param tamLocalidades
/// @param contadorIdPedidosMain
/// @return Retorna ERROR (-1) [Puntero NULO o tama�o de array inv�lido], (0) si la operaci�n sale bien.
int CrearPedido (ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades, int *contadorIdPedidosMain);

/// @brief Pregunta al usuario qu� pedido quiere procesar y luego pregunta qu� pl�sticos desea procesar. Una vez finalizado, el pedido pasa a estar COMPLETADO.
///
/// @param listaPedido
/// @param tamPedido
/// @param listaEmpresa
/// @param tamEmpresa
/// @return Retorna ERROR (-1) [Puntero NULO o tama�o de array inv�lido], (0) si la operaci�n sale bien.
int ProcesarPedidoPendiente(ePedido listaPedido[], int tamPedido, eCliente listaEmpresa[], int tamEmpresa);

/// @brief Imprime la lista de pedidos seg�n el criterio introducido por par�metro. PENDIENTE (-1) para los pendientes, COMPLETADO (1) para los completados.
///
/// @param listaPedido
/// @param tamPedido
/// @param listaEmpresa
/// @param tamEmpresa
/// @param criterio
/// @return Retorna ERROR (-1) [Puntero NULO o tama�o de array inv�lido], (0) si la operaci�n sale bien.
int PrintPedidosConCriterio(ePedido listaPedido[], int tamPedido, eCliente listaEmpresa[], int tamEmpresa, int criterio);

/// @brief Imprime un pedido individual seg�n el criterio introducido por par�metro. PENDIENTE (-1) para los pendientes, COMPLETADO (1) para los completados.
///
/// @param pedido
/// @param listaEmpresa
/// @param tamEmpresa
/// @param criterio
void PrintPedidoIndividualConCriterio (ePedido pedido, eCliente listaEmpresa[], int tamEmpresa, int criterio);

/// @brief Busca una posici�n libre en el array de la lista de pedidos.
///
/// @param list
/// @param len
/// @return Retorna ERROR (-1) [Puntero NULO, tama�o de lista inv�lido o sin posiciones libres], (POSICION) si hay una posici�n libre.
int BuscarEspacioLibrePedido (ePedido list[], int len);

/// @brief Calcula en todos los pedidos COMPLETADOS cu�nto polipropileno en total se proces�.
///
/// @param lista
/// @param tam
/// @return Retorna la cantidad de polipropeno procesado.
float CalcularTotalPolipropenoProcesado (ePedido lista[], int tam);

/// @brief Busca un pedido por ID dentro del array y retorna la posici�n correspondiente, si existe.
///
/// @param lista
/// @param tam
/// @param id
/// @param estadoABuscar
/// @return Retorna ERROR (-1) [Puntero NULO, tama�o de lista inv�lido o cliente no encontrado], (POSICION) si encuentra al empleado.
int FindPedidoByID(ePedido lista[], int tam, int id, int estadoABuscar);

/// @brief Busca y verifica que exista un pedido  dentro del array.
///
/// @param lista
/// @param tam
/// @param criterio
/// @return Retorna (1) si encuentra un cliente, (0) si no existen.
int VerificarArrayCargadoPedidos(ePedido lista[], int tam, int criterio);

/// @brief Funci�n auxiliar. Hardcodea pedidos a la lista.
///
/// @param lista
void HardcodearPedidos (ePedido lista[]);


#endif /* PEDIDO_H_ */
