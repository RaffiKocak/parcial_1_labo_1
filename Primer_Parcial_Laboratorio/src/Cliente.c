/*
 * Cliente.c
 *
 *  Created on: 11 oct 2021
 *      Author: Raffi
 */

#include "Cliente.h"

int ModeloFuncionGenerica(eCliente list[], int len, int totalSalarios) {
	int retorno;

	retorno = -1;

	if (list != NULL && len > 0) {

	}

	return retorno;
}

int InitCliente(eCliente list[], int len) {
	int retorno;

	retorno = -1;

	if (list != NULL && len > 0) {
		retorno = 0;
		for(int i=0; i<len; i++){
	        list[i].isEmpty = TRUE;
	    }
	}

	return retorno;
}

int AddEmpresa(eCliente listaEmpresa[], int tamEmpresa, int id, char nombreEmpresa[], char cuit[], char direccion[], int localidad) {

	int posicionAGuardar;

	posicionAGuardar = BuscarEspacioLibreEmpresa(listaEmpresa, tamEmpresa);

	if(listaEmpresa != NULL && tamEmpresa > 0 && posicionAGuardar != -1) {
		listaEmpresa[posicionAGuardar].idEmpresa = id;
		strncpy(listaEmpresa[posicionAGuardar].nombreEmpresa, nombreEmpresa, sizeof(listaEmpresa[posicionAGuardar].nombreEmpresa));
		strncpy(listaEmpresa[posicionAGuardar].cuit, cuit, sizeof(listaEmpresa[posicionAGuardar].cuit));
		strncpy(listaEmpresa[posicionAGuardar].direccion, direccion, sizeof(listaEmpresa[posicionAGuardar].direccion));
		listaEmpresa[posicionAGuardar].idLocalidad = localidad;
		listaEmpresa[posicionAGuardar].isEmpty = FALSE;

		printf("\nEmpresa cargada exitosamente.\n");
	}

	return posicionAGuardar;
}

int AltaEmpresa (eCliente listaEmpresa[], int tamEmpresa, eLocalidad listaLocalidad[], int tamLocalidad, int *contadorIdMain) {
	int retorno;
	int posicionLibre;
	char nombreEmpresa[51];
	char cuit[12];
	char direccion[51];
	int localidad;
	int verificacionLocalidades;
	int contadorLocalidades;

	retorno = -1;

	if(listaEmpresa != NULL && tamEmpresa > 0 && listaLocalidad != NULL && tamLocalidad > 0) {
		retorno = 0;
		verificacionLocalidades = VerificarArrayCargadoLocalidades(listaLocalidad, tamLocalidad);
		posicionLibre = BuscarEspacioLibreEmpresa(listaEmpresa, tamEmpresa);

		if (posicionLibre != -1 && verificacionLocalidades) {
			if (PedirCadenaProlijaConReintentos("Ingrese el nombre de la empresa: ", nombreEmpresa, sizeof(nombreEmpresa), 3) &&
					PedirCUITConReintentos("Ingrese el cuit de la empresa: ", cuit, sizeof(cuit), 3) &&
					PedirCadenaProlijaConReintentos("Ingrese la dirección de la empresa: ", direccion, sizeof(direccion), 3)) {

				PrintListaLocalidadesConPosicion(listaLocalidad, tamLocalidad, &contadorLocalidades);

				if (PedirIntConRangoConReintentos("Ingrese la localidad de la empresa: ", &localidad, 1, contadorLocalidades, 3)) {
					localidad = listaLocalidad[localidad-1].idLocalidad;
					AddEmpresa(listaEmpresa, tamEmpresa, *contadorIdMain, nombreEmpresa, cuit, direccion, localidad);
					*contadorIdMain += 1;

					printf("------------------------------------------------------------------------------------------------\n");
					printf("ID\tNombre Empresa\t\t\tCUIT\t\tDireccion\t\tLocalidad\n");
					PrintEmpresaIndividual(listaEmpresa[posicionLibre], listaLocalidad, tamLocalidad);
					printf("------------------------------------------------------------------------------------------------\n");
				} else { // else localidad mal ingresada
					printf("Error en ingreso de datos.\n");
				}
			} else { // else nombre/cuit/dir mal ingresados
				printf("Error en ingreso de datos.\n");
			}
		} else if (!verificacionLocalidades) {
				printf("No hay localidades cargadas en la lista. No pueden existir empresas sin localidades.\n");
		} else {
			printf("La lista de clientes está llena.\n");
		}
	}

	return retorno;
}

