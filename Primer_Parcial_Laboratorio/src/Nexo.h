/*
 * nexo.h
 *
 *  Created on: 11 oct 2021
 *      Author: Raffi
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "Cliente.h"
#include "Pedido.h"
#include "Localidad.h"

/// @brief Muestra el men� principal del programa, en donde el usuario va a poder operar como quiera
///
/// @param listaClientes
/// @param tamCliente
/// @param listaPedidos
/// @param tamPedidos
/// @param listaLocalidades
/// @param tamLocalidades
/// @param contadorIDClientes
/// @param contadorIDPedidos
/// @param contadorIDLocalidades
/// @return Retorna ERROR (-1) [Puntero NULO, tama�o de array inv�lido o no se encontr� el pedido], (0) si la operaci�n sale bien.
int MostrarMenuPrincipal (eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidades, int *contadorIDClientes, int *contadorIDPedidos, int *contadorIDLocalidades);

/// @brief Muestra el submen� correspondiente a la estructura de localidades
///
/// @param listaLocalidad
/// @param tamLocalidad
/// @param listaEmpresa
/// @param tamEmpresa
/// @param listaPedido
/// @param tamPedido
/// @param idMainLocalidad
void MostrarSubMenuLocalidad (eLocalidad listaLocalidad[], int tamLocalidad, eCliente listaEmpresa[], int tamEmpresa,
		ePedido listaPedido[], int tamPedido, int *idMainLocalidad);

/// @brief Imprime la lista de clientes con la cantidad de pedidos pendientes que tiene cada uno.
///
/// @param listaEmpresa
/// @param tamEmpresa
/// @param listaPedido
/// @param tamPedido
/// @param listaLocalidad
/// @param tamLocalidad
/// @return Retorna ERROR (-1) [Puntero NULO, tama�o de array inv�lido o no se encontr� el pedido], (0) si la operaci�n sale bien.
int PrintClientesConCantidadDePendientes(eCliente listaEmpresa[], int tamEmpresa, ePedido listaPedido[], int tamPedido, eLocalidad listaLocalidad[], int tamLocalidad);

/// @brief Imprime un cliente individual con la cantidad de pedidos pendientes del mismo.
///
/// @param empresa
/// @param listaPedido
/// @param tamPedido
/// @param listaLocalidad
/// @param tamLocalidad
void PrintClienteIndividualConCantidadDePendientes (eCliente empresa, ePedido listaPedido[], int tamPedido, eLocalidad listaLocalidad[], int tamLocalidad);

/// @brief Cuenta la cantidad de pedidos pendientes de un cliente.
///
/// @param cliente
/// @param listaPedido
/// @param tamPedido
/// @return Retorna la cantidad de pedidos pendientes de un cliente.
int ContarCantidadPedidosPendientesDeCliente(eCliente cliente, ePedido listaPedido[], int tamPedido);

/// @brief Pide al usuario que se seleccione una localidad de la lista, luego imprime la cantidad de pedidos pendientes que le corresponden.
///
/// @param listaLocalidad
/// @param tamLocalidad
/// @param listaPedido
/// @param tamPedido
/// @param listaEmpresa
/// @param tamEmpresa
/// @return Retorna ERROR (-1) [Puntero NULO, tama�o de array inv�lido o no se encontr� el pedido], (0) si la operaci�n sale bien.
int PrintLocalidadConCantidadPedidosPendientes (eLocalidad listaLocalidad[], int tamLocalidad, ePedido listaPedido[], int tamPedido, eCliente listaEmpresa[], int tamEmpresa);

/// @brief Muestra el promedio de PP reciclado por cada cliente que realiz� al menos un pedido de reciclaje de ese pl�stico.
///
/// @param listaPedido
/// @param tamPedido
/// @param listaEmpresa
/// @param tamEmpresa
/// @return Retorna ERROR (-1) [Puntero NULO, tama�o de array inv�lido o no se encontr� el pedido], (0) si la operaci�n sale bien.
int InformarPromedioDePPReciclado (ePedido listaPedido[], int tamPedido, eCliente listaEmpresa[], int tamEmpresa);

/// @brief Cuenta la cantidad de clientes que tienen al menos un pedido en el cual se proces� PP.
///
/// @param listaEmpresa
/// @param tamEmpresa
/// @param listaPedido
/// @param tamPedido
/// @return Retorna la cantidad de clientes que procesaron PP.
int ContarClientesQueProcesanPP (eCliente listaEmpresa[], int tamEmpresa, ePedido listaPedido[], int tamPedido);

/// @brief Cuenta la cantidad de pedidos pendientes que existen en una localidad ingresada por par�metro.
///
/// @param localidad
/// @param listaPedido
/// @param tamPedido
/// @param listaEmpresa
/// @param tamEmpresa
/// @return Retorna la cantidad de pedidos pendientes de la localidad ingresada.
int ContarPedidosPendientesPorLocalidad (eLocalidad localidad, ePedido listaPedido[], int tamPedido, eCliente listaEmpresa[], int tamEmpresa);

/// @brief Pide el ingreso de ID de un cliente para que el usuario lo pueda borrar l�gicamente. Si ese cliente tiene pedidos relacionados, tambi�n se borrar�n.
///
/// @param listaEmpresa
/// @param tamEmpresa
/// @param listaPedido
/// @param tamPedido
/// @param listaLocalidad
/// @param tamLocalidad
/// @return Retorna ERROR (-1) [Puntero NULO, tama�o de array inv�lido o no se encontr� el pedido], (0) si la operaci�n sale bien.
int BajaEmpresa(eCliente listaEmpresa[], int tamEmpresa, ePedido listaPedido[], int tamPedido, eLocalidad listaLocalidad[], int tamLocalidad);

/// @brief Borra los pedidos relacionados a una empresa ingresada por par�metro.
///
/// @param empresa
/// @param listaPedido
/// @param tamPedido
/// @return Retorna ERROR (-1) [Puntero NULO, tama�o de array inv�lido o no se encontr� el pedido], (0) si la operaci�n sale bien.
int BajaPedidosDeEmpresa (eCliente empresa, ePedido listaPedido[], int tamPedido);

/// @brief Pide el ingreso de ID de una localidad para que el usuario la pueda borrar l�gicamente. Si esa localidad tiene clientes relacionados, tambi�n se borrar�n.
///
/// @param listaLocalidad
/// @param tamLocalidad
/// @param listaEmpresa
/// @param tamEmpresa
/// @param listaPedido
/// @param tamPedido
/// @return Retorna ERROR (-1) [Puntero NULO, tama�o de array inv�lido o no se encontr� el pedido], (0) si la operaci�n sale bien.
int BajaLocalidad (eLocalidad listaLocalidad[], int tamLocalidad, eCliente listaEmpresa[], int tamEmpresa, ePedido listaPedido[], int tamPedido);

/// @brief Cuenta la cantidad de clientes que pertenecen a la localidad ingresada por par�metro.
///
/// @param localidad
/// @param listaEmpresa
/// @param tamEmpresa
/// @return Retorna la cantidad de clientes que pertenecen a esa localidad.
int ContarCantidadClientesEnLocalidad(eLocalidad localidad, eLocalidad listaEmpresa[], int tamEmpresa);

/// @brief Borra los clientes relacionados a una localidad ingresada por par�metro. Tambi�n borra los pedidos relacionados a esos clientes que se dan de baja.
///
/// @param localidad
/// @param listaEmpresa
/// @param tamEmpresa
/// @param listaPedido
/// @param tamPedido
/// @return Retorna ERROR (-1) [Puntero NULO, tama�o de array inv�lido o no se encontr� el pedido], (0) si la operaci�n sale bien.
int BorrarClientesEnLocalidad (eLocalidad localidad, eCliente listaEmpresa[], int tamEmpresa, ePedido listaPedido[], int tamPedido);

#endif /* NEXO_H_ */
