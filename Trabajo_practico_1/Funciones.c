/*
 * Funciones.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Hernan Nicolas Pereya.
 */


#include <stdio.h>
#include <stdlib.h>

int menu(float km,float aerolineas,float latam)
{
	int opcion;

	printf("***Menu de opciones***\n\n");
	printf("1- Ingresar kilometros: (km=%.2f)\n",km);
	printf("2- Ingresar precio de vuelos (Aerolineas=$%.2f,Latam=$%.2f)\n",aerolineas,latam);
	printf("3- Calcular todos los costos\n");
	printf("4- Informar resultados\n");
	printf("5- Carga forzada de datos\n");
	printf("6- Salir\n");
	printf("Seleccionar la opcion deseada\n");
	scanf("%d", &opcion);

	return opcion;
}

float kilometros()
{
	float kilometros;
	int cant;


	printf("Ingrese kilometros\n");
	cant=scanf("%f",&kilometros);
	fflush(stdin);

	while((kilometros <= 0) || (cant == 0))
	{
		printf("Error,ingrese una cantidad valida\n");
		printf("Ingrese kilometros\n");
		cant=scanf("%f",&kilometros);
		fflush(stdin);
	}

	return kilometros;
}

float precioA()
{
	float precioA;
	int cant;

	printf("Ingrese el precio de Aerolineas;\n");
	cant = scanf("%f",&precioA);
	fflush(stdin);

	while(precioA <= 0 || cant == 0)
	{
		printf("Error,re ingrese precio");
		cant = scanf("%f",&precioA);
		fflush(stdin);
	}
	return precioA;
}

float precioL()
{
	float precioL;
	int cant;

	printf("Ingrese el precio de Latam;\n");
	cant = scanf("%f",&precioL);
	fflush(stdin);

	while(precioL <= 0 || cant == 0)
	{
		printf("Error,re ingrese precio");
		cant = scanf("%f",&precioL);
		fflush(stdin);
	}
	return precioL;

}

float precioDebito(float a)
{
	float precioDebito;
	precioDebito = a-((a*10)/100);
	return precioDebito;
}

float precioCredito(float a)
{
	float precioCredito;
	precioCredito = a+((a*25)/100);
	return precioCredito;
}

float precioBitcoin(float a)
{
	float precioBitcoin;
	precioBitcoin = a/4606954.55;
	return precioBitcoin;
}

float precioKm(float p,float k)
{
	float precioKm;
	precioKm = p/k;
	return precioKm;
}

float diferencia(float a,float l)
{
	float diferencia;

	if(a > l)
	{
		diferencia = a-l;
	}
	else
	{
		diferencia = l-a;
	}
	return diferencia;
}

void mostrarResultados(float kmIngresados,float preA,float preL,float debitoL,
		float creditoL, float btcL, float kmL, float debitoA, float creditoA, float btcA, float kmA, float diferencia)//funcion para mostrar los resultados obtenidos.
{
	printf("KMs ingresados: %.2fkm\n\n",kmIngresados);
	printf("Precio Aerolineas: $%.2f\n",preA);
	printf("a) Precio con tarjeta de debito: $%.2f\n",debitoA);
	printf("b) Precio con tarjeta de credito: $%.2f\n",creditoA);
	printf("c) Precio pagando con bitcoin: $%.5f\n",btcA);
	printf("d) Mostrar precio unitario: $%.2f\n\n",kmA);
	printf("Precio Latam: $%.2f\n",preL);
	printf("a) Precio con tarjeta de debito: $%.2f\n",debitoL);
	printf("b) Precio con tarjeta de credito: $%.2f\n",creditoL);
	printf("c) Precio pagando con bitcoin: $%.5f\n",btcL);
	printf("d) Mostrar precio unitario: $%.2f\n\n",kmL);
	printf("la diferencia de precio es: $%.2f\n\n",diferencia);
}



