/*
 * Pedido.c
 *
 *  Created on: 11 oct 2021
 *      Author: Raffi
 */

#include "Pedido.h"

int InitPedido(ePedido lista[], int tam) {
	int retorno;

	retorno = -1;

	if (lista != NULL && tam > 0) {
		retorno = 0;
		for(int i=0; i<tam; i++){
	        lista[i].isEmpty = VACIO;
	        lista[i].kilosHDPE = 0;
	        lista[i].kilosLDPE = 0;
	        lista[i].kilosPP = 0;
	    }
	}

	return retorno;
}

int AddPedido(ePedido lista[], int tam, int id, float kilosTotales, int idCliente) {
	int posicionAGuardar;

	posicionAGuardar = BuscarEspacioLibrePedido(lista, tam);

	if (lista != NULL && tam > 0) {
		lista[posicionAGuardar].idPedido = id;
		lista[posicionAGuardar].kilosTotales = kilosTotales;
		lista[posicionAGuardar].kilosHDPE = 0;
		lista[posicionAGuardar].kilosLDPE = 0;
		lista[posicionAGuardar].kilosPP = 0;
		lista[posicionAGuardar].idCliente = idCliente;
		lista[posicionAGuardar].isEmpty = -1;

		printf("Pedido generado exitosamente.\n");
	}

	return posicionAGuardar;
}

int RemovePedido(ePedido lista[], int tam, int id) {
	int retorno;

	retorno = -1;

	if (lista != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (!lista[id].isEmpty && id == lista[i].idPedido) {
				lista[id].isEmpty = VACIO;
				retorno = 0;
			}
		}
	}

	return retorno;
}

int CrearPedido (ePedido listaPedido[], int tamPedido, eCliente listaEmpresa[], int tamEmpresa, eLocalidad listaLocalidad[], int tamLocalidad, int *contadorIdPedidosMain) {
	int retorno;
	int verificacionClientes;
	int posicionLibre;
	int idCliente;
	float kilosTotales;

	retorno = -1;

	if (listaPedido != NULL && tamPedido > 0 && listaEmpresa != NULL && tamEmpresa > 0 && listaLocalidad != NULL && tamLocalidad > 0) {
		retorno = 0;
		verificacionClientes = VerificarArrayCargadoEmpresa(listaEmpresa, tamEmpresa);
		posicionLibre = BuscarEspacioLibrePedido(listaPedido, tamPedido);

		if (verificacionClientes && posicionLibre != -1) {

			PrintEmpresas(listaEmpresa, tamEmpresa, listaLocalidad, tamLocalidad);

			if (PedirIntConRangoConReintentos("\nIngrese el ID de la empresa correspondiente a este pedido: ", &idCliente, 1, 20000000, 3)) {
				if (FindEmpresaById(listaEmpresa, tamEmpresa, idCliente) != -1) {

					if (PedirFloatConRangoConReintentos("Ingrese la cantidad total de kgs de basura a procesar (25 a 1000 kgs): ", &kilosTotales, 25, 1000, 3)) {

						AddPedido(listaPedido, tamPedido, *contadorIdPedidosMain, kilosTotales, idCliente);
						*contadorIdPedidosMain += 1;
					} else {
						printf("Error en ingreso de datos.\n");
					}
				} else {
					printf("El ID ingresado no existe en ninguna empresa.\n");
				}
			} else {
				printf("Error en ingreso de datos.\n");
			}
		} else if (!verificacionClientes){
			printf("No existen empresas para asignarles un pedido.\n");
		} else {
			printf("No hay posiciones disponibles en la lista para cargar este pedido.\n");
		}
	}
	return retorno;
}