int RemoveEmpresa(eCliente lista[], int tam, int id) {

	int retorno;

	retorno = -1;

	if (lista != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (!lista[i].isEmpty && (id == lista[i].idEmpresa)) {
				lista[i].isEmpty = TRUE;
				retorno = 0;
			}
		}
	}
	return retorno;
}

int EditEmpresa(eCliente listaEmpresa[], int tamEmpresa, eLocalidad listaLocalidad[], int tamLocalidad) {
	int retorno;
	int idABuscar;
	int posicionAEditar;

	retorno = -1;

	if (listaEmpresa != NULL && tamEmpresa > 0 && listaLocalidad != NULL && tamLocalidad > 0) {
		retorno = 0;
		if (VerificarArrayCargadoEmpresa(listaEmpresa, tamEmpresa)) {
			if (PedirIntConReintentos("Ingrese el ID de la empresa a modificar: ", &idABuscar, 3)) {

				posicionAEditar = FindEmpresaById(listaEmpresa, tamEmpresa, idABuscar);

				if (posicionAEditar != -1) {
					MostrarSubMenuEditEmpresa(listaEmpresa, tamEmpresa, listaLocalidad, tamLocalidad, posicionAEditar);
					printf("------------------------------------------------------------------------------------------------\n");
					printf("ID\tNombre Empresa\t\t\tCUIT\t\tDireccion\t\tLocalidad\n");
					PrintEmpresaIndividual(listaEmpresa[posicionAEditar], listaLocalidad, tamLocalidad);
					printf("------------------------------------------------------------------------------------------------\n");
				} else { // else id empresa no existe
					printf("No existe una empresa con ese ID");
				}
			} else { // else pedir id
				printf("Error en carga de datos, regresando al menú principal...\n");
			}
		} else { // else array vacio
			printf("No existen empresas para modificar.\n");
		}
	}

	return retorno;
}

int MostrarSubMenuEditEmpresa(eCliente listaEmpresa[], int tamEmpresa, eLocalidad listaLocalidad[], int tamLocalidad, int posicionAEditar) {
	int retorno;
	char opcionMenuEditar;
	char confirmacion;
	int contadorLocalidades;
	eCliente auxCliente;

	retorno = -1;

	if (listaEmpresa != NULL && tamEmpresa > 0 && listaLocalidad != NULL && tamLocalidad > 0) {

		printf("------------------------------------------------------------------------------------------------\n");
		printf("ID\tNombre Empresa\t\t\tCUIT\t\tDireccion\t\tLocalidad\n");
		PrintEmpresaIndividual(listaEmpresa[posicionAEditar], listaLocalidad, tamLocalidad);
		printf("------------------------------------------------------------------------------------------------\n");

		do {
			auxCliente = listaEmpresa[posicionAEditar];
			printf("-----------------------------\n"
					"Modificar Empresa\n"
					"-----------------------------\n"
					"[A] Modificar dirección\n"
					"[B] Modificar localidad\n"
					"[C] Volver al menú principal\n");
			opcionMenuEditar = tolower(PedirCaracterSoloLetra("Ingrese una opción para modificar: "));

			switch(opcionMenuEditar) {
				case 'a':
					printf("Dirección actual: %s\n", auxCliente.direccion);
					if (PedirCadenaProlijaConReintentos("Ingrese nueva dirección de la empresa: ", auxCliente.direccion, sizeof(auxCliente.direccion), 3)) {
						printf("Dirección sin modificar: %s\n", listaEmpresa[posicionAEditar].direccion);
						printf("Nueva dirección modificada: %s\n", auxCliente.direccion);
						confirmacion = tolower(PedirCaracterSiONo("Está seguro de realizar la modificación?\n[S] Sí\n[N] No\n"));
						if (confirmacion == 's') {
							listaEmpresa[posicionAEditar] = auxCliente;
							printf("Modificación exitosa.\n");
						} else {
							printf("Modificación cancelada.\n");
						}
					} else {
						printf("Error en ingreso de datos. Modificación cancelada.\n");
					}
					break;

				case 'b':
					contadorLocalidades = 0;
					PrintLocalidadDeUnCliente(auxCliente.idLocalidad, listaLocalidad, tamLocalidad, "Localidad actual: ");
					PrintListaLocalidadesConPosicion(listaLocalidad, tamLocalidad, &contadorLocalidades);
					if (PedirIntConRangoConReintentos("Ingrese la nueva localidad de la empresa: ", &auxCliente.idLocalidad, 1, contadorLocalidades, 3)) {
						printf("Localidad sin modificar: ");
						PrintLocalidadDeUnCliente(listaEmpresa[posicionAEditar].idLocalidad, listaLocalidad, tamLocalidad, "Localidad sin modificar: ");
						PrintLocalidadDeUnCliente(auxCliente.idLocalidad, listaLocalidad, tamLocalidad, "Nueva localidad modificada: ");
						confirmacion = tolower(PedirCaracterSiONo("Está seguro de realizar la modificación?\n[S] Sí\n[N] No\n"));
						if (confirmacion == 's') {
							listaEmpresa[posicionAEditar] = auxCliente;
							printf("Modificación exitosa.\n");
						} else {
							printf("Modificación cancelada.\n");
						}
					} else {
						printf("Error en ingreso de datos. Modificación cancelada.\n");
					}
					break;

				case 'c':
					printf("Edición de datos finalizada.\n");
					break;

				default:
					printf("Opción inválida. Ingrese una opción del menú por favor.\n");
					break;
			}

		} while (opcionMenuEditar != 'c');
	}

	return retorno;

}

