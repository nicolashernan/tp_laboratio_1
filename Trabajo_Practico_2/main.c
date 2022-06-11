/*
 * main.c
 *
 *  Created on: 7 may. 2022
 *      Author: nico
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FuncionesPasajeros.h"


#define TAM 2000
#define ACTIVO 1


int main()
{

	setbuf(stdout,NULL);

	ePasajero listaPasajeros[TAM];
	int banderaPasajero = 0;


	int nextId = 1000;

	char salir = 'n';

	inicializarPasajeros(listaPasajeros,TAM);

	do{
		switch(menuOpciones())
		{
			case 1:
				banderaPasajero=agregarPasajeros(listaPasajeros,TAM,&nextId);
			break;
			case 2:
				if(banderaPasajero)
				{
				modificarPasajero(listaPasajeros,TAM);
				}
				else
				{
					printf("No hay pasajeros cargados en el sistema.\n");
					system("pause");
				}
			break;
			case 3:
				if(banderaPasajero)
				{
				bajaPasajero(listaPasajeros,TAM);
				}
				else
				{
					printf("No hay pasajeros cargados en el sistema.\n");
					system("pause");
				}
			break;
			case 4:
					if(banderaPasajero)
					{
						switch(informar())
						{
						case 1:
							system("cls");
							ordenarPasajerosPorTipoApellido(listaPasajeros,TAM);
							listarPasajeros(listaPasajeros,TAM);

						break;
						case 2:
							system("cls");
							promedioPrecios(listaPasajeros,TAM);
						break;
						case 3:

							ListadoDePasajerosPorCodigoActivo(listaPasajeros,TAM);

						break;
						}
					}
					else
					{
						printf("No hay pasajeros cargados en el sistema.\n");
						system("pause");
					}

			break;
			case 5:

                banderaPasajero=harcodearPasajeros(listaPasajeros,TAM,10,&nextId);
                listarPasajeros(listaPasajeros,TAM);

			break;
			case 6:
				salir = 's';
			break;


		}
	}while(salir != 's');

}

