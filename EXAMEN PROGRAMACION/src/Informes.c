/*
 * Informes.c
 *
 *  Created on: May 5, 2020
 *      Author: Mauro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "publicidad.h"
#include "utn.h"
#include "Informes.h"


int info_imprimirClientePorIdPubPau(publicidad* arraypublicidades,int limitepublicidades,Cliente* arrayClientes,int limiteClientes,int auxiliarId)
{
	int retorno = -1;
	int i;
	int indiceArrayCliente;
	int idCliente;
	int opcion = 0;
	if(arraypublicidades != NULL && limitepublicidades > 0 && arrayClientes != NULL && limiteClientes > 0 && auxiliarId > 0)
	{
		for(i=0;i<limitepublicidades;i++)
		{
			if(arraypublicidades[i].isEmpty == 0 &&  arraypublicidades[i].idPublicacion==auxiliarId)
			{
				retorno = 0;
				idCliente = arraypublicidades[i].idCliente;
				indiceArrayCliente = cli_buscarId(arrayClientes,limiteClientes,idCliente);


				printf("\nID : %d - NOMBRE: %s - APELLIDO: %s - CUIT: %s",arrayClientes[indiceArrayCliente].id,arrayClientes[indiceArrayCliente].nombre,arrayClientes[indiceArrayCliente].apellido,arrayClientes[indiceArrayCliente].cuit);

				printf("quiere modificar el estado 1[si], 2 [no]?");
				scanf( "%d", &opcion);
				if(opcion == 1)
				{
					strcpy(arraypublicidades[i].estado,"pausado");
					printf("Estado: %s", arraypublicidades[i].estado);
				}else
				{
					printf("no se modificaron los datos.");
					break;
				}

			}
		}
	}
	return retorno;
}







int info_imprimirClientePorIdPubAct(publicidad* arraypublicidades,int limitepublicidades,Cliente* arrayClientes,int limiteClientes,int auxiliarId)
{
	int retorno = -1;
	int i;
	int indiceArrayCliente;
	int idCliente;
	int opcion = 0;
	if(arraypublicidades != NULL && limitepublicidades > 0 && arrayClientes != NULL && limiteClientes > 0 && auxiliarId > 0)
	{
		for(i=0;i<limitepublicidades;i++)
		{
			if(arraypublicidades[i].isEmpty == 0 &&  arraypublicidades[i].idPublicacion==auxiliarId)
			{
				retorno = 0;
				idCliente = arraypublicidades[i].idCliente;
				indiceArrayCliente = cli_buscarId(arrayClientes,limiteClientes,idCliente);


				printf("\nID : %d - NOMBRE: %s - APELLIDO: %s - CUIT: %s",arrayClientes[indiceArrayCliente].id,arrayClientes[indiceArrayCliente].nombre,arrayClientes[indiceArrayCliente].apellido,arrayClientes[indiceArrayCliente].cuit);

				printf("quiere modificar el estado 1[si], 2 [no]?");
				scanf( "%d", &opcion);
				if(opcion == 1)
				{
					strcpy(arraypublicidades[i].estado,"activo");
					printf("Estado: %s", arraypublicidades[i].estado);
				}else
				{
					printf("no se modificaron los datos.");
					break;
				}

			}
		}
	}
	return retorno;
}






int info_imprimirClientePorEst(publicidad* arraypublicidades,int limitepublicidades,Cliente* arrayClientes,int limiteClientes)
{
	int retorno = -1;
	int i;
	int indiceCli;
	if(arraypublicidades != NULL && limitepublicidades > 0 && arrayClientes != NULL && limiteClientes > 0)
		{
			for(i=0;i<limitepublicidades;i++)
			{
				indiceCli = cli_buscarId(arrayClientes, limiteClientes, arraypublicidades[i].idCliente);

				if(arraypublicidades[i].isEmpty != 1 && strcmp(arraypublicidades[i].estado,"activo")==0)
				{
					printf("%s - %s- %s - %s\n", arrayClientes[indiceCli].nombre, arrayClientes[indiceCli].apellido, arrayClientes[indiceCli].cuit, arraypublicidades[i].estado);
				}



			}
		}



	return retorno;
}

int info_imprimirPublicidadPorCuit(publicidad* arraypublicidades,int limitepublicidades,Cliente* arrayClientes,int limiteClientes)
{
	int retorno = -1;
	int i;
	int indiceCli;
	if(arraypublicidades != NULL && limitepublicidades > 0 && arrayClientes != NULL && limiteClientes > 0)
		{
			for(i=0;i<limitepublicidades;i++)
			{
				indiceCli = cli_buscarId(arrayClientes, limiteClientes, arraypublicidades[i].idCliente);

				if(arraypublicidades[i].isEmpty != 1)
				{
					printf("%s - %s- %d - %s\n", arrayClientes[indiceCli].cuit, arraypublicidades[i].texto, arraypublicidades[i].rubro, arraypublicidades[i].estado);
				}



			}
		}



	return retorno;
}















int info_calcularEImprmirAvisosCliente(Cliente* pArrayCli, int lenCli, publicidad* pArrayPub, int lenPub, int estado)
{
	int retorno = -1;
	int i;
	int cantAvisosByCli;
	int idCliAvisos;
	int cantidadAvisos;
	int flag=0;

	if(pArrayCli != NULL && lenCli > 0 && pArrayPub != NULL && lenPub )//Valida que los datos de la funcion sean correctos.
	{
		switch(estado)//Valida lo que se desea calcular e imprimir. 1 = SOLO ACTIVOS; 2 = SOLO PAUSADOS; 3 = GENERAL.
		{
			case 1:

				for(i=0;i<lenCli;i++)//Recorre el array de clientes.
				{
					if( pArrayCli[i].isEmpty == 0 )//Valida que el indice este "cargado".
					{
						cantAvisosByCli = pub_contAviAct(pArrayPub,lenPub,pArrayCli[i].id);//Contador de avisos activos.
						if( flag == 0 || cantAvisosByCli > cantidadAvisos)//Busca el Cliente con mas avisos activos.
						{
							flag = 1;
							idCliAvisos = pArrayCli[i].id;
							cantidadAvisos = cantAvisosByCli;
						}
						retorno=0;
					}
				}
				if( cantidadAvisos >0 &&
					!info_imprimirAvisosActivosCliente(pArrayCli,lenCli,idCliAvisos,cantidadAvisos))//Imprime el cliente con mas avisos activos.
				{
					printf("\nBusqueda exitosa!.");


				}
				else
				{
					printf("\nNo existen usuarios con publicaciones en estado Activo.");
				}
				break;

			case 2:

				for(i=0;i<lenCli;i++)//Recorre el array de clientes.
				{
					if( pArrayCli[i].isEmpty == 0 )//Valida que el indice este "cargado".
					{
						cantAvisosByCli = pub_contAviPau(pArrayPub,lenPub,pArrayCli[i].id);//Contador de avisos pausados.
						if( flag == 0 || cantAvisosByCli > cantidadAvisos)//Busca el Cliente con mas avisos pausados.
						{
							flag = 1;
							idCliAvisos = pArrayCli[i].id;
							cantidadAvisos = cantAvisosByCli;
						}
						retorno=0;
					}
				}
				if( cantidadAvisos >0 &&
					!info_imprimirAvisosPausadosCliente(pArrayCli,lenCli,idCliAvisos,cantidadAvisos))//Imprime el cliente con mas avisos pausados.
				{
					printf("\nBusqueda exitosa!.");

				}
				else
				{
					printf("\nNo existen usuarios con publicaciones en estado Pausada.");
				}
				break;

			case 3:

				for(i=0;i<lenCli;i++)//Recorre el array de clientes.
				{
					if( pArrayCli[i].isEmpty == 0 )//Valida que el indice este "cargado".
					{
						cantAvisosByCli = pub_contAvisos(pArrayPub,lenPub,pArrayCli[i].id);//Contador de avisos generales.
						if( flag == 0 || cantAvisosByCli > cantidadAvisos)//Busca el Cliente con mas avisos generales.
						{
							flag = 1;
							idCliAvisos = pArrayCli[i].id;
							cantidadAvisos = cantAvisosByCli;
						}
						retorno=0;
					}
				}
				if( cantidadAvisos >0 &&
					!info_imprimirAvisosCliente(pArrayCli,lenCli,idCliAvisos,cantidadAvisos))//Imprime el cliente con mas avisos generales.
				{
					printf("\nBusqueda exitosa!.");
				}
				else
				{
					printf("\nNo existen usuarios con publicaciones.");
				}
				break;
		}
	}
	return retorno;
}







int info_imprimirClientePausados(publicidad* arraypublicidades,int limitepublicidades,Cliente* arrayClientes,int limiteClientes)
{
	int retorno = -1;
	int i;
	int indiceCli;
	if(arraypublicidades != NULL && limitepublicidades > 0 && arrayClientes != NULL && limiteClientes > 0)
		{
			for(i=0;i<limitepublicidades;i++)
			{
				indiceCli = cli_buscarId(arrayClientes, limiteClientes, arraypublicidades[i].idCliente);

				if(arraypublicidades[i].isEmpty != 1 && strcmp(arraypublicidades[i].estado,"pausado")==0)
				{
					printf("%s - %s- %s - %s\n", arrayClientes[indiceCli].nombre, arrayClientes[indiceCli].apellido, arrayClientes[indiceCli].cuit, arraypublicidades[i].estado);
				}



			}
		}


	return retorno;
}







int info_imprimirAvisosPausadosCliente(Cliente* pArray, int len, int idCliBuscado, int cantAvisos)
 {
 	int retorno = -1;
 	int i;
 	if(pArray != NULL && len > 0 && idCliBuscado > -1)//Valida que los datos de la funcion sean correctos.
 	{
 		for(i=0;i<len;i++)
 		{
 			if( pArray[i].isEmpty == 0 &&
 				pArray[i].id == idCliBuscado )//Valida que el indice este "cargado" y que encuentra el id buscado.
 			{
 				retorno = 0;

 				printf("\nEl cliente con mas cantidad de avisos pausados (%d) es: %s, %s - Cuit: %s.",cantAvisos,pArray[i].apellido,pArray[i].nombre,pArray[i].cuit);
 			}
 		}
 	}
 	return retorno;
 }









int info_imprimirAvisosCliente(Cliente* pArray, int len, int idCliBuscado, int cantAvisos)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && len > 0 && idCliBuscado > -1)//Valida que los datos de la funcion sean correctos.
	{
		for(i=0;i<len;i++)
		{
			if( pArray[i].isEmpty == 0 &&
				pArray[i].id == idCliBuscado )//comparo los id .. y si contiene el id que estoy buscando entra al if
			{
				retorno = 0;
				printf("\nEl cliente con mas cantidad de avisos (%d) es: %s, %s - Cuit: %s.",cantAvisos,pArray[i].apellido,pArray[i].nombre,pArray[i].cuit);
			}
		}
	}
	return retorno;
}






 int info_imprimirAvisosActivosCliente(Cliente* pArray, int len, int idCliBuscado, int cantAvisos)
 {
 	int retorno = -1;
 	int i;
 	if(pArray != NULL && len > 0 && idCliBuscado > -1)//Valida que los datos de la funcion sean correctos.
 	{
 		for(i=0;i<len;i++)
 		{
 			if( pArray[i].isEmpty == 0 &&
 				pArray[i].id == idCliBuscado )//Valida que el indice este "cargado" y que encuentra el id buscado.
 			{
 				retorno = 0;
 				printf("\nEl cliente con mas cantidad de avisos activos (%d) es: %s, %s - Cuit: %s.",cantAvisos,pArray[i].apellido,pArray[i].nombre,pArray[i].cuit);
 			}
 		}
 	}
 	return retorno;
 }





 //10-1




 int info_buscarRubro(publicidad* pArray, int len, int rubro)
 {
 	int retorno = -1;
 	int i;

 	if(pArray != NULL && len > 0 && rubro > 0 )//Valida que los datos de la funcion sean correctos.
 	{
 		for(i=0;i<len;i++)
 		{
 			if( pArray[i].isEmpty == 0 &&
 				pArray[i].rubro == rubro	)//Valida que el indice este "cargado" y encontrar el numero de rubro.
 			{
 				retorno = rubro;//Retorna el numero de rubro.
 				break;
 			}
 		}
 	}
 	return retorno;
 }






int info_contPubliByRubro(publicidad* pArrayPub, int lenPub, int rubro)
 {
 	int retorno = -1;
 	int i;
 	int contRubro=0;

 	if(pArrayPub != NULL && lenPub > 0 && rubro > -1 )//Valida que los datos de la funcion sean correctos.
 	{
 		for(i=0;i<lenPub;i++)//Recorre el array de publicaciones.
 		{
 			if( pArrayPub[i].isEmpty == 0 &&
 			strcmp(pArrayPub[i].estado,"activo")==0 &&
 				pArrayPub[i].rubro == rubro)//comparo los rubros.. y si contiene el rubro que estoy buscando entra al if
 			{
 				contRubro++;//Incrementa la cantidad de publicaciones activas.
 			}
 		}
 		retorno = contRubro;//Devuelve el numero de publicaciones activas.
 	}
 	return retorno;
 }






 int info_imprimirPubActivasByRubro(publicidad* pArray, int len, int rubro)
 {
 	int retorno = -1;
 	int cantiPub;

 	if(pArray != NULL && len >0 && rubro >-1)//Valida que los datos de la funcion sean correctos.
 	{
 		cantiPub = info_contPubliByRubro(pArray,len,rubro);//Calcula las publicaciones.
 		retorno = 0;
 		printf("El rubro '%d', posee %d publicaciones activas.",rubro,cantiPub);
 	}
 	return retorno;
 }






//10-2



 int info_imprimirMaximosMinimosPubByRubros(publicidad* pArray, int len, int MaxiOrMin)
 {
 	int retorno = -1;
 	int i;
 	int j;
 	int listaRubros[len];
 	int flagRubro;
 	int flagMaximoRubro = 0;
 	int cantiPub;
 	int maxCantPubByRubro;
 	int numeroRubro;
 	int indiceRubroLibre = 0;

 	for(i=0;i<len;i++)
 	{
 		flagRubro = 0;
 		if(pArray[i].isEmpty == 0)//Valida que el indice este "cargado".
 		{
 			for(j=0;j<indiceRubroLibre;j++)// recorre las distintas posiciones de mi lista de cuits, hasta lo que encontre .... como "J" a lo primero no va a ser nunca > a 0 pasa directamente para abajo. cuando a hay uno lo compara con el que esta en la posicion 0
 			{
 				if(pArray[i].rubro == listaRubros[j])// con esto se sabe o no se sabe si el cuit se repite
 				{
 					flagRubro = 1; // datos que ya se verificaron .. no se repitan
 					break;
 				}
 			}

 			if( flagRubro == 0 &&
 				MaxiOrMin == 1)//Si no encuentra el rubro cargado y el objetivo es buscar el maximo, entra al IF.
 			{
 				listaRubros[indiceRubroLibre] = pArray[i].rubro;//copia el primer dato del rubro del array publicaciones a la listaRubros.

 				cantiPub = info_contPubliByRubro(pArray,len,listaRubros[indiceRubroLibre]);//Calcula la cantidad de publicaciones activas de un rubro.
 				if(i == 0 || cantiPub > maxCantPubByRubro)//Determina la maxima cantidad de rubros con publicaciones activas.
 				{
 					flagMaximoRubro = 1;
 					numeroRubro = listaRubros[indiceRubroLibre];//NUEVO MAXIMO
 					maxCantPubByRubro = cantiPub;
 				}
 				indiceRubroLibre++;//Incrementa el rubro.
 			}
 			if( flagRubro == 0 &&
 				MaxiOrMin == 0)//Si no encuentra el rubro cargado y el objetivo es buscar el minimo, entra al IF.
 			{
 				listaRubros[indiceRubroLibre] = pArray[i].rubro;//copia el rubro del array publicaciones a la listaRubros.
 				cantiPub = info_contPubliByRubro(pArray,len,listaRubros[indiceRubroLibre]);//Calcula la cantidad de publicaciones activas de un rubro.
 				if(flagMaximoRubro == 0 ||  maxCantPubByRubro > cantiPub )//Determina la minima cantidad de rubros con publicaciones activas.
 				{
 					flagMaximoRubro = 1;
 					numeroRubro = listaRubros[indiceRubroLibre];
 					maxCantPubByRubro = cantiPub;
 				}
 				indiceRubroLibre++;//Incrementa el rubro.
 			}
 		}
 	}
 	printf("\n\nEl rubro '%d' posee %d publicaciones activas.\n\n",numeroRubro,maxCantPubByRubro);
 	return retorno;
 }










/*
int info_imprimirpublicidadesConImporte(publicidad* arraypublicidades,int limitepublicidades,Cliente* arrayClientes,int limiteClientes,char* auxiliarCuit)
{
	int retorno = -1;
	int i;
	int indiceArrayCliente;
	int idCliente;
	float auxiliarImporte;
	if(arraypublicidades != NULL && limitepublicidades > 0 && arrayClientes != NULL && limiteClientes > 0 && auxiliarCuit != NULL)
	{
		for(i=0;i<limitepublicidades;i++)
		{
			if(arraypublicidades[i].isEmpty)
			{
				continue;
			}
			if(strncmp(arraypublicidades[i].cuit,auxiliarCuit,CUIT_LEN) == 0)
			{
				retorno = 0;
				idCliente = arraypublicidades[i].idCliente;
				indiceArrayCliente = pan_buscarId(arrayClientes,limiteClientes,idCliente);
				auxiliarImporte = arraypublicidades[i].dias * arrayClientes[indiceArrayCliente].precio;
				printf("\nID: %d - Archivo: %s - Cuit: %s - Dias: %d - IdCliente: %d - Importe %.2f"
															,arraypublicidades[i].id
															,arraypublicidades[i].archivo
															,arraypublicidades[i].cuit
															,arraypublicidades[i].dias
															,arraypublicidades[i].idCliente
															,auxiliarImporte);
			}
		}
	}
	return retorno;
}

#define CANTIDAD_CLIENTES 1000

int info_imprimirpublicidadesConImportePorCliente(publicidad* arraypublicidades,int limitepublicidades,Cliente* arrayClientes,int limiteClientes)
{

	int retorno = -1;
	char listaCuit[CANTIDAD_CLIENTES][CUIT_LEN];
	int i;
	int j;
	int flagExisteCuit;
	int indiceCuitLibre = 0;
	float auxiliarDeuda;
	float deudaMaxima;
	int indiceClienteDeudaMaxima;

	for(i=0;i<limitepublicidades;i++)
	{
		flagExisteCuit = 0;
		if(arraypublicidades[i].isEmpty == 0)
		{
			for(j=0;j<indiceCuitLibre;j++)
			{
				if(strncmp(arraypublicidades[i].cuit,listaCuit[j],CUIT_LEN ) == 0)
				{
					flagExisteCuit = 1;
					break;
				}
			}
			if(flagExisteCuit == 0)
			{
				strncpy(listaCuit[indiceCuitLibre],arraypublicidades[i].cuit,CUIT_LEN);
				indiceCuitLibre++;
			}
		}
	}

	for(j=0;j<indiceCuitLibre;j++)
	{
		printf("\n\n El cliente con cuit %s\n",listaCuit[j]);
		info_imprimirpublicidadesConImporte(arraypublicidades,limitepublicidades,arrayClientes,limiteClientes,listaCuit[j]);
	}



	for(j=0;j<indiceCuitLibre;j++)
	{

		info_calcularDeudaCliente(arraypublicidades,limitepublicidades,arrayClientes,limiteClientes,listaCuit[j], &auxiliarDeuda);
		if(i== 0|| (auxiliarDeuda > deudaMaxima))
		{
			deudaMaxima = auxiliarDeuda;
			indiceClienteDeudaMaxima = 	j;
		}

	}
	printf("\n\n El cliente con mas deuda es cuit %s - debe %.2f\n",listaCuit[indiceClienteDeudaMaxima],deudaMaxima);

	return retorno;



}


int info_calcularDeudaCliente(publicidad* arraypublicidades,int limitepublicidades,Cliente* arrayClientes,int limiteClientes,char* auxiliarCuit, float* deuda)
{
	int retorno = -1;
	int i;
	int indiceArrayCliente;
	int idCliente;
	float auxiliarDeuda=0;
	if(arraypublicidades != NULL && limitepublicidades > 0 && arrayClientes != NULL && limiteClientes > 0 && auxiliarCuit != NULL)
	{
		for(i=0;i<limitepublicidades;i++)
		{
			if(arraypublicidades[i].isEmpty)
			{
				continue;
			}
			if(strncmp(arraypublicidades[i].cuit,auxiliarCuit,CUIT_LEN) == 0)
			{
				idCliente = arraypublicidades[i].idCliente;
				indiceArrayCliente = pan_buscarId(arrayClientes,limiteClientes,idCliente);
				auxiliarDeuda = auxiliarDeuda + (arraypublicidades[i].dias * arrayClientes[indiceArrayCliente].precio);
			}
		}
		retorno = 0;
		*deuda=auxiliarDeuda;
	}
	return retorno;
}

*/


