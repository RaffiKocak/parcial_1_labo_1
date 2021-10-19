/*
 * nexo.c
 *
 *  Created on: 11 oct 2021
 *      Author: Raffi
 */

#include "Nexo.h"

int MostrarClientesConMasCompletados (eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos) {
	int retorno;
	eAuxiliar contador[tamClientes];
	int maximo;
	int flag;

	retorno = -1;

	if(listaClientes != NULL && tamClientes > 0 && listaPedidos != NULL && tamPedidos > 0) {

		retorno = 0;
		flag = 1;

		if (VerificarArrayCargadoEmpresa(listaClientes, tamClientes) && VerificarArrayCargadoPedidos(listaPedidos, tamPedidos, COMPLETADO)) {
			for (int i = 0; i < tamClientes; i++) {
				if (!listaClientes[i].isEmpty) {
					contador[i].contador = 0;
					contador[i].idAuxiliar = listaClientes[i].idEmpresa;
				}
			}

			for(int i = 0; i < tamClientes; i++) {
				if (!listaClientes[i].isEmpty) {
					for (int j = 0; j < tamPedidos; j++) {
						if (listaPedidos[j].isEmpty == COMPLETADO && listaPedidos[j].idCliente == contador[i].idAuxiliar) {
							contador[i].contador++;
						}
					}
				}
			}

			for (int i = 0; i < tamClientes; i++) {
				if (!listaClientes[i].isEmpty && (contador[i].contador > maximo || flag)) {
					maximo = contador[i].contador;
					flag = 0;
				}
			}

			printf("El/los clientes con más pedidos completados es/son: \n");
			for (int i = 0; i < tamClientes; i++) {
				if (!listaClientes[i].isEmpty && contador[i].contador == maximo) {
					printf("%s\n", listaClientes[i].nombreEmpresa);
				}
			}

		} else if (!VerificarArrayCargadoEmpresa(listaClientes, tamClientes)) {
			printf("No hay clientes existentes para contar.\n");
		} else {
			printf("No hay pedidos pendientes para contar.\n");
		}
	}
	return retorno;
}

int MostrarClientesConMasPendientes (eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos) {
	int retorno;
	eAuxiliar contador[tamClientes];
	int maximo;
	int flag;

	retorno = -1;

	if(listaClientes != NULL && tamClientes > 0 && listaPedidos != NULL && tamPedidos > 0) {

		retorno = 0;
		flag = 1;

		if (VerificarArrayCargadoEmpresa(listaClientes, tamClientes) && VerificarArrayCargadoPedidos(listaPedidos, tamPedidos, PENDIENTE)) {
			for (int i = 0; i < tamClientes; i++) {
				if (!listaClientes[i].isEmpty) {
					contador[i].contador = 0;
					contador[i].idAuxiliar = listaClientes[i].idEmpresa;
				}
			}

			for(int i = 0; i < tamClientes; i++) {
				if (!listaClientes[i].isEmpty) {
					for (int j = 0; j < tamPedidos; j++) {
						if (listaPedidos[j].isEmpty == PENDIENTE && listaPedidos[j].idCliente == contador[i].idAuxiliar) {
							contador[i].contador++;
						}
					}
				}
			}

			for (int i = 0; i < tamClientes; i++) {
				if (!listaClientes[i].isEmpty && (contador[i].contador > maximo || flag)) {
					maximo = contador[i].contador;
					flag = 0;
				}
			}

			printf("El/los clientes con más pedidos pendientes es/son: \n");
			for (int i = 0; i < tamClientes; i++) {
				if (!listaClientes[i].isEmpty && contador[i].contador == maximo) {
					printf("%s\n", listaClientes[i].nombreEmpresa);
				}
			}

		} else if (!VerificarArrayCargadoEmpresa(listaClientes, tamClientes)) {
			printf("No hay clientes existentes para contar.\n");
		} else {
			printf("No hay pedidos pendientes para contar.\n");
		}
	}
	return retorno;
}

