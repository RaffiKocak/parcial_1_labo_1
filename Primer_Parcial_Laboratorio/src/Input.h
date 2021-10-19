/*
 * Input.h
 *
 *  Created on: 4 oct 2021
 *      Author: Raffi
 */


#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//--------------------------NUMEROS----------------------------

/// @brief Pide un n�mero entero con una cantidad determinada de reintentos, en un rango determinado.
///
/// @param mensaje
/// @param numeroIngresado
/// @param minimo
/// @param maximo
/// @param intentos
/// @return Retorna 1 si se ingres� el n�mero correctamente dentro de la cantidad de reintentos o 0 si hubo demasiados intentos fallidos.
int PedirIntConRangoConReintentos(char mensaje[], int *numeroIngresado, int minimo, int maximo, int intentos);

/// @brief Pide un n�mero flotante con una cantidad determinada de reintentos, en un rango determinado.
///
/// @param mensaje
/// @param numeroIngresado
/// @param minimo
/// @param maximo
/// @param intentos
/// @return Retorna 1 si se ingres� el n�mero correctamente dentro de la cantidad de reintentos o 0 si hubo demasiados intentos fallidos.
int PedirFloatConRangoConReintentos(char mensaje[], float *numeroIngresado, int minimo, int maximo, int intentos);

/// @brief Pide un n�mero entero con una cantidad determinada de reintentos.
///
/// @param mensaje
/// @param numeroIngresado
/// @param intentos
/// @return Retorna 1 si se ingres� el n�mero correctamente dentro de la cantidad de reintentos o 0 si hubo demasiados intentos fallidos.
int PedirIntConReintentos(char mensaje[], int *numeroIngresado, int intentos);

/// @brief Pide un n�mero flotante con una cantidad determinada de reintentos.
///
/// @param mensaje
/// @param numeroIngresado
/// @param intentos
/// @return Retorna 1 si se ingres� el n�mero correctamente dentro de la cantidad de reintentos o 0 si hubo demasiados intentos fallidos.
int PedirFloatConReintentos(char mensaje[], float *numeroIngresado, int intentos);

/// @brief Pide un n�mero entero que se encuentre en un rango determinado.
///
/// @param mensaje
/// @param minimo
/// @param maximo
/// @return Retorna el n�mero entero ingresado dentro del rango establecido.
int PedirIntConRango (char mensaje[], int minimo, int maximo);

/// @brief Pide un n�mero flotante que se encuentre en un rango determinado.
///
/// @param mensaje
/// @param minimo
/// @param maximo
/// @return Retorna el n�mero flotante ingresado dentro del rango establecido.
float PedirFloatConRango (char mensaje[], float minimo, float maximo);

/// @brief Pide un n�mero entero.
///
/// @param mensaje
/// @return Retorna el n�mero entero ingresado.
int PedirInt (char mensaje[]);

/// @brief Pide un n�mero flotante.
///
/// @param mensaje
/// @return Retorna el n�mero flotante ingresado.
float PedirFloat (char mensaje[]);

/// @brief Funci�n auxiliar. Verifica que el n�mero ingresado cumpla con todas las propiedades correspondientes a un n�mero entero.
///
/// @param numeroAVerificar
/// @return Retorna 1 si el n�mero cumple con las condiciones de n�mero entero, o 0 si no las cumple.
int VerificarInt(char numeroAVerificar[]);

/// @brief Funci�n auxiliar. Verifica que el n�mero ingresado se encuentre dentro del rango establecido.
///
/// @param numeroAVerificar
/// @param numeroADevolver
/// @param minimo
/// @param maximo
/// @return Retorna 1 si el n�mero se encuentra dentro del rango o 0 si no cumple con esta condici�n.
int VerificarRangoInt(char numeroAVerificar[], int *numeroADevolver, int minimo, int maximo);

/// @brief Funci�n auxiliar. Verifica que el n�mero ingresado cumpla con todas las propiedades correspondientes a un n�mero flotante.
///
/// @param numeroAVerificar
/// @return Retorna 1 si el n�mero cumple con las condiciones de n�mero entero, o 0 si no las cumple.
int VerificarFloat(char numeroAVerificar[]);

/// @brief Funci�n auxiliar. Verifica que el n�mero ingresado se encuentre dentro del rango establecido.
///
/// @param numeroAVerificar
/// @param numeroADevolver
/// @param minimo
/// @param maximo
/// @return Retorna 1 si el n�mero se encuentra dentro del rango o 0 si no cumple con esta condici�n.
int VerificarRangoFloat(char numeroAVerificar[], float *numeroADevolver, float minimo, float maximo);
//--------------------------STRINGS----------------------------
/// @brief Funci�n auxiliar para tomar cadenas de caracteres a trav�s del buffer. Evita el desbordamiento de memoria.
///
/// @param string
/// @param len
/// @return Retorna -1 si la cadena ingresada por el usuario es m�s larga que la cadena donde el dato se almacenar�, de lo contrario retorna 0.
int GetString(char string[], int len);

