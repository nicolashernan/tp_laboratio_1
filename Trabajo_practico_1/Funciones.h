/*
 * Funciones.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Hernan Nicolas Pereyra.
 */


#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/// @fn int menu(float, float, float)
/// @brief muetra un menu  y toma la opcion seleccionada por el usuario
///
/// @param kilometros
/// @param precio de vuelo aerolineas
/// @param precios de vuelo latam
/// @return opcion seleccionada
int menu(float,float,float);

/// @fn float kilometros()
/// @brief funcion para validar los kilometros ingresados por el usuario
///
/// @return kilometros
float kilometros();

/// @fn float precioA()
/// @brief funcion para validar el precio de vuelo aerolineas
///
/// @return precio ingresado por el usuario
float precioA();

/// @fn float precioL()
/// @brief funcion para validar el precio de vuelo latam
///
/// @return precio ingresado por el usuario
float precioL();

/// @fn float precioDebito(float)
/// @brief operador que calcular el precio ingresado pagando con tarjeta de debito
///
/// @param precio a calcular
/// @return precio ingresado con 10% de descuento
float precioDebito(float a);

/// @fn float precioCredito(float)
/// @brief operador que calcula el precio ingresado pagando con tarjeta de credito
///
/// @param precio a calcular
/// @return precio ingresado con un 25% de interes
float precioCredito(float a);

/// @fn float precioBitcoin(float)
/// @brief operador que calcula el precio ingresado pagando con bitcoins
///
/// @param precio a calcular
/// @return precio ingresado pagando con bitcoins
float precioBitcoin(float a);

/// @fn float precioKm(float, float)
/// @brief operador que calcula el precio por km
///
/// @param precio de vuelo
/// @param kilometros ingresados
/// @return precio por kilometro
float precioKm(float p,float k);

/// @fn float diferencia(float, float)
/// @brief operador que calcula la diferencia de precios entre los vuelos
///
/// @param precio de vuelo 1
/// @param precio de vuelo 2
/// @return diferencia de precios
float diferencia(float a,float l);

/// @fn void mostrarResultados(float, float, float, float, float, float, float, float, float, float, float, float)
/// @brief funcion para mostrar los resultados obtenidos
///
/// @param kilometros
/// @param precio Aerolineas
/// @param precio Latam
/// @param precio a pagar de vuelo latam pagando con tarjeta de debito
/// @param precio a pagar de vuelo latam pagando con tarjeta de credito
/// @param precio a pagar de vuelo latam pagando con bitcoins
/// @param precio por kilometros de vuelo latam
/// @param precio a pagar de vuelo aerolineas pagando con tarjeta de debito
/// @param precio a pagar de vuelo aerolineas pagando con tarjeta de credito
/// @param precio a pagar de vuelo aerolineas pagando con bitcoins
/// @param precio por kilometros de vuelo aerolineas
/// @param diferencia de precios
void mostrarResultados(float kmIngresados,float preA,float preL,
		float debitoL, float creditoL, float btcL, float kmL, float debitoA, float creditoA, float btcA, float kmA, float diferencia);


#endif /* FUNCIONES_H_ */