int MostrarMenuPrincipal (eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidades,
		int *contadorIDClientes, int *contadorIDPedidos, int *contadorIDLocalidades) {
	int retorno;
	int opcionMenuPrincipal;

	retorno = -1;

	if (listaClientes != NULL && tamClientes > 0 && listaPedidos != NULL && tamPedidos > 0 && listaLocalidades != NULL && tamLocalidades > 0) {

		do{
			printf("-------------------------------------------------\n");
			printf("[1] Alta de cliente\n"
					"[2] Modificar datos de cliente\n"
					"[3] Baja de cliente\n"
					"[4] Crear pedido de recolección\n"
					"[5] Procesar residuos\n"
					"[6] Imprimir clientes\n"
					"[7] Imprimir pedidos pendientes\n"
					"[8] Imprimir pedidos procesados\n"
					"[9] Pedidos pendientes por localidad\n"
					"[10] Promedio de PP reciclado por cliente\n"
					"[11] SubMenu localidad\n"
					"[12] Ver cliente(s) con más pedidos pendientes\n"
					"[13] Ver cliente(s) con más pedidos completados\n"
					"[0] Salir del sistema\n");
			printf("-------------------------------------------------\n");
			opcionMenuPrincipal = PedirInt("Ingrese qué desea hacer: ");
			printf("-------------------------------------------------\n");

			switch(opcionMenuPrincipal) {
				case 0:
					printf("Suerte en el parcial Raffi del futuro! Atte. Raffi del pasado - 16/10/2021. ");
					break;

				case 1:
					AltaEmpresa(listaClientes, tamClientes, listaLocalidades, tamLocalidades, contadorIDClientes);
					break;

				case 2:
					EditEmpresa(listaClientes, tamClientes, listaLocalidades, tamLocalidades);
					break;

				case 3:
					BajaEmpresa(listaClientes, tamClientes, listaPedidos, tamPedidos, listaLocalidades, tamLocalidades);
					break;

				case 4:
					CrearPedido(listaPedidos, tamPedidos, listaClientes, tamClientes, listaLocalidades, tamLocalidades, contadorIDPedidos);
					break;

				case 5:
					ProcesarPedidoPendiente(listaPedidos, tamPedidos, listaClientes, tamClientes);
					break;

				case 6:
					PrintClientesConCantidadDePendientes(listaClientes, tamClientes, listaPedidos, tamPedidos, listaLocalidades, tamLocalidades);
					break;

				case 7:
					PrintPedidosConCriterio(listaPedidos, tamPedidos, listaClientes, tamClientes, PENDIENTE);
					break;

				case 8:
					PrintPedidosConCriterio(listaPedidos, tamPedidos, listaClientes, tamClientes, COMPLETADO);
					break;

				case 9:
					PrintLocalidadConCantidadPedidosPendientes(listaLocalidades, tamLocalidades, listaPedidos, tamPedidos, listaClientes, tamClientes);
					break;

				case 10:
					InformarPromedioDePPReciclado(listaPedidos, tamPedidos, listaClientes, tamClientes);
					break;

				case 11:
					//AltaLocalidad(listaLocalidades, tamLocalidades, contadorIDLocalidades);
					MostrarSubMenuLocalidad(listaLocalidades, tamLocalidades, listaClientes, tamClientes, listaPedidos, tamPedidos, contadorIDLocalidades);
					break;

				case 12:
					MostrarClientesConMasPendientes(listaClientes, tamClientes, listaPedidos, tamPedidos);
					break;

				case 13:
					MostrarClientesConMasCompletados(listaClientes, tamClientes, listaPedidos, tamPedidos);
					break;

				default:
					printf("Opción inválida, elija nuevamente por favor.");
					break;
			}
		} while (opcionMenuPrincipal != 0);
	}

	return retorno;
}

void MostrarSubMenuLocalidad (eLocalidad listaLocalidad[], int tamLocalidad, eCliente listaEmpresa[], int tamEmpresa,
		ePedido listaPedido[], int tamPedido, int *idMainLocalidad) {

	char opcionSubMenuLocalidad;

		do{


		printf("-------------------------------------------------\n");
		printf("[A] Alta de localidad\n"
				"[B] Modificar datos de localidad\n"
				"[C] Baja de localidad\n"
				"[D] Mostrar lista de localidades\n"
				"[E] Volver al menú principal\n");
		printf("-------------------------------------------------\n");
		opcionSubMenuLocalidad = PedirCaracterSoloLetra("Ingrese opción: ");
		printf("-------------------------------------------------\n");

		switch (opcionSubMenuLocalidad) {
			case 'a':
				AltaLocalidad(listaLocalidad, tamLocalidad, idMainLocalidad);
				break;

			case 'b':
				EditLocalidad(listaLocalidad, tamLocalidad);
				break;

			case 'c':
				BajaLocalidad(listaLocalidad, tamLocalidad, listaEmpresa, tamEmpresa, listaPedido, tamPedido);
				break;

			case 'd':
				PrintListaLocalidades(listaLocalidad, tamLocalidad);
				break;

			case 'e':
				printf("Salida de submenú de localidades.\n");
				break;

			default:
				printf("Opción inválida, por favor ingrese una opción dentro del menú!\n");
				break;
		}
	} while (opcionSubMenuLocalidad != 'e');


}