int PrintEmpresas(eCliente listEmpresa[], int tamEmpresa, eLocalidad listaLocalidad[], int tamLocalidad) {
	int retorno;

	retorno = -1;

	if (listEmpresa != NULL && tamEmpresa > 0) {
		retorno = 0;
		if (VerificarArrayCargadoEmpresa(listEmpresa, tamEmpresa)) {
			printf("------------------------------------------------------------------------------------------------\n");
			printf("ID\tNombre Empresa\t\t\tCUIT\t\tDireccion\t\tLocalidad\n");
			for (int i = 0; i < tamEmpresa; i++) {
				if (!listEmpresa[i].isEmpty) {
					PrintEmpresaIndividual(listEmpresa[i], listaLocalidad, tamLocalidad);
				}
			}
			printf("------------------------------------------------------------------------------------------------\n");
		} else {
			printf("No hay clientes cargados.\n");
		}
	}

	return retorno;
}

void PrintEmpresaIndividual(eCliente empresa, eLocalidad listaLocalidad[], int tamLocalidad) {
	//printf("------------------------------------------------------------------------------------------------\n");
	//printf("%-7d %-31s %-15s %-23s %d\n", empresa.idEmpresa, empresa.nombreEmpresa, empresa.cuit, empresa.direccion, empresa.idLocalidad);
	for (int i = 0; i < tamLocalidad; i++) {
		if (empresa.idLocalidad == listaLocalidad[i].idLocalidad) {
			printf("------------------------------------------------------------------------------------------------\n");
			printf("%-7d %-31s %-15s %-23s %s\n", empresa.idEmpresa, empresa.nombreEmpresa, empresa.cuit, empresa.direccion, listaLocalidad[i].descripcion);
			break;
		}
	}
}

void PrintLocalidadDeUnCliente (int idLocalidad, eLocalidad listaLocalidad[], int tamLocalidad, char mensaje[]) {
	for (int i = 0; i < tamLocalidad; i++) {
		if (idLocalidad == listaLocalidad[i].idLocalidad) {
			printf("%s%s\n", mensaje, listaLocalidad[i].descripcion);
			break;
		}
	}
}

int FindEmpresaById(eCliente lista[], int tam, int id) {

	int posicion;

	posicion = -1;

	if (lista != NULL && tam > 0) {
		for(int i = 0; i < tam; i++) {
			if(lista[i].idEmpresa == id && !lista[i].isEmpty) {
				posicion = i;
				break;
			}
		}
	}

	return posicion;
}

int BuscarEspacioLibreEmpresa (eCliente lista[], int tam) {
	int posicionLibre;

	posicionLibre = -1;

	for (int i = 0; i < tam; i++) {
		if (lista[i].isEmpty) {
			posicionLibre = i;
			break;
		}
	}
	return posicionLibre;
}

int VerificarArrayCargadoEmpresa(eCliente lista[], int tam) {
	int estaCargado;

	estaCargado = 0;

	if (lista != NULL && tam > 0) {
		for(int i=0 ; i < tam ; i++) {
			if(!lista[i].isEmpty) {
				estaCargado = 1;
				break;
			}
		}
	}
	return estaCargado;
}

void HardcodearEmpresa (eCliente lista[]) {

	eCliente hardcode[] = {
	    {10, "Worklift S.A.", "33709896429", "Maure 3410", 1, 0},
	    {11, "Asesoramiento Biacco S.R.L.", "33716020986", "Piedras 666", 2, 0},
		{12, "Trenes Argentinos", "33123456789", "Gral. Hornos 11", 2, 0},
	    {13, "Techint", "33321654987", "Calle Falsa 123", 3, 0},
	    {14, "CLIENTE HARDCODEADO VACIO", "11111111111", "", 1, 1}
	};

	for (int i = 0; i < 5; ++i) {
		lista[i] = hardcode[i];
	}
}

