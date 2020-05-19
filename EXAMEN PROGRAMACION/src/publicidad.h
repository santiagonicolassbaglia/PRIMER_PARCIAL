/*
 * publicidad.h
 *
 *  Created on: 30 abr. 2020
 *      Author: admin
 */
#ifndef publicidad_H_
#define publicidad_H_


#define TEXTO_LEN 64
#define ESTADO_LEN 50

typedef struct
{
	char texto[TEXTO_LEN];
	int idCliente;
	int rubro;
	char estado[ESTADO_LEN];
	int idPublicacion;
	int isEmpty;
}publicidad;

int pub_imprimir(publicidad* auxProducto);
int pub_inicializarArray(publicidad* array,int limite);
int pub_altaArray(publicidad* array,int limite, int indice, int* idPublicacion, int idPantalla);
int pub_getEmptyIndex(publicidad* array,int limite);
int pub_imprimirArray(publicidad* array,int limite);
int pub_buscarId(publicidad array[], int limite, int valorBuscado);
int pub_ordenarPorNombre(publicidad* array,int limite);
int pub_modificarArray(publicidad* array,int limite, int indice);
int pub_bajaArray(publicidad* array,int limite, int indice);


int pub_altaForzada(publicidad* array,int limite, int indice, int* idPublicacion, int idCliente,char* texto,int rubro,char* estado);
int pub_modificarEstado(publicidad* array,int limite, int indice);
int info_imprimirClientePorEstado(publicidad* arraypublicidades,int limitepublicidades,Cliente* arrayClientes,int limiteClientes,int auxiliarId);


int pub_contAviAct(publicidad* pArray, int len, int idCli);
int pub_contAviPau(publicidad* pArray, int len, int idCli);
int pub_contAvisos(publicidad* pArray, int len, int idCli);
#endif /* PUBLICIDAD_H_ */