int ProcesarPedidoPendiente(ePedido listaPedido[], int tamPedido, eCliente listaEmpresa[], int tamEmpresa) {
	int retorno;
	int idAProcesar;
	int posicionPedidoAProcesar;
	char opcionSeleccionada;
	char confirmacion;
	char confirmacionSalida;
	ePedido auxPedido;

	retorno = -1;

	if(listaPedido != NULL && tamPedido > 0 && listaEmpresa != NULL && tamEmpresa > 0) {
		retorno = 0;
		if (VerificarArrayCargadoPedidos(listaPedido, tamPedido, PENDIENTE)) {

			PrintPedidosConCriterio(listaPedido, tamPedido, listaEmpresa, tamEmpresa, PENDIENTE);

			if (PedirIntConReintentos("Ingrese el ID del pedido a procesar: ", &idAProcesar, 3)) {

				posicionPedidoAProcesar = FindPedidoByID(listaPedido, tamPedido, idAProcesar, PENDIENTE);

				if (posicionPedidoAProcesar != -1) {

					printf("----------------------------------------------------------------------------------------------------\n");
					printf("ID Pedido\tCUIT cliente\t\tDirección cliente\t\tCantidad kgs. a recolectar\n");
					PrintPedidoIndividualConCriterio(listaPedido[posicionPedidoAProcesar], listaEmpresa, tamEmpresa, PENDIENTE);
					printf("----------------------------------------------------------------------------------------------------\n");
					confirmacion = tolower(PedirCaracterSiONo(
							"\nEstá seguro de procesar este pedido? Una vez finalizada la carga de kgs procesados,\nel pedido cambiará a 'COMPLETADO' al volver al menú principal.\n[S] Sí\n[N] No\n"));

					if (confirmacion == 's') {
						do {
							auxPedido = listaPedido[posicionPedidoAProcesar];
							printf("-----------------------------\n"
									"Procesar pedido pendiente \n"
									"-----------------------------\n"
									"Cantidad de kgs de basura sin procesar: %.2f\n"
									"-----------------------------\n"
									"[A] Procesar HDPE - Envases para lácteos, perfumes, detergentes líquidos, etc.\n"
									"[B] Procesar LDPE - Bolsas de congelación de alimentos, tapas flexibles o bolsas de basura\n"
									"[C] Procesar PP - Plásticos utilizados en la industria automovilística y en la construcción\n"
									"[D] Volver al menú principal\n", auxPedido.kilosTotales);
									opcionSeleccionada = tolower(PedirCaracterSoloLetra("Ingrese opción a realizar: "));

									switch (opcionSeleccionada) {
									case 'a':
										printf("Cantidad actual de kgs HDPE procesados: %.2f\n", auxPedido.kilosHDPE);
										if (PedirFloatConRangoConReintentos("Ingrese cantidad de kgs a procesar: ", &auxPedido.kilosHDPE, 0, auxPedido.kilosTotales, 3)) {
											printf("Cantidad de kgs a procesar: %.2f\n", auxPedido.kilosHDPE);
											confirmacion = tolower(PedirCaracterSiONo("Está seguro de realizar este proceso?\n[S] Sí\n[N] No\n"));
											if (confirmacion == 's') {
												listaPedido[posicionPedidoAProcesar] = auxPedido;
												listaPedido[posicionPedidoAProcesar].kilosTotales -= listaPedido[posicionPedidoAProcesar].kilosHDPE;
												printf("Proceso exitoso.\n");
											} else {
												printf("Proceso cancelado.\n");
											}
										} else {
											printf("Error en ingreso de datos. Proceso cancelado.\n");
										}
										break;

									case 'b':
										printf("Cantidad actual de kgs LDPE procesados: %.2f\n", auxPedido.kilosLDPE);
										if (PedirFloatConRangoConReintentos("Ingrese cantidad de kgs a procesar: ", &auxPedido.kilosLDPE, 0, auxPedido.kilosTotales, 3)) {
											printf("Cantidad de kgs a procesar: %.2f\n", auxPedido.kilosLDPE);
											confirmacion = tolower(PedirCaracterSiONo("Está seguro de realizar este proceso?\n[S] Sí\n[N] No\n"));
											if (confirmacion == 's') {
												listaPedido[posicionPedidoAProcesar] = auxPedido;
												listaPedido[posicionPedidoAProcesar].kilosTotales -= listaPedido[posicionPedidoAProcesar].kilosLDPE;
												printf("Proceso exitoso.\n");
											} else {
												printf("Proceso cancelado.\n");
											}
										} else {
											printf("Error en ingreso de datos. Proceso cancelado.\n");
										}
										break;

									case 'c':
										printf("Cantidad actual de kgs PP procesados: %.2f\n", auxPedido.kilosPP);
										if (PedirFloatConRangoConReintentos("Ingrese cantidad de kgs a procesar: ", &auxPedido.kilosPP, 0, auxPedido.kilosTotales, 3)) {
											printf("Cantidad de kgs a procesar: %.2f\n", auxPedido.kilosPP);
											confirmacion = tolower(PedirCaracterSiONo("Está seguro de realizar este proceso?\n[S] Sí\n[N] No\n"));
											if (confirmacion == 's') {
												listaPedido[posicionPedidoAProcesar] = auxPedido;
												listaPedido[posicionPedidoAProcesar].kilosTotales -= listaPedido[posicionPedidoAProcesar].kilosPP;
												printf("Proceso exitoso.\n");
											} else {
												printf("Proceso cancelado.\n");
											}
										} else {
											printf("Error en ingreso de datos. Proceso cancelado.\n");
										}
										break;

									case 'd':
										confirmacionSalida = tolower(PedirCaracterSiONo("Está seguro que desea terminar el proceso? Al confirmar, el proceso se considerará completado.\n[S] Sí\n[N] No\n"));
										break;

									default:
										printf("Opción no válida. Por favor ingrese una opción dentro del menú del proceso.\n");
										break;
									}
						} while (confirmacionSalida != 's');
						printf("Pedido procesado exitosamente.\n");
						listaPedido[posicionPedidoAProcesar].isEmpty = COMPLETADO;
					} else {
						printf("Proceso cancelado. Volviendo al menú principal...\n");
					}
				} else {
					printf("El ID ingresado no se encuentra en la lista de pedidos pendientes.\n");
				}
			} else {
				printf("Error en carga de ID.\n");
			}
		} else {
			printf("No hay pedidos pendientes para procesar.\n");
		}
	}

	return retorno;
}

