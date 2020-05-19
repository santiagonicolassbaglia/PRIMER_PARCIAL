/*
 * >>>> CLASE 10 <<<<
 *
 * Desarrollar una aplicacion que permita gestionar una array de Clientes
 *
 * Se debera poder realizar
 * 	ALTAS
 * 	BAJAS
 * 	MODIFICACIONES
 *
 * La aplicacion debera permitir ordenar el array por Nombre del cliente
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "utn.h"
#include "publicidad.h"
#include "informes.h"


#define OPCION_LEN 2
#define CANTIDAD_CLIENTES 100
#define CANTIDAD_PUBLICACION 1000
int main(void) {

	setbuf(stdout,NULL);

     	publicidad arrayPublicaciones[CANTIDAD_PUBLICACION];
		Cliente arrayClientes[CANTIDAD_CLIENTES];
		int idClientes=0;
		int idPublicaciones=0;
		int opcion;
		int auxiliarIndice;
		int auxiliarId;
		int auxiliarIdPublicacion;
		int auxiliarIndicePublicacion;
		int auxNumRubro;


if(cli_inicializarArray(arrayClientes,CANTIDAD_CLIENTES) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}
if(pub_inicializarArray(arrayPublicaciones,CANTIDAD_PUBLICACION) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}

cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,0,&idClientes,"joseph","flores","23-40040804");
cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,1,&idClientes,"santi","sbaglia","23-50041604");
cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,2,&idClientes,"marcos","araya","23-60040804");

pub_altaForzada(arrayPublicaciones,CANTIDAD_PUBLICACION,0,&idPublicaciones,1,"texto 1", 2,"activo");
pub_altaForzada(arrayPublicaciones,CANTIDAD_PUBLICACION,1,&idPublicaciones,2,"texto 2", 3,"activo");
pub_altaForzada(arrayPublicaciones,CANTIDAD_PUBLICACION,2,&idPublicaciones,1,"texto 3", 4,"pausado");
pub_altaForzada(arrayPublicaciones,CANTIDAD_PUBLICACION,3,&idPublicaciones,1,"texto 4", 4,"pausado");
pub_altaForzada(arrayPublicaciones,CANTIDAD_PUBLICACION,4,&idPublicaciones,2,"texto 5", 2,"activo");



do
	{
		if(!utn_getNumero(	&opcion,
				"\n\n1.Cargar un cliente"
				"\n2.Modificar un cliente"
				"\n3.Eliminar un cliente"
				"\n4.Contratar una publicidad"
				"\n5.Pausar publicacion"
				"\n6.Reanudar Publicacion"
				"\n7.Imprimir clientes"
				"\n8.Imprimir Publicaciones"
				"\n9.Informar clientes"
				"\n10.Informar Publicaciones"
				"\n11.imprimir"
				"\n12.Salir\n\n",

				"\nError opcion invalida",1,11,2) )
		{
			switch(opcion)
			{
			case 1:
				auxiliarIndice = cli_getEmptyIndex(arrayClientes,CANTIDAD_CLIENTES);
				if(auxiliarIndice >= 0)
				{
					if(cli_altaArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice,&idClientes) == 0)
					{
						printf("\nCarga realizada con exito\n");
					}
				}
				else
				{
					printf("\nNO HAY MAS LUGAR");
				}
				break;
			case 2:
				cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del cliente a modificar","\nID invalido",0,idClientes,0) == 0)
				{
					auxiliarIndice = cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						cli_modificarArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice) == 0)
					{
						printf("\nModificacion realizada con exito\n");
					}
				}
				break;

			case 3:
				cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del cliente a eliminar","\nID invalido",0,idClientes,0)==0)
				{
					auxiliarIndice = cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						cli_bajaArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice)== 0)
					{
						printf("\nBaja realizada con exito\n");
					}
				}
				break;
			case 4:
				auxiliarIndicePublicacion = pub_getEmptyIndex(arrayPublicaciones,CANTIDAD_PUBLICACION);
								if(auxiliarIndicePublicacion >= 0)
								{
									cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
									if(	utn_getNumero(&auxiliarId,"\nId Cliente: ","\nError",0,10000,2) == 0 &&
										cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId) != -1)
									{
										pub_altaArray(arrayPublicaciones,CANTIDAD_PUBLICACION,auxiliarIndicePublicacion,&idPublicaciones,auxiliarId);
									}
									else
									{
										printf("\nEL ID NO EXISTE");
									}
								}
				break;

			case 5:

				pub_imprimirArray(arrayPublicaciones,CANTIDAD_PUBLICACION);
				if(	!utn_getNumero(&auxiliarIdPublicacion,"\n Id plublicacion? ", "\nError",0,20000,2)
				&& !info_imprimirClientePorIdPubPau(arrayPublicaciones,CANTIDAD_PUBLICACION,arrayClientes,CANTIDAD_CLIENTES,auxiliarIdPublicacion))
								{

									printf("Cambios realizados");

								}
								else
								{
									printf("\nId NO ENCONTRADO");
								}

				break;



			case 6:

				pub_imprimirArray(arrayPublicaciones,CANTIDAD_PUBLICACION);
							if(	!utn_getNumero(&auxiliarIdPublicacion,"\n Id plublicacion? ", "\nError",0,20000,2)
							&& !info_imprimirClientePorIdPubAct(arrayPublicaciones,CANTIDAD_PUBLICACION,arrayClientes,CANTIDAD_CLIENTES,auxiliarIdPublicacion))
									{

										printf("Cambios realizados");

									}
									else
									{
										printf("\nId NO ENCONTRADO");
									}



						break;

					case 7:
								if(	!info_imprimirClientePorEst(arrayPublicaciones,CANTIDAD_PUBLICACION,arrayClientes,CANTIDAD_CLIENTES))
								{

									printf("Cambios realizados");

								}
								else
								{
									printf("\nId NO ENCONTRADO");
								}




						break;
					case 8:

						if(	!info_imprimirPublicidadPorCuit(arrayPublicaciones,CANTIDAD_PUBLICACION,arrayClientes,CANTIDAD_CLIENTES))
														{

															printf("Cambios realizados");

														}
														else
														{
															printf("\nId NO ENCONTRADO");
														}
					//	cli_ordenarPorNombre(arrayClientes,CANTIDAD_CLIENTES);
						break;

					case 9:
					//Informar clientes.




						do
						{
							if(!utn_getNumero(&opcion,"Por favor, ingrese una opcion:\n"//Le solicita al usuario una letra para seleccionar la opcion deseable.
						     "\t1.- Cliente con más avisos activos.\n"
							 "\t2.- Cliente con más avisos pausados.\n"//Menu de opciones a ingresar por el usuario.
							 "\t3.- Cliente con más avisos.\n"
							 "\t4.- Volver al menú principal.\n","No valido.\n",1,5,2))//Compara si el string obtenido es igual a A.
							{

								switch(opcion)
								{
								case 1 :

								if(!info_calcularEImprmirAvisosCliente(arrayClientes,CANTIDAD_CLIENTES,arrayPublicaciones,CANTIDAD_PUBLICACION,1))//Busca e imprime los datos del cliente con mas publicaciones sin distinguir A o P(3).
								{
									printf("\nProcesado correctamente.\n");//Mensaje a imprimir si cumple las validaciones del IF.
								}
								break;



								case 2:

								if(!info_calcularEImprmirAvisosCliente(arrayClientes,CANTIDAD_CLIENTES,arrayPublicaciones,CANTIDAD_PUBLICACION,2))//Busca e imprime los datos del cliente con mas publicaciones Pausadas (2).
								{
									printf("\nProcesado correctamente.\n");//Mensaje a imprimir si cumple las validaciones del IF.
								}
				              break;




								case 3:

									if(!info_calcularEImprmirAvisosCliente(arrayClientes,CANTIDAD_CLIENTES,arrayPublicaciones,CANTIDAD_PUBLICACION,3))//Busca e imprime los datos del cliente con mas publicaciones Activas (1).
									{
										printf("\nProcesado correctamente.\n");//Mensaje a imprimir si cumple las validaciones del IF.
									}
						  	break;



								}






						}	}while(opcion != 4);




             break;








			case 10:



                 do
					{
						if(!utn_getNumero(&opcion,"Por favor, ingrese una opcion:\n"//Le solicita al usuario una letra para seleccionar la opcion deseable.
						 "\t1.- Cantidad de publicaciones de un rubro.\n"
						 "\t2.- Rubro con más publicaciones activas.\n"//Menu de opciones a ingresar por el usuario.
						 "\t3.- Rubro con menos publicaciones activas.\n"
						 "\t4.- Volver al menú principal\n","No valido.\n",1,5,2))//Compara si el string obtenido es igual a A.
						{

							switch(opcion)
							{
							case 1 :

								if( !utn_getNumero(&auxNumRubro,"Ingrese el numero de Rubro:\n","Rubro invalido.\n",0,1000,0) &&//Le solicita al usuario un numero y se lo asigna a auxNumRubro.
							info_buscarRubro(arrayPublicaciones,CANTIDAD_PUBLICACION,auxNumRubro) != -1 &&//Busca el numero de rubro asignado a auxNumRubro y lo busca en el array de publicaciones.
							!info_imprimirPubActivasByRubro(arrayPublicaciones,CANTIDAD_PUBLICACION,auxNumRubro) )//Imprime la cantidad de publicaciones activas del rubro asignado auxNumRubro.
						{
							printf("\nBusqueda exitosa!.\n");//Mensaje a imprimir si cumple las validaciones del IF.
						}
						else
						{
							printf("El rubro ingresado no existe.\n");//Mensaje a imprimir si el rubro ingresado no existe.
							break;
						}
							break;



							case 2:

							if(!info_imprimirMaximosMinimosPubByRubros(arrayPublicaciones,CANTIDAD_PUBLICACION,1))//Busca e imprime los datos del cliente con mas publicaciones Pausadas (2).
							{
								printf("\nProcesado correctamente.\n");//Mensaje a imprimir si cumple las validaciones del IF.
							}
						  break;




							case 3:

								if(!info_imprimirMaximosMinimosPubByRubros(arrayPublicaciones,CANTIDAD_PUBLICACION,0))//Busca e imprime los datos del cliente con mas publicaciones Activas (1).
								{
									printf("\nProcesado correctamente.\n");//Mensaje a imprimir si cumple las validaciones del IF.
								}
						break;



							}






					}	}while(opcion != 4);




				break;



			case 11:
				printf("\tLISTA DE CLIENTES\n");
				cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
				printf("\n\n\tLISTA DE PUBLICACIONES\n");
				pub_imprimirArray(arrayPublicaciones, CANTIDAD_PUBLICACION);
				break;

						}
					}
				}while(opcion != 12);

				return EXIT_SUCCESS;
			}





