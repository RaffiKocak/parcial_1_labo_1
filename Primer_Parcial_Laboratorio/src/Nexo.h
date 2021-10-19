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

/// @brief Muestra el menú principal del programa, en donde el usuario va a poder operar como quiera
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
/// @return Retorna ERROR (-1) [Puntero NULO, tamaño de array inválido o no se encontró el pedido], (0) si la operación sale bien.
int MostrarMenuPrincipal (eCliente listaClientes[], int tamCliente, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidades, int *contadorIDClientes, int *contadorIDPedidos, int *contadorIDLocalidades);

/// @brief Muestra el submenú correspondiente a la estructura de localidades
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
/// @return Retorna ERROR (-1) [Puntero NULO, tamaño de array inválido o no se encontró el pedido], (0) si la operación sale bien.
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
/// @return Retorna ERROR (-1) [Puntero NULO, tamaño de array inválido o no se encontró el pedido], (0) si la operación sale bien.
int PrintLocalidadConCantidadPedidosPendientes (eLocalidad listaLocalidad[], int tamLocalidad, ePedido listaPedido[], int tamPedido, eCliente listaEmpresa[], int tamEmpresa);

/// @brief Muestra el promedio de PP reciclado por cada cliente que realizó al menos un pedido de reciclaje de ese plástico.
///
/// @param listaPedido
/// @param tamPedido
/// @param listaEmpresa
/// @param tamEmpresa
/// @return Retorna ERROR (-1) [Puntero NULO, tamaño de array inválido o no se encontró el pedido], (0) si la operación sale bien.
int InformarPromedioDePPReciclado (ePedido listaPedido[], int tamPedido, eCliente listaEmpresa[], int tamEmpresa);

/// @brief Cuenta la cantidad de clientes que tienen al menos un pedido en el cual se procesó PP.
///
/// @param listaEmpresa
/// @param tamEmpresa
/// @param listaPedido
/// @param tamPedido
/// @return Retorna la cantidad de clientes que procesaron PP.
int ContarClientesQueProcesanPP (eCliente listaEmpresa[], int tamEmpresa, ePedido listaPedido[], int tamPedido);

/// @brief Cuenta la cantidad de pedidos pendientes que existen en una localidad ingresada por parámetro.
///
/// @param localidad
/// @param listaPedido
/// @param tamPedido
/// @param listaEmpresa
/// @param tamEmpresa
/// @return Retorna la cantidad de pedidos pendientes de la localidad ingresada.
int ContarPedidosPendientesPorLocalidad (eLocalidad localidad, ePedido listaPedido[], int tamPedido, eCliente listaEmpresa[], int tamEmpresa);

/// @brief Pide el ingreso de ID de un cliente para que el usuario lo pueda borrar lógicamente. Si ese cliente tiene pedidos relacionados, también se borrarán.
///
/// @param listaEmpresa
/// @param tamEmpresa
/// @param listaPedido
/// @param tamPedido
/// @param listaLocalidad
/// @param tamLocalidad
/// @return Retorna ERROR (-1) [Puntero NULO, tamaño de array inválido o no se encontró el pedido], (0) si la operación sale bien.
int BajaEmpresa(eCliente listaEmpresa[], int tamEmpresa, ePedido listaPedido[], int tamPedido, eLocalidad listaLocalidad[], int tamLocalidad);

/// @brief Borra los pedidos relacionados a una empresa ingresada por parámetro.
///
/// @param empresa
/// @param listaPedido
/// @param tamPedido
/// @return Retorna ERROR (-1) [Puntero NULO, tamaño de array inválido o no se encontró el pedido], (0) si la operación sale bien.
int BajaPedidosDeEmpresa (eCliente empresa, ePedido listaPedido[], int tamPedido);

/// @brief Pide el ingreso de ID de una localidad para que el usuario la pueda borrar lógicamente. Si esa localidad tiene clientes relacionados, también se borrarán.
///
/// @param listaLocalidad
/// @param tamLocalidad
/// @param listaEmpresa
/// @param tamEmpresa
/// @param listaPedido
/// @param tamPedido
/// @return Retorna ERROR (-1) [Puntero NULO, tamaño de array inválido o no se encontró el pedido], (0) si la operación sale bien.
int BajaLocalidad (eLocalidad listaLocalidad[], int tamLocalidad, eCliente listaEmpresa[], int tamEmpresa, ePedido listaPedido[], int tamPedido);

/// @brief Cuenta la cantidad de clientes que pertenecen a la localidad ingresada por parámetro.
///
/// @param localidad
/// @param listaEmpresa
/// @param tamEmpresa
/// @return Retorna la cantidad de clientes que pertenecen a esa localidad.
int ContarCantidadClientesEnLocalidad(eLocalidad localidad, eLocalidad listaEmpresa[], int tamEmpresa);

/// @brief Borra los clientes relacionados a una localidad ingresada por parámetro. También borra los pedidos relacionados a esos clientes que se dan de baja.
///
/// @param localidad
/// @param listaEmpresa
/// @param tamEmpresa
/// @param listaPedido
/// @param tamPedido
/// @return Retorna ERROR (-1) [Puntero NULO, tamaño de array inválido o no se encontró el pedido], (0) si la operación sale bien.
int BorrarClientesEnLocalidad (eLocalidad localidad, eCliente listaEmpresa[], int tamEmpresa, ePedido listaPedido[], int tamPedido);

#endif /* NEXO_H_ */