int InformarPromedioDePPReciclado (ePedido listaPedido[], int tamPedido, eCliente listaEmpresa[], int tamEmpresa) {
	int retorno;
	float totalPPReciclado;
	int contadorClientes;
	float promedioPPReciclado;

	retorno = -1;

	if (listaPedido != NULL && tamPedido > 0 && listaEmpresa != NULL && tamEmpresa > 0) {
		retorno = 0;
		if (VerificarArrayCargadoPedidos(listaPedido, tamPedido, COMPLETADO)) {

			contadorClientes = ContarClientesQueProcesanPP(listaEmpresa, tamEmpresa, listaPedido, tamPedido);
			totalPPReciclado = CalcularTotalPolipropenoProcesado(listaPedido, tamPedido);

			promedioPPReciclado = totalPPReciclado / contadorClientes;

			printf("El promedio de polipropeno reciclado por clientes es de %.2f kgs.\n", promedioPPReciclado);

		} else {
			printf("No existen pedidos completados para realizar el cálculo.\n");
		}
	}

	return retorno;
}

int ContarClientesQueProcesanPP (eCliente listaEmpresa[], int tamEmpresa, ePedido listaPedido[], int tamPedido) {

	int contadorClientes;

	contadorClientes = 0;

	for (int i = 0; i < tamEmpresa; i++) {
		if (!listaEmpresa[i].isEmpty) {
			for (int j = 0; j < tamPedido; j++) {
				if (listaPedido[j].isEmpty == COMPLETADO && listaEmpresa[i].idEmpresa == listaPedido[j].idCliente && listaPedido[j].kilosPP > 0) {
					contadorClientes++;
					break;
				}
			}
		}
	}

	return contadorClientes;

}

int PrintLocalidadConCantidadPedidosPendientes (eLocalidad listaLocalidad[], int tamLocalidad, ePedido listaPedido[], int tamPedido, eCliente listaEmpresa[], int tamEmpresa) {
	int retorno;
	int contadorLocalidades;
	int localidadAContar;
	int contadorPedidos;

	retorno = -1;

	if (listaEmpresa != NULL && tamEmpresa > 0 && listaPedido != NULL && tamPedido > 0 && listaLocalidad != NULL && tamLocalidad) {
		retorno = 0;
		if (VerificarArrayCargadoPedidos(listaPedido, tamPedido, PENDIENTE)) {

			PrintListaLocalidadesConPosicion(listaLocalidad, tamLocalidad, &contadorLocalidades);

			if (PedirIntConRangoConReintentos("Seleccione una localidad: ", &localidadAContar, 1, contadorLocalidades, 3)) {

				contadorPedidos = ContarPedidosPendientesPorLocalidad(listaLocalidad[localidadAContar-1], listaPedido, tamPedido, listaEmpresa, tamEmpresa);

				if (contadorPedidos > 0) {
					printf("En la localidad de %s hay %d pedido(s) pendiente(s).\n", listaLocalidad[localidadAContar-1].descripcion, contadorPedidos);
				} else {
					printf("No hay pedidos pendientes en la localidad de %s.\n", listaLocalidad[localidadAContar-1].descripcion);
				}

			} else {
				printf("Error en ingreso de datos.\n");
			}

		} else {
			printf("No hay pedidos pendientes en ninguna localidad.\n");
		}
	}


	return retorno;
}

int ContarPedidosPendientesPorLocalidad (eLocalidad localidad, ePedido listaPedido[], int tamPedido, eCliente listaEmpresa[], int tamEmpresa) {
	int contadorPedidos;

	contadorPedidos = 0;

	for (int i = 0; i < tamEmpresa; i++) {
		if (!listaEmpresa[i].isEmpty  && listaEmpresa[i].idLocalidad == localidad.idLocalidad) {
			for (int j = 0; j < tamPedido; j++) {
				if (listaPedido[j].isEmpty == PENDIENTE && listaPedido[j].idCliente == listaEmpresa[i].idEmpresa) {
					contadorPedidos++;
				}
			}
		}
	}

	return contadorPedidos;
}

