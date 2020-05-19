/*
 * Producto.h
 *
 *  Created on: Apr 23, 2020
 *      Author: Mauro
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#define NOMBRE_LEN 50
#define CUIT_LEN 110
#define APELLIDO_LEN 50

typedef struct
{
	char nombre[NOMBRE_LEN];
	char apellido[APELLIDO_LEN];
	char cuit[CUIT_LEN];
	int isEmpty;
	int id;
}Cliente;

int cli_imprimir(Cliente* auxProducto);
int cli_inicializarArray(Cliente* array,int limite);
int cli_altaArray(Cliente* array,int limite, int indice, int* id);
int cli_getEmptyIndex(Cliente* array,int limite);
int cli_imprimirArray(Cliente* array,int limite);
int cli_buscarId(Cliente array[], int limite, int valorBuscado);
int cli_ordenarPorNombre(Cliente* array,int limite);
int cli_modificarArray(Cliente* array,int limite, int indice);
int cli_bajaArray(Cliente* array,int limite, int indice);

int cli_altaForzadaArray(Cliente* array,int limite, int indice, int* id,char* nombre,char* apellido, char* cuit);
#endif /* CLIENTE_H_ */