/// @brief Pide una cadena de caracteres con una cantidad determinada de intentos.
/// El dato ingresado ser� cada palabra que contenga su primer letra may�scula, y el resto de las letras en min�scula.
/// @param mensaje
/// @param cadena
/// @param tam
/// @param intentos
/// @return Retorna 1 si se ingres� el n�mero correctamente dentro de la cantidad de reintentos o 0 si hubo demasiados intentos fallidos.
int PedirCadenaProlijaConReintentos(char mensaje[], char cadena[], int tam, int intentos);

/// @brief Pide una cadena de caracteres con una cantidad determinada de intentos.
///
/// @param mensaje
/// @param cadena
/// @param tam
/// @param intentos
/// @return Retorna 1 si se ingres� el n�mero correctamente dentro de la cantidad de reintentos o 0 si hubo demasiados intentos fallidos.
int PedirCadenaConReintentos(char mensaje[], char cadena[], int tam, int intentos);

/// @brief  Pide una cadena de caracteres.
///
/// @param mensaje
/// @param cadena
/// @param tam
/// @param intentos
void PedirCadena(char mensaje[], char cadena[], int tam, int intentos);

/// @brief Pide una cadena de caracteres, pudiendo ser un nombre o apellido en general, con una cantidad determinada de intentos.
/// El dato ingresado ser� una cadena que contenga su primer letra may�scula, y el resto de las letras en min�scula.
/// @param mensaje
/// @param cadena
/// @param tam
/// @param intentos
/// @return Retorna 1 si se ingres� el n�mero correctamente dentro de la cantidad de reintentos o 0 si hubo demasiados intentos fallidos.
int PedirNombreOApellidoConReintentos(char mensaje[], char cadena[], int tam, int intentos);

/// @brief Pide una cadena de caracteres, pudiendo ser un nombre o apellido en general.
/// El dato ingresado ser� una cadena que contenga su primer letra may�scula, y el resto de las letras en min�scula.
/// @param mensaje
/// @param cadena
/// @param tam
void PedirNombreOApellido(char mensaje[], char cadena[], int tam);

/// @brief Funci�n auxiliar. Convierte la primer letra de una cadena de caracteres a may�scula, y el resto de las letras en min�scula.
///
/// @param cadena
void EmprolijarPalabra(char cadena[]);

/// @brief Funci�n auxiliar. Convierte la primer letra de cada palabra en may�scula, y el resto de las letras en min�scula.
///
/// @param cadena
void EmprolijarCadena(char cadena[]);

/// @brief Pide una cadena de caracteres que no contenga nada m�s que letras, con una determinada cantidad de reintentos.
///
/// @param mensaje
/// @param cadena
/// @param tam
/// @param intentos
/// @return Retorna 1 si se ingres� el n�mero correctamente dentro de la cantidad de reintentos o 0 si hubo demasiados intentos fallidos.
int PedirCadenaSoloLetrasConReintentos(char mensaje[], char cadena[], int tam, int intentos);

/// @brief Pide una cadena de caracteres que no contenga nada m�s que letras.
///
/// @param mensaje
/// @param cadena
/// @param tam
void PedirCadenaSoloLetras(char mensaje[], char cadena[], int tam);

/// @brief Pide un caracter que solamente pueda ser una letra.
///
/// @param mensaje
/// @return Retorna la letra ingresada.
char PedirCaracterSoloLetra (char mensaje[]);

/// @brief Pide un caracter que solamente pueda ser una 's', 'S', 'n' o 'N'. Para confirmaciones.
///
/// @param mensaje
/// @return Retorna la letra ingresada.
char PedirCaracterSiONo (char mensaje[]);

/// @brief Funci�n auxiliar. Verifica que en una cadena ingresada s�lo se hayan ingresado caracteres de tipo letra.
///
/// @param cadena
/// @return Retorna 1 si el caracter solamente tiene letras, y 0 si no cumple con esa condici�n.
int VerificarCadenaSoloLetras(char cadena[]);
int PedirCUITConReintentos (char mensaje[], char cadenaIngresada[], int tamCadenaIngresada, int intentos);

int VerificarFormatoCUIT (char numeroAVerificar[]);
//int VerificarRangoCUIT (char numeroAVerificar[], double *numeroADevolver);


#endif /* INPUT_H_ */
