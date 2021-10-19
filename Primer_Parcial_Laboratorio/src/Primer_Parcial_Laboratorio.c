/*
 ============================================================================
 Name        : Primer_Parcial_Laboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Nexo.h"

#define TAM_C 100
#define TAM_P 1000
#define TAM_L 50

int main(void) {

	setbuf(stdout, NULL);

	eCliente listaClientes[TAM_C];
	ePedido listaPedidos[TAM_P];
	eLocalidad listaLocalidades[TAM_L];

	int idClientes;
	int idPedidos;
	int idLocalidad;

	idClientes = 15; //14 es el último hardcodeado, si no, inicializar en 1
	idPedidos = 107; //106 es el último hardcodeado, si no, inicializar en 100
	idLocalidad = 8; //7 es el último hardcodeado, si no, inicializar en 1

	InitCliente(listaClientes, TAM_C);
	InitPedido(listaPedidos, TAM_P);
	InitLocalidad(listaLocalidades, TAM_L);
	HardcodearEmpresa(listaClientes);
	HardcodearPedidos(listaPedidos);
	HardcodearLocalidades(listaLocalidades);

	MostrarMenuPrincipal(listaClientes, TAM_C, listaPedidos, TAM_P, listaLocalidades, TAM_L, &idClientes, &idPedidos, &idLocalidad);


	return EXIT_SUCCESS;
}
