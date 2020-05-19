/*
 * Producto.c
 *
 *  Created on: Apr 23, 2020
 *      Author: Mauro
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "cliente.h"
#include "publicidad.h"

/**
 * \brief Imprime los datos de un pubente
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimir(publicidad* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - Texto: %s - Rubro: %d - Id Cliente: %d - Estado: %s",pElemento->idPublicacion,pElemento->texto,pElemento->rubro,pElemento->idCliente,pElemento->estado);
	}
	return retorno;
}

/**
 * \brief Imprime el array de contrataciones
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimirArray( publicidad* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			pub_imprimir(&array[i]);
		}
	}
	return respuesta;
}


/**
 * \brief Inicializa el array
 * \param array Array de pubentes a ser actualizado
 * \param limite Limite del array de pubentes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_inicializarArray(publicidad* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta un pubente en una posicion del array
 * \param array Array de pubentes a ser actualizado
 * \param limite Limite del array de pubentes
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al pubente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_altaArray(publicidad* array,int limite, int indice, int* idPublicacion, int idCliente)
{
	int respuesta = -1;
	publicidad auxiliar;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idPublicacion != NULL)
	{
		if(	!utn_getDescripcion(auxiliar.texto,TEXTO_LEN,"\nTEXTO DEL AVISO:? ", "\nError",2) &&
			!utn_getNumero(&auxiliar.rubro,"\n RUBRO? ", "\nError",1,50,2)&&
			!utn_getNombre(auxiliar.estado,ESTADO_LEN,"\nINGRESE [ACTIVA] o [PAUSADA]","\nError",3))


		{
			respuesta = 0;
			auxiliar.idCliente = idCliente;
			auxiliar.idPublicacion = *idPublicacion;
			auxiliar.isEmpty = 0;
			array[indice] = auxiliar;
			(*idPublicacion)++;
		}
	}
	return respuesta;
}






/**
 * \brief Da de alta un pubente en una posicion del array modo TEST
 * \param array Array de pubentes a ser actualizado
 * \param limite Limite del array de pubentes
 * \param indice Posicion a ser actualizada
 * \param id ID a ser asignado al pubente
 *  *
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_altaTestArray(publicidad* array,int limite, int indice, int* id, publicidad auxiliar)
{
	int respuesta = -1;

	if(array != NULL && limite > 0 && indice < limite)
	{
		respuesta = 0;
		array[indice] = auxiliar;
		array[indice].isEmpty = 0;
		array[indice].idPublicacion = *id;
		*id = *id + 1;
	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un pubente en una posicion del array
 * \param array Array de pubentes a ser actualizado
 * \param limite Limite del array de pubentes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_modificarArray(publicidad* array,int limite, int indice)
{
	int respuesta = -1;
	publicidad auxiliar;
	if(array != NULL && limite > 0 && indice < limite)
	{
		if(	!utn_getDescripcion(auxiliar.texto,TEXTO_LEN,"\nTEXTO DEL AVISO:? ", "\nError",2) &&

				!utn_getNumero(&auxiliar.rubro,"\n RUBRO? ", "\nError",1,50,2))
		{
			respuesta = 0;
			array[indice] = auxiliar;
			array[indice].isEmpty = 0;
		}
	}
	return respuesta;
}
/**
 * \brief Actualiza una posicion del array
 * \param array Array de pubentes a ser actualizado
 * \param limite Limite del array de pubentes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_bajaArray(publicidad* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite)
	{
		respuesta = 0;
		array[indice].isEmpty = 1;
	}
	return respuesta;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array pubente Array de pubente
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int pub_buscarId(publicidad array[], int limite, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!= NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==0 && array[i].idPublicacion==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}



/**
 * \brief Buscar primer posicion vacia
 * \param array Array de pubentes
 * \param limite Limite del array de pubentes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int pub_getEmptyIndex(publicidad* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Ordenar el array de pubentes por nombre
 * \param array Array de pubentes
 * \param limite Limite del array de pubentes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
/*int pub_ordenarPorNombre(publicidad* array,int limite)
{
	int respuesta = -1;
	int i;
	int flagSwap;
	publicidad auxiliar;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{

				if(	array[i].isEmpty == 0 &&
					array[i+1].isEmpty == 0 &&
					strncmp(array[i].archivo,array[i+1].archivo,NOMBRE_PUB) > 0)
				{
					auxiliar = array[i];
					array[i]= array[i+1];
					array[i+1] = auxiliar;
					flagSwap = 1;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}

*/