int PrintPedidosConCriterio(ePedido listaPedido[], int tamPedido, eCliente listaEmpresa[], int tamEmpresa, int criterio) {
	int retorno;

	retorno = -1;

	if (listaPedido != NULL && tamPedido > 0 && listaEmpresa != NULL && tamEmpresa > 0) {
		if (criterio == PENDIENTE) {
			if (VerificarArrayCargadoPedidos(listaPedido, tamPedido, PENDIENTE)) {
				printf("----------------------------------------------------------------------------------------------------\n");
				printf("ID Pedido\tCUIT cliente\t\tDirección cliente\t\tCantidad kgs. a recolectar\n");
				for (int i = 0; i < tamPedido; i++) {
					PrintPedidoIndividualConCriterio(listaPedido[i], listaEmpresa, tamEmpresa, criterio);
				}
				printf("----------------------------------------------------------------------------------------------------\n");
			} else {
				printf("No hay pedidos pendientes para mostrar.\n");
			}
		} else {
			if (VerificarArrayCargadoPedidos(listaPedido, tamPedido, COMPLETADO)) {
				printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("ID Pedido\tCUIT cliente\t\tDirección cliente\t\tKgs. procesados HDPE\tKgs. procesados LDPE\tKgs. procesados PP\n");
				for(int i = 0; i < tamPedido; i++) {
					PrintPedidoIndividualConCriterio(listaPedido[i], listaEmpresa, tamEmpresa, criterio);
				}
				printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
			} else {
				printf("No hay pedidos completados para mostrar.\n");
			}
		}
	}
	return retorno;
}

void PrintPedidoIndividualConCriterio (ePedido pedido, eCliente listaEmpresa[], int tamEmpresa, int criterio) {


	if (criterio == PENDIENTE) {
		for (int i = 0; i < tamEmpresa; i++) {
			if (pedido.isEmpty == PENDIENTE && pedido.idCliente == listaEmpresa[i].idEmpresa) {
				printf("----------------------------------------------------------------------------------------------------\n");
				printf("%-15d %-23s %-31s %.2f\n", pedido.idPedido, listaEmpresa[i].cuit, listaEmpresa[i].direccion, pedido.kilosTotales);
				break;
			}
		}
	} else {
		for (int i = 0; i < tamEmpresa; i++) {
			if (pedido.isEmpty == COMPLETADO && pedido.idCliente == listaEmpresa[i].idEmpresa) {
				printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("%-15d %-23s %-31s %-23.2f %-23.2f %.2f\n", pedido.idPedido, listaEmpresa[i].cuit, listaEmpresa[i].direccion, pedido.kilosHDPE, pedido.kilosLDPE, pedido.kilosPP);
				break;
			}
		}

	}
}

float CalcularTotalPolipropenoProcesado (ePedido lista[], int tam) {

	float totalPP;

	totalPP = 0;

	for (int i = 0; i < tam; i++) {
		if (lista[i].isEmpty == COMPLETADO) {
			totalPP += lista[i].kilosPP;
		}
	}

	return totalPP;
}

int FindPedidoByID(ePedido lista[], int tam, int id, int estadoABuscar) {
	int posicion;

	posicion = -1;

		for (int i = 0; i < tam; i++) {
			if (lista[i].idPedido == id && lista[i].isEmpty == estadoABuscar) {
				posicion = i;
			}
		}

	return posicion;
}

int BuscarEspacioLibrePedido (ePedido lista[], int tam) {
	int posicionLibre;

	posicionLibre = -1;

	for (int i = 0; i < tam; i++) {
		if (lista[i].isEmpty == VACIO) {
			posicionLibre = i;
			break;
		}
	}

	return posicionLibre;
}

int VerificarArrayCargadoPedidos(ePedido lista[], int tam, int criterio) {
	int hayPedidos;

	hayPedidos = 0;

	if (lista != NULL && tam > 0) {
		if (criterio == PENDIENTE) {
			for(int i=0 ; i < tam ; i++) {
				if(lista[i].isEmpty == -1) {
					hayPedidos = 1;
					break;
				}
			}
		} else if (criterio == COMPLETADO){
			for(int i=0 ; i < tam ; i++) {
				if(lista[i].isEmpty == 1) {
					hayPedidos = 1;
					break;
				}
			}
		} else {
			for(int i=0 ; i < tam ; i++) {
				if(lista[i].isEmpty != 0) {
					hayPedidos = 1;
					break;
				}
			}
		}
	}
	return hayPedidos;
}

void HardcodearPedidos (ePedido lista[]) {

	ePedido hardcode[] = {
	    {101, 100, 0, 0, 0, 10, -1},
	    {102, 150, 0, 0, 0, 12, -1},
	    {103, 75, 0, 0, 0, 12, -1},
		{104, 75, 0, 0, 0, 13, -1},
		{105, 25, 50, 50, 60, 10, 1},
		{106, 30, 70, 10, 10, 12, 1}
	};

	for (int i = 0; i < 6; ++i) {
		lista[i] = hardcode[i];
	}
}