int PrintClientesConCantidadDePendientes(eCliente listaEmpresa[], int tamEmpresa, ePedido listaPedido[], int tamPedido, eLocalidad listaLocalidad[], int tamLocalidad) {
	int retorno;

	retorno = -1;

	if (listaEmpresa != NULL && tamEmpresa > 0 && listaPedido != NULL && tamPedido > 0 && listaLocalidad != NULL && tamLocalidad) {
		retorno = 0;

		if (VerificarArrayCargadoEmpresa(listaEmpresa, tamEmpresa)) {

			printf("----------------------------------------------------------------------------------------------------------------------------\n");
			printf("ID\tNombre Empresa\t\t\tCUIT\t\tDireccion\t\tLocalidad\t\tCant. pedidos pendientes\n");
			for (int i = 0; i < tamEmpresa; i++) {
				if (!listaEmpresa[i].isEmpty) {
					PrintClienteIndividualConCantidadDePendientes(listaEmpresa[i], listaPedido, tamPedido, listaLocalidad, tamLocalidad);
				}
			}

			printf("----------------------------------------------------------------------------------------------------------------------------\n");
		} else {
			printf("No hay empresas cargadas");
		}
	}

	return retorno;
}

void PrintClienteIndividualConCantidadDePendientes (eCliente empresa, ePedido listaPedido[], int tamPedido, eLocalidad listaLocalidad[], int tamLocalidad) {

	for (int i = 0; i < tamLocalidad; i++) {
		if (empresa.idLocalidad == listaLocalidad[i].idLocalidad) {
			printf("----------------------------------------------------------------------------------------------------------------------------\n");
			printf("%-7d %-31s %-15s %-23s %-23s %d\n", empresa.idEmpresa, empresa.nombreEmpresa, empresa.cuit, empresa.direccion, listaLocalidad[i].descripcion, ContarCantidadPedidosPendientesDeCliente(empresa, listaPedido, tamPedido));
			break;
		}
	}
}

int ContarCantidadPedidosPendientesDeCliente(eCliente cliente, ePedido listaPedido[], int tamPedido) {

	int cantidadPedidosPorCliente;

	cantidadPedidosPorCliente = 0;

	for (int i = 0; i < tamPedido; i++) {
		if (listaPedido[i].isEmpty == PENDIENTE && cliente.idEmpresa == listaPedido[i].idCliente) {
			cantidadPedidosPorCliente++;
		}
	}

	return cantidadPedidosPorCliente;
}

int BajaEmpresa(eCliente listaEmpresa[], int tamEmpresa, ePedido listaPedido[], int tamPedido, eLocalidad listaLocalidad[], int tamLocalidad) {

	int retorno;
	int idABorrar;
	int posicionABorrar;
	int cantidadPedidosDeEmpresa;
	char confirmacion;

	retorno = -1;

	if (listaEmpresa != NULL && tamEmpresa > 0) {
		retorno = 0;
		if (VerificarArrayCargadoEmpresa(listaEmpresa, tamEmpresa)) {
			idABorrar = PedirInt("Ingrese el ID de la empresa a dar de baja: ");
			posicionABorrar = FindEmpresaById(listaEmpresa, tamEmpresa, idABorrar);

			if (posicionABorrar != -1) {
				printf("Cliente a borrar: \n");
				printf("------------------------------------------------------------------------------------------------\n");
				printf("ID\tNombre Empresa\t\t\tCUIT\t\tDireccion\t\tLocalidad\n");
				PrintEmpresaIndividual(listaEmpresa[posicionABorrar], listaLocalidad, tamLocalidad);
				printf("------------------------------------------------------------------------------------------------\n");
				cantidadPedidosDeEmpresa = ContarCantidadPedidosPendientesDeCliente(listaEmpresa[posicionABorrar], listaPedido, tamPedido);
				if (cantidadPedidosDeEmpresa > 0) {
					printf("-------------------------------------------------------\n");
					printf("ATENCIÓN!! La empresa posee %d pedido(s) sin finalizar!\n", cantidadPedidosDeEmpresa);
					printf("-------------------------------------------------------\n");
				}
				confirmacion = tolower(PedirCaracterSiONo("Está seguro que desea borrar esta empresa? \n[S] Si\n[N] No\nRespuesta: "));

				if (confirmacion == 's') {
					RemoveEmpresa(listaEmpresa, tamEmpresa, idABorrar);
					if (cantidadPedidosDeEmpresa > 0) {
						BajaPedidosDeEmpresa(listaEmpresa[posicionABorrar], listaPedido, tamPedido);
					}
					printf("El cliente se ha eliminado exitosamente.\n");
				} else {
					printf("Eliminación cancelada.\n");
				}
			} else { // ELSE POSICION A BORRAR =! -1
				printf("No existe un empleado con ese ID.\n");
			}
		} else { // ELSE VERIF. EXISTENCIA EMPLEADOS
			printf("No existen empleados para borrar.\n");
		}
	}

	return retorno;
}

