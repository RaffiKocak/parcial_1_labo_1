/*
 * Localidades.c
 *
 *  Created on: 13 oct 2021
 *      Author: Raffi
 */


#include "Localidad.h"

int InitLocalidad(eLocalidad lista[], int tam) {
	int retorno;

	retorno = -1;
	if (lista != NULL && tam > 0) {
		retorno = 0;
		for(int i=0; i<tam; i++){
			lista[i].isEmpty = TRUE;
	    }
	}
	return retorno;
}

int AddLocalidad(eLocalidad lista[], int tam, int id, char descripcion[]) {

	int posicion;

	posicion = BuscarEspacioLibreLocalidad(lista, tam);

	if(lista != NULL && tam > 0) {
		if (posicion != -1) {
			lista[posicion].idLocalidad = id;
			strncpy(lista[posicion].descripcion, descripcion, sizeof(lista[posicion].descripcion));
			lista[posicion].isEmpty = FALSE;
		}
	}

	return posicion;
}

int RemoveLocalidad(eLocalidad lista[], int tam, int id) {

	int retorno;

	retorno = -1;

	if (lista != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (!lista[i].isEmpty && (id == lista[i].idLocalidad)) {
				lista[i].isEmpty = TRUE;
				retorno = 0;
			}
		}
	}

	return retorno;
}

int AltaLocalidad(eLocalidad lista[], int tam, int *idMainLocalidad) {
	int posicion;
	char descripcion[51];

	posicion = BuscarEspacioLibreLocalidad(lista, tam);

	if (lista != NULL && tam > 0) {
		if (posicion != -1) {
			if(PedirCadenaProlijaConReintentos("Ingrese descripción de la nueva localidad: ", descripcion, sizeof(descripcion), 3)){
				AddLocalidad(lista, tam, *idMainLocalidad, descripcion);
				*idMainLocalidad += 1;
				printf("Localidad ingresada exitosamente.\n");
			} else {
				printf("Error en ingreso de datos.\n");
			}
		} else {
			printf("No hay espacio en la lista para agregar una nueva localidad.\n");
		}
	}
	return posicion;
}

int EditLocalidad(eLocalidad lista[], int tam) {
	int retorno;
	int idABuscar;
	int posicionAEditar;
	char confirmacion;
	eLocalidad auxLocalidad;

	retorno = -1;

	if (lista != NULL && tam > 0) {
		if (VerificarArrayCargadoLocalidades(lista, tam)) {
			if (PedirIntConReintentos("Ingrese el ID de la localidad a modificar: ", &idABuscar, 3)) {

				posicionAEditar = FindLocalidadById(lista, tam, idABuscar);

				if (posicionAEditar != -1) {
					auxLocalidad = lista[posicionAEditar];
					printf("----------------------------\n");
					printf("ID\tDescripcion\t\n");
					PrintLocalidadIndividual(lista[posicionAEditar]);

					if (PedirCadenaProlijaConReintentos("Ingrese el nuevo nombre de la localidad: ", auxLocalidad.descripcion, sizeof(auxLocalidad.descripcion), 3)) {
						confirmacion = tolower(PedirCaracterSiONo("Está seguro de realizar la modificación?\n[S] Sí\n[N] No\n"));
						if (confirmacion == 's') {
							auxLocalidad = lista[posicionAEditar];
						} else {
							printf("Modificación cancelada.\n");
						}
					} else {
						printf("Error en ingreso de datos. Modificación cancelada.\n");
					}
				} else {
					printf("No existe una localidad con ese ID.\n");
				}

			} else {
				printf("Error en carga de datos, regresando al menú principal...\n");
			}
		} else {
			printf("No existen localidades para modificar.\n");
		}
	}

	return retorno;
}

int SortLocalidadesPorEstado(eLocalidad lista[], int tam) {
	int retorno;
	eLocalidad aux;

	retorno = -1;

	if(lista != NULL && tam > 0) {
		retorno = 0;
		for (int i = 0; i < tam -1; i++) {
			for (int j = i+1; j < tam; j++) {
				if (lista[i].isEmpty && !lista[j].isEmpty) {
					aux = lista[i];
					lista[i] = lista[j];
					lista[j] = aux;
				}
			}
		}
	}
	return retorno;
}

int PrintListaLocalidadesConPosicion(eLocalidad lista[], int tam, int *contadorLocalidades) {

	int retorno;
	int contadorLocalLocalidades;

	retorno = -1;

	if (lista != NULL && tam > 0) {
		retorno = 0;
		contadorLocalLocalidades = 0;

		if (VerificarArrayCargadoLocalidades(lista, tam)) {
			SortLocalidadesPorEstado(lista, tam);
				printf("----------------------------\n");
				printf("Posición\tDescripcion\t\n");
				for(int i = 0; i < tam; i++) {
					if (!lista[i].isEmpty) {
						PrintLocalidadIndividualConPosicion(lista[i], contadorLocalLocalidades+1);
						contadorLocalLocalidades++;
					}
				}
				printf("----------------------------\n");
				*contadorLocalidades = contadorLocalLocalidades;
		} else {
			printf("No hay localidades cargadas en el sistema para mostrar.\n");
		}
	}
	return retorno;
}

void PrintLocalidadIndividualConPosicion (eLocalidad localidad, int posicion) {
	printf("----------------------------\n");
	printf("%d\t%s\n", posicion, localidad.descripcion);
}

int PrintListaLocalidades(eLocalidad lista[], int tam) {

	int retorno;

	retorno = -1;

	if (lista != NULL && tam > 0) {
		retorno = 0;

		if (VerificarArrayCargadoLocalidades(lista, tam)) {
			SortLocalidadesPorEstado(lista, tam);
				printf("----------------------------\n");
				printf("ID\tDescripcion\t\n");
				for(int i = 0; i < tam; i++) {
					if (!lista[i].isEmpty) {
						PrintLocalidadIndividual(lista[i]);
					}
				}
				printf("----------------------------\n");
		} else {
			printf("No hay localidades cargadas en el sistema para mostrar.\n");
		}
	}
	return retorno;
}

void PrintLocalidadIndividual (eLocalidad localidad) {
	printf("----------------------------\n");
	printf("%d\t%s\n", localidad.idLocalidad, localidad.descripcion);
}

int FindLocalidadById(eLocalidad lista[], int tam, int id) {

	int posicion;

	posicion = -1;

	if (lista != NULL && tam > 0) {
		for(int i = 0; i < tam; i++) {
			if(lista[i].idLocalidad == id && !lista[i].isEmpty) {
				posicion = i;
				break;
			}
		}
	}

	return posicion;
}

int BuscarEspacioLibreLocalidad (eLocalidad lista[], int tam) {
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

int VerificarArrayCargadoLocalidades(eLocalidad lista[], int tam) {
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

void HardcodearLocalidades (eLocalidad lista[]) {

	eLocalidad hardcode[] = {
	    {1, "Barracas", 0},
	    {2, "La Boca", 0},
	    {3, "Parque Patricios", 0},
	    {4, "Montserrat", 0},
	    {5, "San Cristobal", 0},
	    {6, "San Telmo", 0},
	    {7, "Almagro", 0}

	};

	for (int i = 0; i < 7; ++i) {
		lista[i] = hardcode[i];
	}
}
