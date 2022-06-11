/*
 * Funciones.h
 *
 *  Created on: 7 may. 2022
 *      Author: nico
 */

#ifndef FUNCIONESPASAJEROS_H_
#define FUNCIONESPASAJEROS_H_

typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoVuelo[10];
	int tipoDePasajero;
	int estadoDeVuelo;
	int isEmpty;
}ePasajero;

/// @fn int inicializarPasajeros(ePasajero[], int)
/// @brief le da el valor 1 a todos los campos isEmpty de un vector de estructura
///
/// @pre
/// @post
/// @param vector de estructura
/// @param tamaño del vector
/// @return 1 si esta todo ok y 0 si el vector es igual a null o el tamaño es 0 o menor.
int inicializarPasajeros(ePasajero vec[],int tam);

/// @fn void mostrarPasajero(ePasajero)
/// @brief muestra todos los campos de una estructura
///
/// @pre
/// @post
/// @param vector de estructura
void mostrarPasajero(ePasajero pas);

/// @fn int agregarPasajeros(ePasajero[], int, int*)
/// @brief funcion para agregar pasajeros al sistema
///
/// @pre
/// @post
/// @param vector de estructura
/// @param tamaño de vector
/// @param id con el cual se esta trabajando
/// @return 1 si esta todo ok y 0 si el vector es igual a null o el tamaño es 0 o menor o el id es null.
int agregarPasajeros(ePasajero vec[],int tam,int* pSiguienteId);

/// @fn int buscarLibre(ePasajero[], int, int*)
/// @brief busca en el vector de estructura un campo con el valor de isEmpty en 1
///
/// @pre
/// @post
/// @param vector de estructura
/// @param tamaño de vector
/// @param indice para buscar en el vector
/// @return 1 si esta todo ok y 0 si el vector es igual a null o el tamaño es 0 o menor o el indice es null.
int buscarLibre(ePasajero vec[],int tam,int* pIndex);

/// @fn int menuOpciones()
/// @brief muestra un menu de opciones
///
/// @pre
/// @post
/// @return opcion elegida por el usuario
int menuOpciones();

/// @fn int bajaPasajero(ePasajero[], int)
/// @brief da la baja a un pasajero del vector de estructura en el sistema
///
/// @pre
/// @post
/// @param vector de estructura
/// @param tamaño de vector
/// @return 1 si esta todo ok y 0 si el vector es igual a null o el tamaño es 0 o menor.
int bajaPasajero(ePasajero vec[],int tam);

/// @fn int menuModificar()
/// @brief muestra un menu de opciones de modificacion
///
/// @pre
/// @post
/// @return opcion elegida por el usuario
int menuModificar();

/// @fn int modificarPasajero(ePasajero[], int)
/// @brief funcion para modificar a un pasajero del vector de estructura
///
/// @pre
/// @post
/// @param vector de estructura
/// @param tamaño del vector
/// @return 1 si esta todo ok y 0 si el vector es igual a null o el tamaño es 0 o menor.
int modificarPasajero(ePasajero vec[],int tam);

/// @fn int harcodearPasajeros(ePasajero[], int, int, int*)
/// @brief
///
/// @pre
/// @post
/// @param vector de estructura
/// @param tamaño del vector
/// @param cantidad de pasajeros a harcodear
/// @param id con el que se trabaj en ese momento
/// @return 1 si esta todo ok y 0 si el vector es igual a null o el tamaño es 0 o menor.
int harcodearPasajeros(ePasajero vec[],int tam,int cantidad,int* pNextId);

/// @fn int ordenarPasajerosPorTipoApellido(ePasajero[], int)
/// @brief ordena los pasajeros por apellido y tipo de pasajero
///
/// @pre
/// @post
/// @param vector de estructura
/// @param tamaño del vector
/// @return 1 si esta todo ok y 0 si el vector es igual a null o el tamaño es 0 o menor.
int ordenarPasajerosPorTipoApellido(ePasajero vec[],int tam);

/// @fn int informar()
/// @brief menu de opciones para la informacion
///
/// @pre
/// @post
/// @return opcion elegida por el usuario
int informar();

/// @fn int buscarPasajero(ePasajero[], int, int, int*)
/// @brief busca un pasajero por id
///
/// @pre
/// @post
/// @param vector de estructura
/// @param tamaño del vector
/// @param id a buscar
/// @param indice en el que se encuentra el id
/// @return 1 si esta todo ok y 0 si el vector es igual a null o el tamaño es 0 o menor.
int buscarPasajero(ePasajero vec[],int tam,int id,int* pIndice);

/// @fn int promedioPrecios(ePasajero[], int)
/// @brief promedia los precios ingresados en el vector de estructura
///
/// @pre
/// @post
/// @param vector de estructura
/// @param tamaño del vector
/// @return 1 si esta todo ok y 0 si el vector es igual a null o el tamaño es 0 o menor.
int promedioPrecios(ePasajero vec[],int tam);

/// @fn void ListadoDePasajerosPorCodigoActivo(ePasajero[], int)
/// @brief muestra la lista de pasajeros por codigo y estado de vuelo activo
///
/// @pre
/// @post
/// @param vector de estructura
/// @param tamaño del vector
void ListadoDePasajerosPorCodigoActivo(ePasajero vec[],int tam);

/// @fn void listarPasajeros(ePasajero[], int)
/// @brief lista los pasajeros del vector de estructura
///
/// @pre
/// @post
/// @param vector de estructura
/// @param tamaño del vector
void listarPasajeros(ePasajero vec[],int tam);

/// @fn int buscarActivos(ePasajero[], int)
/// @brief busca los pasajeros con el tipo de vuelo activo en un vector de estructura
///
/// @pre
/// @post
/// @param vector de estructura
/// @param tamaño del vector
/// @return 1 si escuentra estado de vuelos activo y 0 si no hay pasajeros con el estado de vuelo activo
int buscarActivos(ePasajero vec[],int tam);



#endif /* FUNCIONESPASAJEROS_H_ */
