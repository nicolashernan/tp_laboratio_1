/*
 * Funciones.c
 *
 *  Created on: 7 may. 2022
 *      Author: nico
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FuncionesPasajeros.h"


void mostrarPasajero(ePasajero pas)
{
	char tipo[20];
	char estado[20];

		if(pas.estadoDeVuelo == 1)
		{
			strcpy(estado,"ACTIVO");
		}
		if(pas.estadoDeVuelo == 2)
		{
			strcpy(estado,"CANCELADO");
		}
		if(pas.estadoDeVuelo == 3)
		{
			strcpy(estado,"DEMORADO");
		}
		if(pas.tipoDePasajero == 1)
		{
			strcpy(tipo,"PRIMERA CLASE");
		}
		if(pas.tipoDePasajero == 2)
		{
			strcpy(tipo,"EJECUTIVO");
		}
		if(pas.tipoDePasajero == 3)
		{
			strcpy(tipo,"PREMIUM");
		}
        printf("id: %d\n",pas.id);
        printf("nombre: %s\n", pas.nombre);
        printf("apellido: %s\n", pas.apellido);
        printf("Sueldo: %.2f\n", pas.precio);
        printf("Codigo de vuelo: %s\n",pas.codigoVuelo);
        printf("Tipo de pasajero: %s\n",tipo);
        printf("Estado de vuelo: %s\n",estado);

}

int inicializarPasajeros(ePasajero vec[],int tam)
{
    int todoOk = -1;
    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 0;
    }
    return todoOk;
}



int agregarPasajeros(ePasajero vec[],int tam,int* pSiguienteId)
{
	int todoOk = 0;
	int indice;
	char auxCad[51];
	int cant;
	ePasajero nuevoPasajero;


	if(vec != NULL && pSiguienteId != NULL && tam > 0)
	{
		system("cls");
		printf("     ***Cargar pasajero***     \n\n");
		buscarLibre(vec,tam,&indice);

		if(indice == -1)
		{
			printf("No hay lugar en el sistema\n");
			system("pause");
		}
		else
		{
			nuevoPasajero.id = *pSiguienteId;
			printf("Ingrese Nombre:\n");
			fflush(stdin);
			gets(auxCad);
			while(strlen(auxCad) >= 51)
            {
                printf("Nombre demaciado largo,Reingrese nombre:\n");
                fflush(stdin);
                gets(auxCad);
            }
            strcpy(nuevoPasajero.nombre,auxCad);

			printf("Ingrese apellido:\n");
			fflush(stdin);
			gets(auxCad);
			while(strlen(auxCad) >= 51)
            {
                printf("Apellido demaciado largo,Reingrese apellido:\n");
                fflush(stdin);
                gets(auxCad);
            }
            strcpy(nuevoPasajero.apellido,auxCad);

			printf("Ingrese precio\n");
			fflush(stdin);
			cant = scanf("%f",&nuevoPasajero.precio);
			while(nuevoPasajero.precio <= 0 || cant == 0)
            {
                printf("Error,Reingrese precio\n");
                fflush(stdin);
                cant = scanf("%f",&nuevoPasajero.precio);

            }

			printf("Ingrese codigo de vuelo:\n");
			fflush(stdin);
			gets(auxCad);
			while(strlen(auxCad) >= 10)
            {
                printf("Codigo demaciado largo,Reingrese codigo de vuelo:\n");
                fflush(stdin);
                gets(auxCad);
            }
            strcpy(nuevoPasajero.codigoVuelo,auxCad);

			printf("Ingrese tipo de pasajero:\n");
			printf("1- Primera Clase.\n");
			printf("2- Ejecutivo.\n");
			printf("3- Premium.\n");
			fflush(stdin);
			scanf("%d",&nuevoPasajero.tipoDePasajero);
			while(nuevoPasajero.tipoDePasajero != 1 && nuevoPasajero.tipoDePasajero != 2 && nuevoPasajero.tipoDePasajero != 3)
            {
                printf("Error,reingrese tipo de pasajero:\n");
                printf("1- Primera Clase.\n");
                printf("2- Ejecutivo.\n");
                printf("3- Premium.\n");
                fflush(stdin);
                scanf("%d",&nuevoPasajero.tipoDePasajero);
            }

			printf("Ingrese estado de vuelo:\n");
			printf("1- Activo.\n");
			printf("2- Cancelado.\n");
			printf("3- Demorado.\n");
			fflush(stdin);
			scanf("%d",&nuevoPasajero.estadoDeVuelo);
			while(nuevoPasajero.estadoDeVuelo != 1 && nuevoPasajero.estadoDeVuelo != 2 && nuevoPasajero.estadoDeVuelo != 3)
			{
			   printf("Error,reingrese estado de vuelo:\n");
			   printf("1- Activo.\n");
			   printf("2- Cancelado.\n");
			   printf("3- Demorado.\n");
			   fflush(stdin);
			   scanf("%d",&nuevoPasajero.estadoDeVuelo);
			}


            printf("Pasajero cargado con exito.\n");
            system("pause");

			nuevoPasajero.isEmpty = 0;
			vec[indice] = nuevoPasajero;

			(*pSiguienteId)++;

			todoOk = 1;
		}

	}

	return todoOk;
}



int buscarLibre(ePasajero vec[],int tam,int* pIndex)
{
	int todoOk = 0;
	if(vec != NULL && pIndex != NULL && tam > 0)
	{
		*pIndex = -1;
		for(int i = 0; i < tam;i++)
		{
			if(vec[i].isEmpty)
			{
				*pIndex = i;
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}


int menuOpciones()
{
	int opcion;
	int cant;
		system("cls");
		printf("***Menu de opciones***\n\n\n");
		printf("1- Altas\n");
		printf("2- Modificar\n");
		printf("3- Baja\n");
		printf("4- Informar\n");
		printf("5- Alta forzada de pasajeros\n");
		printf("6- Salir\n");
		printf("Seleccionar la opcion deseada\n\n");
		cant=scanf("%d",&opcion);
			while(cant==0 || opcion <=0 || opcion>6)
			{
				printf("Error,Reingrese la opcion");
				fflush(stdin);
				cant=scanf("%d",&opcion);
			}

			return opcion;
	return opcion;
}

int bajaPasajero(ePasajero vec[],int tam)
{
    int todoOk = 0;
    int id;
    int indice;
    char respuesta;

    if(vec != NULL && tam > 0)
    {
        listarPasajeros(vec,tam);

        printf("Ingrese el id del pasajero a dar de baja\n");
        scanf("%d",&id);

        buscarPasajero(vec,tam,id,&indice);

        if(indice == -1)
        {
            printf("No existe pasajero con ese id\n");
            system("pause");
        }
        else
        {
            mostrarPasajero(vec[indice]);
            printf("confirmar baja? s / n\n\n");
            fflush(stdin);
            scanf("%c",&respuesta);

            if(respuesta == 'S' || respuesta == 's')
            {
                vec[indice].isEmpty = 1;
                printf("Se dio de baja al pasajero\n");
                system("pause");
            }
            else
            {
                printf("baja cancelada.\n");
                system("pause");
            }
        }

    }

    return todoOk;
}

int buscarPasajero(ePasajero vec[],int tam,int id,int* pIndice)
{
    int todoOk = 0;

    if(vec != NULL && pIndice != NULL && tam > 0)
    {
        *pIndice = -1;

        for(int i = 0;i < tam; i++)
        {
            if(vec[i].isEmpty != 1 && vec[i].id == id)
            {
                *pIndice = i;
                break;//para que deje de recorrer el array al momento de encontrar
            }
        }

        todoOk = 1;
    }

    return todoOk;
}

int modificarPasajero(ePasajero vec[],int tam)
{
	int todoOk = 0;
    int id;
    int indice;
    char auxNombre[100];
    char auxApellido[100];
    char auxCodigoVuelo[100];
    float auxPrecio;
    int auxTipoDePasajero;
    int cant;

    listarPasajeros(vec,tam);


    printf("Ingrese el id del pasajero que decea modificar:");
    scanf("%d",&id);

    buscarPasajero(vec,tam,id,&indice);

    if(indice == -1)
    {
        printf("id ingresado incorrecto.\n");
        system("pause");
    }
    else
    {
        switch(menuModificar())
        {
            case 1:
                printf("Ingrese nuevo nombre:\n");
                fflush(stdin);
                gets(auxNombre);
                while(strlen(auxNombre) >= 51)
                {
                    printf("Nombre demaciado largo,Reingrese nombre:\n");
                    fflush(stdin);
                    gets(auxNombre);
                }
                strcpy(vec[indice].nombre,auxNombre);
                printf("Nombre cambiado con exito!");
                system("pause");
            break;
            case 2:
                printf("Ingrese nuevo apellido:\n");
                fflush(stdin);
                gets(auxApellido);
                while(strlen(auxApellido) >= 51)
                {
                    printf("Apellido demaciado largo,Reingrese apellido:\n");
                    fflush(stdin);
                    gets(auxApellido);
                }
                strcpy(vec[indice].apellido,auxApellido);
                printf("Apellido cambiado con exito!");
                system("pause");
            break;
            case 3:
                printf("Ingrese nuevo precio:\n");
                fflush(stdin);
                cant = scanf("%f",&auxPrecio);
                while(auxPrecio <= 0 || cant == 0)
                {
                   printf("Error,Reingrese precio\n");
                   fflush(stdin);
                   cant = scanf("%f",&auxPrecio);
                }
                vec[indice].precio = auxPrecio;
                printf("Precio cambiado con exito!");
                system("pause");
            break;
            case 4:
                printf("Ingrese nuevo codigo de vuelo:\n");
                fflush(stdin);
                gets(auxCodigoVuelo);
                while(strlen(auxCodigoVuelo) >= 10)
                {
                    printf("Codigo demaciado largo,Reingrese codigo de vuelo:\n");
                    fflush(stdin);
                    gets(auxCodigoVuelo);
                }
                strcpy(vec[indice].codigoVuelo,auxCodigoVuelo);
                printf("Codigo cambiado con exito!");
                system("pause");
            break;
            case 5:
                printf("Ingrese nuevo tipo de pasajero\n");
                printf("1- Primera Clase.\n");
                printf("2- Ejecutivo.\n");
                printf("3- Premium.\n");
                fflush(stdin);
                scanf("%d",&auxTipoDePasajero);
                while(auxTipoDePasajero != 1 && auxTipoDePasajero != 2 && auxTipoDePasajero != 3)
                {
                   printf("Error,reingrese tipo de pasajero:\n");
                   printf("1- Primera Clase.\n");
                   printf("2- Ejecutivo.\n");
                   printf("3- Premium.\n");
                   fflush(stdin);
                   scanf("%d",&auxTipoDePasajero);
                }
                vec[indice].tipoDePasajero = auxTipoDePasajero;
                printf("Tipo de pasajero cambiado con exito!\n");
                system("pause");
            break;
            todoOk = 1;
        }
    }

    return todoOk;
}

int menuModificar()
{
   int opcion;

   printf("1) modificar nombre.\n");
   printf("2) modificar apellido.\n");
   printf("3) modificar precio.\n");
   printf("4) modificar codigo de vuelo.\n");
   printf("5) modificar tipo de pasajero.\n");
   scanf("%d",&opcion);

   return opcion;
}

int harcodearPasajeros(ePasajero vec[],int tam,int cantidad,int* pNextId)
{
    int todoOk = 0;
    ePasajero pasajeros[10]=
     {
        {0,"Juan","Pereyra",233,"dgs45",2,2,0},
        {0,"Miguel","Ledezma",522,"23yuj",2,2,0},
        {0,"Juana","Aguilar",682,"ov3t6",1,3,0},
        {0,"Andrea","Andrade",734,"nmud56",1,3,0},
        {0,"Juliana","Fernandez",122,"pbr793",3,2,0},
        {0,"Martin","Baes",531,"04x1bk",2,1,0},
        {0,"Dario","Ponce",67,"lcw730",2,1,0},
        {0,"Alicia","Irala",45,"mxb5u1",3,2,0},
        {0,"Javier","Ramirez",26,"pxx267",1,3,0},
        {0,"Diego","Topo",25,"Jgxw2",1,1,0}
    };

    if(vec != NULL && pNextId != NULL && tam > 0 && tam <= 2000 && cantidad <= tam)
    {
        for(int i = 0; i<cantidad;i++)
        {
            vec[i]=pasajeros[i];
            vec[i].id = *pNextId;
            (*pNextId)++;
        }
        todoOk = 1;
        printf("Pasajeros cargados!\n");
    }

    return todoOk;
}

int ordenarPasajerosApellido(ePasajero vec[], int tam)
{
    int todoOk = 0;
    ePasajero auxPasajero;

    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {
                if( strcmp(vec[i].apellido, vec[j].apellido) > 0 )
                {
                    auxPasajero = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxPasajero;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int ordenarPasajerosPorTipoApellido(ePasajero vec[],int tam)
{
    int todoOk = 0;
    ePasajero auxPasajero;

    if(vec != NULL && tam > 0)
    {
        for(int i = 0;i<tam-1;i++)
        {
            for(int j = i+1;j<tam;j++)
            {
            	if((strcmp(vec[i].apellido,vec[j].apellido) > 0) || (strcmp(vec[i].apellido,vec[j].apellido) == 0 && vec[i].tipoDePasajero > vec[j].tipoDePasajero))

            	                {
            	                    auxPasajero = vec[i];
            	                    vec[i] = vec[j];
            	                    vec[j] = auxPasajero;
            	                }
            }
        }
        todoOk = 1;

    }

    return todoOk;


}

int informar()
{
	int opcion;
	int cant;
	printf("1) Listado de los pasajeros ordenados alfabeticamente por apellido y Tipo de pasajero.\n");
	printf("2) Total y promedio de los precios de los pasaje, y cuantos pasajeros superan el precio promedio.\n");
	printf("3) Listado de pasajeros por codigo de vuelo y estado de vuelos -ACTIVOS-.\n");
	printf("Ingrese la opcion deceada");
	fflush(stdin);
	cant=scanf("%d",&opcion);
	while(cant==0 || opcion <=0)
	{
		printf("Error,Reingrese la opcion");
		fflush(stdin);
		cant=scanf("%d",&opcion);
	}

	return opcion;

}

int promedioPrecios(ePasajero vec[],int tam)
{
	int todoOk = 0;
	int contPasajeros = 0;
	float acumPrecio = 0;
	float promedioPasajeros;
	int contSuperanPromedio = 0;

	if(vec != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(!vec[i].isEmpty)
			{
				acumPrecio += vec[i].precio;
				contPasajeros++;
			}
		}
		if(contPasajeros != 0)
		{
			promedioPasajeros = acumPrecio / contPasajeros;
		}

		for(int i = 0; i<tam; i++)
		{
			if(vec[i].isEmpty != 1 && promedioPasajeros < vec[i].precio)
			{
				contSuperanPromedio++;
			}
		}

		printf("El total de precio de los pasajes es: $ %.2f\n ",acumPrecio);
		printf("El promedio de precios es: $ %.2f\n",promedioPasajeros);
		printf("%d son los pasajeros que superan el precio promedio.\n",contSuperanPromedio);
		system("pause");


		todoOk=1;

	}

	return todoOk;
}

int buscarActivos(ePasajero vec[],int tam)
{

	int respuesta = 0;

	if(vec != NULL && tam > 0)
	{
		for(int i=0;i < tam;i++)
		{
			if(vec[i].estadoDeVuelo == 1)
			{
				respuesta = 1;
			}
		}
	}

	return respuesta;
}

void ListadoDePasajerosPorCodigoActivo(ePasajero vec[],int tam)
{
	char codigo[10];
	int validar;

		if(vec != NULL && tam > 0)
		{
			validar = buscarActivos(vec,tam);

			if(validar==1)
			{
				system("cls");
				printf("    nombre     |  apellido   |   codigo de vuelo   |   estado de vuelo\n\n");

				for(int i = 0;i<tam;i++)
				{
					if(vec[i].isEmpty == 0)
					{
						if(vec[i].estadoDeVuelo == 1)
						{
							strcpy(codigo,"ACTIVO");

							printf("%10s   %10s                %6s             %10s\n",
							vec[i].nombre,vec[i].apellido,vec[i].codigoVuelo,codigo);
						}

					}
				}

			}
			else
			{
				printf("No hay pasajeros con estado de vuelo activo.\n");

			}

			system("pause");
		}
}

void listarPasajeros(ePasajero vec[],int tam)
{
	char estado[10];
	char tipo[20];

	printf("id    |    nombre    |    apellido   |     precio de vuelo   |      codigo de vuelo         |   tipo de pasajero          |   estado de vuelo\n\n");
	if(vec != NULL && tam > 0)
	{
		for(int i = 0;i<tam;i++)
		{
			if(vec[i].isEmpty == 0)
			{

				if(vec[i].estadoDeVuelo == 1)
				{
					strcpy(estado,"ACTIVO");
				}
				if(vec[i].estadoDeVuelo == 2)
				{
					strcpy(estado,"CANCELADO");
				}
				if(vec[i].estadoDeVuelo == 3)
				{
					strcpy(estado,"DEMORADO");
				}
				if(vec[i].tipoDePasajero == 1)
				{
					strcpy(tipo,"PRIMERA CLASE");
				}
				if(vec[i].tipoDePasajero == 2)
				{
					strcpy(tipo,"EJECUTIVO");
				}
				if(vec[i].tipoDePasajero == 3)
				{
					strcpy(tipo,"PREMIUM");
				}

	printf("%-4d     %-10s     %-10s            %-7.2f                 %-6s                   %-20s             %-20s\n",
						vec[i].id,vec[i].nombre,vec[i].apellido,vec[i].precio,vec[i].codigoVuelo,
						tipo,estado);


			}

		}

		system("pause");
	}
}








