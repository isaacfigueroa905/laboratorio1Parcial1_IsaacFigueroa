/*
 ============================================================================
 Name        : c.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"


#include "Servicio.h"
#include "Trabajo.h"
#include "Bicicletas.h"
#define T 7




int main(void)
{
	setbuf(stdout,NULL);
		eTrabajo trabajito[T];
		int retornoCarga;
		int retornoEliminar;
		int retornoModificar;
		float gananciaPorTrabajos;
		eServicio servicios[4]= {{20000,"limpieza",250,OCUPADO},{20001,"parche",300,OCUPADO},{20002,"centrado",400,OCUPADO},{20003,"cadena",350,OCUPADO}};
		int banderaIngreso=0;
		int opcion;
		eBicicleta misBicicletas[5]  ={{25,"olmo",18,"azul",OCUPADO},{26,"aurora",15,"rojo",OCUPADO},{27,"fiorenza",26,"rojo",OCUPADO},{28,"peugeot",20,"azul",OCUPADO},{29,"aurora", 28, "verde",OCUPADO}};

		InicializadorTrabajos(trabajito,T);


		 do
			    {
			        printf("\n\t\tMENU PRINCIPAL\n");
			        printf("\t___________________________________\n");
			        printf("\tElija una opcion:\n");
			        printf("\t1.Alta Trabajo\n");
			        printf("\t2.Modificar Trabajo\n");
			        printf("\t3.Baja Trabajo \n");
			        printf("\t4.Listar Trabajos  \n");
			        printf("\t5.Listar Servicios \n");
			        printf("\t6.Total\n");
			        printf("\t0.SALIR\n");
			        scanf("%d", &opcion);
			        printf("\n\t__________________________________\n");

			        while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5 && opcion!=6 &&opcion!=0 && opcion!=7)
			        {
			            printf("\n\t***********************************\n");
			            printf("\tError!!! ingrese una opcion valida:\n");
			            printf("\t1.Alta Trabajo\n");
			            printf("\t2.Modificar Trabajo\n");
			            printf("\t3.Baja Trabajo \n");
			            printf("\t4.Listar Trabajos  \n");
			            printf("\t5.Listar Servicios \n");
			            printf("\t6.Total\n");
			            printf("\t0.SALIR\n");


			            scanf("%d", &opcion);


			        }

			        switch(opcion)
			        {
			           /*case 1:
			                banderaIngreso=1;
			            	printf("\n\t Alta de trabajos:\n");
			            	retornoCarga=CargarTrabajos(trabajito,T,servicios,4);
			            	if(retornoCarga!=-1)
			            	{
			            		printf("cargado exitosamente");
			            	}
			            	else
			            	{
			            		printf("no se pudo");
			            	}

			                break;


			                break;

			            case 2:
			            	if(banderaIngreso==1)
			            	{
			            		retornoModificar=ModificarTrabajo(trabajito,T,servicios,4);
			            		if(retornoModificar!=-1)
			            		{
			            		    printf("\n\t modificacion realizada con exito!!!\n");

			                     }
			            		else
			            		{
			            		    printf("\n\t modificacion cancelada, volviendo. . . ");
			            		}
			            		break;


			            	}
			            	else
			            	{
			            		printf("\n\t nada mostrar\n ");
			            	}
			            	break;
			            case 3:
			            	if(banderaIngreso==1)
			            	{
			            		retornoEliminar=EliminarTrabajo(trabajito,T,servicios,4);
			            	    if(retornoEliminar==0)
			            		{
			            			printf("\n\t trabajo eliminado!!!");
			            		}
			            		else
			            		{
			            			 if(retornoEliminar==-1)
			            		     {

			            		            printf("\n\t Eliminacion cancelada,volviendo. . .");
			            		     }
			            		      else
			                          {
			            			          printf("\n\t no se encontro el codigo de trabajo ingresado...");
			            		      }


			            		}

			            	}
			            	else
			            	{
			            		printf("\n\t nada mostrar, primero realice un ingreso \n ");
			            	}




			                break;

			            case 4:
			            	if(banderaIngreso==1)
			            	{
			            		Ordenar(trabajito,T);
			            		MostrarTodosLosTrabajos(trabajito,T,servicios,4);
			            	}
			            	else
			            	{
			            		printf("\n\t nada mostrar primero realice un ingreso \n ");
			            	}






			                break;

			            case 5:
			            	if(banderaIngreso ==1)
			            	{
			            		printf("\n\t Lista de servicios disponibles");
			            		printf("\n\t Codigo\t Descripcion \t precio");
			                    MostrarServicios(servicios,4);

			            	}
			            	else
			            	{
			            		printf("\n\t nada mostrar primero realice un ingreso \n ");
			            	}


			                break;

			            case 6:
			            	if(banderaIngreso==1)
			            	{
			            		gananciaPorTrabajos=AcumularGanancia(servicios,4,trabajito,T);
			            	    printf("\n\t el total de pesos por servicios realizados fue: %.2f ", gananciaPorTrabajos);

			            	}
			            	else
			            	{
			            		printf("\n\t nada mostrar primero realice un ingreso \n ");
			            	}



			                break;*/

			            case 7:
			            	MostrarBicicletas(misBicicletas,5);

			        }
			    }while(opcion!=0);



		return EXIT_SUCCESS;
}