int pub_altaForzada(publicidad* array,int limite, int indice, int* idPublicacion, int idCliente,char* texto,int rubro,char* estado)
{
	int respuesta = -1;
	publicidad auxiliar;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idPublicacion != NULL)

		{




		strncpy(auxiliar.texto, texto, TEXTO_LEN);
		strncpy(auxiliar.estado, estado, ESTADO_LEN);

		        auxiliar.rubro= rubro;

				auxiliar.idCliente = idCliente;
				respuesta = 0;
				auxiliar.idPublicacion = *idPublicacion;
				auxiliar.isEmpty = 0;
				array[indice] = auxiliar;
				(*idPublicacion)++;


		}

	return respuesta;
}




int pub_modificarEstado(publicidad* array,int limite, int indice)
{
	int respuesta = -1;
	publicidad auxiliar;


	if(array != NULL && limite > 0 && indice < limite)
	{
		if(
		    !utn_getNombre(auxiliar.estado,ESTADO_LEN,"\n Estado? ", "\nError",2))



		{
			strncpy(array[indice].estado,"pausado",ESTADO_LEN);
			respuesta = 0;
			array[indice].isEmpty = 0;
		}
	}
	return respuesta;
}






int pub_contAviAct(publicidad* pArray, int len, int idCli)
{
	int retorno = -1;
	int i;
	int contAviAct=0;

	if(pArray != NULL && len > 0 && idCli > -1 )//Valida que los datos de la funcion sean correctos.
	{
		for(i=0;i<len;i++)
		{
			if( strcmp(pArray[i].estado,"activo")==0 &&
				pArray[i].isEmpty == 0 &&
				pArray[i].idCliente == idCli)//Valida que este "cargado" y "activo" el indice y que se encuentre el ID brindado.
			{
				contAviAct++;//Incrementa el contador de avisos activos.
			}
		}
		retorno = contAviAct;//Retorna la cantidad de numeros de avisos activos encontrados.
	}
	return retorno;
}














int pub_contAviPau(publicidad* pArray, int len, int idCli)
{
	int retorno = -1;
	int i;
	int contAviPau=0;

	if(pArray != NULL && len > 0 && idCli > -1 )
	{
		for(i=0;i<len;i++)
		{
			if( ( strcmp(pArray[i].estado,"pausado")) == 0 &&
				pArray[i].isEmpty == 0 &&
				pArray[i].idCliente == idCli)//Valida que este "cargado" y "pausado" el indice y que se encuentre el ID brindado.
			{
				contAviPau++;//Incrementa el contador de avisos pausados.
			}
		}
		retorno = contAviPau;//Retorna la cantidad de numeros de avisos pausados encontrados.
	}
	return retorno;
}










int pub_contAvisos(publicidad* pArray, int len, int idCli)
{
	int retorno = -1;
	int i;
	int contAvisos=0;

	if(pArray != NULL && len > 0 && idCli > -1 )//Valida que los datos de la funcion sean correctos.
	{
		for(i=0;i<len;i++)
		{
			if(	pArray[i].isEmpty == 0 &&
				pArray[i].idCliente == idCli)//Valida que este "cargado el indice y que se encuentre el ID brindado.
			{
				contAvisos++;//Incrementa el contador de avisos.
			}
		}
		retorno = contAvisos;//Retorna la cantidad de numeros de avisos encontrados.
	}
	return retorno;
}



