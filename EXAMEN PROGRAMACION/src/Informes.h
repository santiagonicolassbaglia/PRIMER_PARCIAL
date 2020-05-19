/*
 * Informes.h
 *
 *  Created on: May 5, 2020
 *      Author: Mauro
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int info_imprimirClientePorIdPubPau(publicidad* arraypublicidades,int limitepublicidades,Cliente* arrayClientes,int limiteClientes,int auxiliarId);
int info_imprimirClientePorIdPubAct(publicidad* arraypublicidades,int limitepublicidades,Cliente* arrayClientes,int limiteClientes,int auxiliarId);
int info_imprimirClientePorEst(publicidad* arraypublicidades,int limitepublicidades,Cliente* arrayClientes,int limiteClientes);
int info_imprimirPublicidadPorCuit(publicidad* arraypublicidades,int limitepublicidades,Cliente* arrayClientes,int limiteClientes);
int info_imprimirAvisosPausadosCliente(Cliente* pArray, int len, int idCliBuscado, int cantAvisos);
int info_calcularEImprmirAvisosCliente(Cliente* pArrayCli, int lenCli, publicidad* pArrayPub, int lenPub, int estado);
int info_imprimirClientePausados(publicidad* arraypublicidades,int limitepublicidades,Cliente* arrayClientes,int limiteClientes);
int info_imprimirAvisosCliente(Cliente* pArray, int len, int idCliBuscado, int cantAvisos);
int info_imprimirAvisosActivosCliente(Cliente* pArray, int len, int idCliBuscado, int cantAvisos);


int info_buscarRubro(publicidad* pArray, int len, int rubro);
int info_contPubliByRubro(publicidad* pArrayPub, int lenPub, int rubro);
int info_imprimirPubActivasByRubro(publicidad* pArray, int len, int rubro);
int info_imprimirMaximosMinimosPubByRubros(publicidad* pArray, int len, int MaxiOrMin);
/*int info_imprimirContratacionesConImporte(Contratacion* arrayContrataciones,int limiteContrataciones,Pantalla* arrayPantallas,int limitePantallas,char* auxiliarCuit);
int info_imprimirContratacionesConImportePorCliente(Contratacion* arrayContrataciones,int limiteContrataciones,Pantalla* arrayPantallas,int limitePantallas);
int info_calcularDeudaCliente(Contratacion* arrayContrataciones,int limiteContrataciones,Pantalla* arrayPantallas,int limitePantallas,char* auxiliarCuit, float* deuda);*/
#endif /* INFORMES_H_ */