int BajaPedidosDeEmpresa (eCliente empresa, ePedido listaPedido[], int tamPedido) {
	int retorno;

	retorno = -1;

	if (listaPedido != NULL && tamPedido > 0) {
		retorno = 0;

		for (int i = 0; i < tamPedido; i++) {
			if (empresa.idEmpresa == listaPedido[i].idCliente) {
				listaPedido[i].isEmpty = VACIO;
				//RemovePedido(listaPedido, tamPedido, listaPedido[i].idPedido);
			}
		}
	}

	return retorno;
}

int BajaLocalidad (eLocalidad listaLocalidad[], int tamLocalidad, eCliente listaEmpresa[], int tamEmpresa, ePedido listaPedido[], int tamPedido) {
	int retorno;
	int idABorrar;
	int posicionABorrar;
	int cantidadEmpresasEnLocalidad;
	char confirmacion;

	retorno = -1;

	if (listaLocalidad != NULL && tamLocalidad > 0 && listaEmpresa != NULL && tamEmpresa > 0 && listaPedido != NULL && tamPedido > 0) {
		retorno = 0;

		if (VerificarArrayCargadoLocalidades(listaLocalidad, tamLocalidad)) {
			PrintListaLocalidades(listaLocalidad, tamLocalidad);

			idABorrar = PedirInt("Ingrese el ID de la localidad a borrar: ");
			posicionABorrar = FindLocalidadById(listaLocalidad, tamLocalidad, idABorrar);

			if (posicionABorrar != -1) {
				printf("Localidad a borrar: %s\n", listaLocalidad[posicionABorrar].descripcion);
				cantidadEmpresasEnLocalidad = ContarCantidadClientesEnLocalidad(listaLocalidad[posicionABorrar], listaLocalidad, tamEmpresa);

				if (cantidadEmpresasEnLocalidad > 0) {
					printf("-------------------------------------------------------\n");
					printf("ATENCIÓN!! En esta localidad se encuentran %d clientes!\n", cantidadEmpresasEnLocalidad);
					printf("-------------------------------------------------------\n");
				}

				confirmacion = tolower(PedirCaracterSiONo("Está seguro que desea borrar esta localidad? \n[S] Si\n[N] No\nRespuesta: "));
				if (confirmacion == 's') {
					RemoveLocalidad(listaLocalidad, tamLocalidad, idABorrar);
					if (cantidadEmpresasEnLocalidad > 0) {
						BorrarClientesEnLocalidad(listaLocalidad[posicionABorrar], listaEmpresa, tamEmpresa, listaPedido, tamPedido);
					}
				} else {
					printf("Baja de localidad cancelada.\n");
				}
			} else {
				printf("No existe una localidad con ese ID.\n");
			}
		} else {
			printf("No existen localidades para borrar.\n");
		}
	}


	return retorno;
}

int ContarCantidadClientesEnLocalidad(eLocalidad localidad, eLocalidad listaEmpresa[], int tamEmpresa) {

	int cantidadClientesEnLocalidad;

	cantidadClientesEnLocalidad = 0;

	for (int i = 0; i < tamEmpresa; i++) {
		if (!listaEmpresa[i].isEmpty && localidad.idLocalidad == listaEmpresa[i].idLocalidad) {
			cantidadClientesEnLocalidad++;
		}
	}

	return cantidadClientesEnLocalidad;
}

int BorrarClientesEnLocalidad (eLocalidad localidad, eCliente listaEmpresa[], int tamEmpresa, ePedido listaPedido[], int tamPedido) {
	int retorno;

	retorno = -1;

	if (listaEmpresa != NULL && tamEmpresa > 0 && listaPedido != NULL && tamPedido > 0) {
		retorno = 0;

		for (int i = 0; i < tamEmpresa; i++) {
			if (!listaEmpresa[i].isEmpty && listaEmpresa[i].idLocalidad == localidad.idLocalidad) {
				BajaPedidosDeEmpresa(listaEmpresa[i], listaPedido, tamPedido);
				listaEmpresa[i].isEmpty = TRUE;
			}
		}

	}

	return retorno;

}
