/*
 * main.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Hernan Nicolas Pereyra.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


int main()
{
	setbuf(stdout, NULL);

	int banderaKm=0;
	int banderaPrecio = 0;
	int banderaCalculos = 0;
	float precioLatam = 0;
	float precioAerolineas = 0;
	float km = 0;
	float precioDebitoA;
	float precioDebitoL;
	float precioCreditoA;
	float precioCreditoL;
	float precioBtcA;
	float precioBtcL;
	float precioPorKmA;
	float precioPorKmL;
	float diferenciaDePrecios;
	char salir = 'n';

	do{
		switch(menu(km,precioAerolineas,precioLatam))
		{
		case 1:
			km = kilometros();

			if(km > 0)
			{
				banderaKm=1;
			}
			system("pause");

		break;

		case 2:
			if(banderaKm == 1)
			{
				precioAerolineas = precioA();
				precioLatam = precioL();
				banderaPrecio = 1;
				system("pause");

			}else
			{
				printf("Se debe ingresar kilometros.\n");
				system("pause");
			}

		break;

		case 3:
			if(banderaPrecio == 1)
			{
			precioDebitoA = precioDebito(precioAerolineas);
			precioDebitoL = precioDebito(precioLatam);
			precioCreditoA = precioCredito(precioAerolineas);
			precioCreditoL = precioCredito(precioLatam);
			precioBtcA = precioBitcoin(precioAerolineas);
			precioBtcL = precioBitcoin(precioLatam);
			precioPorKmA = precioKm(precioAerolineas,km);
			precioPorKmL = precioKm(precioLatam,km);
			diferenciaDePrecios = diferencia(precioAerolineas,precioLatam);

			printf("Costos calculados.\n");
			system("pause");

			banderaCalculos = 1;

			}
			else
			{
				printf("Se debe ingresar precios de vuelos.\n");
				system("pause");
			}
		break;

		case 4:
			if(banderaCalculos == 1)
			{
				mostrarResultados(km,precioAerolineas,precioLatam,
								precioDebitoL,precioCreditoL,precioBtcL,precioPorKmL,precioDebitoA,
								precioCreditoA,precioBtcA,precioPorKmA,diferenciaDePrecios);

				system("pause");
				km = 0;
				precioLatam = 0;
				precioAerolineas = 0;
				banderaPrecio = 0;
				banderaCalculos = 0;
			}
			else
			{
				printf("se debe realizar los calculos.\n");
				system("pause");
			}
		break;

		case 5:
			km = 7090;
			precioLatam = 159339;
			precioAerolineas = 162965;
			precioDebitoA = precioDebito(precioAerolineas);
			precioDebitoL = precioDebito(precioLatam);
			precioCreditoA = precioCredito(precioAerolineas);
			precioCreditoL = precioCredito(precioLatam);
			precioBtcA = precioBitcoin(precioAerolineas);
			precioBtcL = precioBitcoin(precioLatam);
			precioPorKmA = precioKm(precioAerolineas,km);
			precioPorKmL = precioKm(precioLatam,km);
			diferenciaDePrecios = diferencia(precioAerolineas,precioLatam);

			mostrarResultados(km,precioAerolineas,precioLatam,
							precioDebitoL,precioCreditoL,precioBtcL,precioPorKmL,precioDebitoA,
							precioCreditoA,precioBtcA,precioPorKmA,diferenciaDePrecios);

			km = 0;
			precioLatam = 0;
			precioAerolineas = 0;

			system("pause");
		break;

		case 6:
			salir = 's';
		break;

		default:
			printf("Error,Ingrese una opcion de las anteriores\n\n\n");
			fflush(stdin);
			system("pause");
		break;

		}
	}while(salir != 's');

	return 0;
}

