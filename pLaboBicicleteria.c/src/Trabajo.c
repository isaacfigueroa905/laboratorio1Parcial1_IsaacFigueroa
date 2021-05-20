/*
 * Trabajo.c
 *
 *  Created on: 17 may. 2021
 *      Author: Isaac
 */
#include "Servicio.h"
#include "Trabajo.h"
#include <stdio.h>
#include <string.h>
#include "inputs.h"
#define OCUPADO 1
#define VACIO 0
#define ELIMINADO -1

void InicializadorTrabajos(eTrabajo listadoTrabajos[] ,int tamT)
{
	int i;


	if ( listadoTrabajos!= NULL && tamT > 0)
	{
		for (i = 0; i <tamT; i++)
		{
			listadoTrabajos[i].isEmpty = VACIO;
		}
	}
}




int BuscarLibre(eTrabajo listaTrabajos[], int tamT)
{
	int index = -1;
	int i;


	if (listaTrabajos != NULL && tamT > 0)
	{
		for (i = 0; i < tamT; i++)
		{
			if (listaTrabajos[i].isEmpty == VACIO)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}





int BuscarTrabajoPorId(eTrabajo listaTrabajos[], int tamT, int ID)
{
	int retorno = -1;
	int i;


	if (listaTrabajos != NULL && tamT > 0)
	{

		for (i = 0; i < tamT; i++)
		{

			if (listaTrabajos[i].idTrabajo == ID && listaTrabajos[i].isEmpty == OCUPADO)
			{

				retorno = i;//encontre id
				break;
			}
		}
	}

	return retorno;//retorna idTrabajo
}


void  OrdenarPorMarcaBici(eTrabajo listaTrabajos[], int tamT)
{
    int i;
    int j;

    eTrabajo auxTrabajo;

    for(i=0; i<tamT-1; i++)
    {
        for(j=i+1; j<tamT; j++)
        {
        	if (listaTrabajos[i].isEmpty == OCUPADO && listaTrabajos[j].isEmpty == OCUPADO)
        	{
        		if(strcmp(listaTrabajos[i].marcaBicicleta ,listaTrabajos[j].marcaBicicleta )>0 )// A -- Z
        		{
        		   auxTrabajo=listaTrabajos[i];
        		   listaTrabajos[i]=listaTrabajos[j];
        		   listaTrabajos[j]=auxTrabajo;

        		}
        	}


        }

    }



}

int OrdenarTrabajosPorAnio(eTrabajo listaTrabajos[], int tamT)
{
    int i;
    int j;
    int retorno;


    eTrabajo auxTrabajo;

    if (listaTrabajos != NULL && tamT > 0)
    {
    	for(i=0; i<tamT-1; i++)
    	    {
    	        for(j=i+1; j<tamT; j++)
    	        {
    	        	if (listaTrabajos[i].isEmpty == OCUPADO && listaTrabajos[j].isEmpty == OCUPADO)
    	        	{

    	        		if(listaTrabajos[i].fecha.anio < listaTrabajos[j].fecha.anio)//mayor mas arriba
    	        		{
    	        			auxTrabajo=listaTrabajos[i];
    	        		    listaTrabajos[i]=listaTrabajos[j];
    	        		    listaTrabajos[j]=auxTrabajo;
    	        		    retorno=1;

    	        		}
    	        		if(listaTrabajos[i].fecha.anio == listaTrabajos[j].fecha.anio)
    	        		{
    	        			retorno=-1;
    	        		}
                    }



    	        }
    	    }

    }
    return retorno;



}



eFechas IngresarFecha(char mensaje[])
{
	eFechas fecha;

	printf("%s",mensaje);
	fflush(stdin);
	printf("\n ingrese dia: ");
	scanf("\n%d", &fecha.dia);
	while(fecha.dia<1 || fecha.dia>30)
	{
		printf("\n ingrese un dia correcto: ");
		scanf("\n%d", &fecha.dia);
	}

	printf("\n ingrese mes: ");
	scanf("\n%d", &fecha.mes);
	while(fecha.mes<1 || fecha.mes>12)
	{
		printf("\n ingrese un mes correcto: ");
		scanf("\n%d", &fecha.mes);
	}

	printf("\n ingrese anio: ");
	scanf("\n%d", &fecha.anio);
	while(fecha.anio<1999 || fecha.dia>2030)
	{
		printf("\n ingrese un anio correcto: ");
		scanf("\n%d", &fecha.anio);
	}


	return fecha;
}




int  MostrarUnTrabajo(eTrabajo unTrabajo, char* descripcionS)
{
    printf("\n\%11d %16s %17d  %22s %19d/%d/%d\n",unTrabajo.idTrabajo,unTrabajo.marcaBicicleta, unTrabajo.rodadoBicicleta,descripcionS,
    		                                             unTrabajo.fecha.dia,unTrabajo.fecha.mes,unTrabajo.fecha.anio);
    printf("\t__________________________________________________________________________________________\n");


    return 0;
}



void Ordenar(eTrabajo listaTrabajos[], int tamT)
{
	int porAnio;


	porAnio=OrdenarTrabajosPorAnio(listaTrabajos,tamT);

	if(porAnio!=-1)//si no son iguales
	{
		OrdenarTrabajosPorAnio(listaTrabajos,tamT);//ordenar por año descendente
	}
	else//si son iguales
	{
		OrdenarPorMarcaBici(listaTrabajos,tamT);//ordenar por marca alfabeticamente ascendente
	}




}


//-------------------



int idIncrementalTradajos = 1;


int GenerarId()
{
	return idIncrementalTradajos ++;
}







float AcumularGanancia(eServicio listaServicios[],int tamS, eTrabajo listaTrabajos[], int tamT)
{
	float acumulador=0;
	int i;
	//eServicio auxServicio;
	//int retServ;
	int j;


	for(i=0;i<tamT;i++)
	{
		for(j=0;j<tamS;j++)
		{
			if( listaTrabajos[i].isEmpty==OCUPADO && listaTrabajos[i].idServicio==listaServicios[j].idServicios)
					{
					     acumulador=listaServicios[j].precio+acumulador;
					     break;

					}
		}


	}
	return acumulador;

}








eTrabajo ingreso(eServicio listaServicios[] , int tamS)
{

		eTrabajo unTrabajo;

		char marca[25];
		int rodado;
		int retRodado;
		int codigoIngresado;
		//int retornoChar;
		int indexRetornado;


	 	printf("\n\t Ingresos de Trabajos\n\n ");
	    printf("\t ingrese marca: ");
	    fflush(stdin);
	    gets(marca);
	    strcpy(unTrabajo.marcaBicicleta,marca);

	    retRodado=utn_getNumero(&rodado,"\n\t ingrese el rodado (10 a 30 ) "," \n\t error, los rodados disponibles son de 10 a 30 reingrese ", 10,30,100);
	    if(retRodado!=-1)
	    {
	    	unTrabajo.rodadoBicicleta=rodado;
	    }
	    else
	    {
	    	printf("\n\t demasiados intentos!!");

	    }


	    printf("\n\t listado de servicios: ");
	    MostrarServicios(listaServicios,4);
	    printf("\n\t ingrese Codigo del Servicio a realizar: ");
	    scanf("%d",&codigoIngresado);

	    indexRetornado=BuscarServicioPorId(listaServicios,tamS,codigoIngresado);

	    while(indexRetornado==-1)
	    {
	    	 printf("\n\t Error el codigo no pertenece a ningun servicio,\n\t reingrese Codigo del Servicio a realizar: ");
	    	 scanf("%d",&codigoIngresado);
	    	 indexRetornado=BuscarServicioPorId(listaServicios,tamS,codigoIngresado);
	    }

	    unTrabajo.idServicio=codigoIngresado;//obtengo el servicio



	    unTrabajo.fecha=IngresarFecha("\n\t indique dia de ingreso: \n");



    return unTrabajo;

}


int EliminarTrabajo(eTrabajo listaTrabajos[], int tamT,eServicio listaServicios[] , int tamS)
{
    int i;
    int codigoIngresado;
    int retorno=1;//por defecto no encontro el codigo
    char decidir;
    char descripcionServicio[20];




    MostrarTodosLosTrabajos(listaTrabajos,tamT,listaServicios,tamS);

    printf("\n\t\t ingrese codigo del trabajo a eliminar: ");
    scanf("%d", &codigoIngresado);
    while( BuscarTrabajoPorId(listaTrabajos,tamT,codigoIngresado)==-1)
    {
        printf("\n\t Error el codigo no pertenece a ningun trabajo,\n\t reingrese Codigo del Trabajo a eliminar: ");
        scanf("%d",&codigoIngresado);
     }


    for(i=0;i<tamT;i++)
    {
       if(listaTrabajos[i].idTrabajo==codigoIngresado&&listaTrabajos[i].isEmpty==OCUPADO)
       {
    	   printf("\n\t\t¿Esta seguro que desea eliminar este trabajo?\n\t\t('s'.Si  | 'otra letra'.Volver al menu principal)\n");
    	   ObtenerDescripcionServicio( listaServicios,tamS,listaTrabajos[i].idServicio,descripcionServicio);
    	   MostrarUnTrabajo(listaTrabajos[i],descripcionServicio);
    	   fflush(stdin);
    	   scanf("\n %s",& decidir);
    	   if(decidir=='s')//elimina
    	   {
    		   listaTrabajos[i].isEmpty=ELIMINADO;
    		   retorno=0;
    		   break;
    	   }
    	   else
    	   {

    		   retorno=-1;//niega
    		   break;
    	   }


       }
       else
       {

           retorno=1;//no encuentra

       }
    }
    return retorno;

}


int ModificarTrabajo(eTrabajo listaTrabajos[], int tamT, eServicio listaServicios[], int tamS)
{
    int i;
    int codIngresado;
    int opc;
    int retorno=-1;
    int codServ;
    int indexRetornado;
    char descripcionServicio[20];


    MostrarTodosLosTrabajos(listaTrabajos,tamT,listaServicios,tamS);
    printf("\n\t\t Ingrese ID del trabajo a modificar: ");

    scanf("%d", &codIngresado);
    //indexTrabajo=BuscarTrabajoPorId(listaTrabajos,tamT,codIngresado);
    while( BuscarTrabajoPorId(listaTrabajos,tamT,codIngresado)==-1)
    {
    	printf("\n\t Error el codigo no pertenece a ningun trabajo,\n\t reingrese Codigo del Trabajo a modificar: ");
        scanf("%d",&codIngresado);


    }


    for(i=0;i<tamT;i++)
    {
        if(listaTrabajos[i].idTrabajo==codIngresado&&listaTrabajos[i].isEmpty==OCUPADO)
        {
            printf("\n\t\t ¿Que cambio desea realizar en este trabajo?\n\n ");
            ObtenerDescripcionServicio( listaServicios,tamS,listaTrabajos[i].idServicio,descripcionServicio);
            MostrarUnTrabajo(listaTrabajos[i],descripcionServicio);

            printf("\t\t1.La marca de bici  2.El servicio:  ");
            scanf(" %d",&opc);
             while(opc!=1 &&opc!=2)
            {

                printf("Error reingrese una opcion valida!!!");
                printf("\n\t\t ¿Que cambio desea realizar?\n\n ");
                printf("\t\t 1.La marca de bici  2.El servicio :  ");
                scanf(" %d",&opc);

            }
            switch(opc)
            {
                case 1:
                    printf("\n\t\t Ingrese nueva marca : ");
                    fflush(stdin);
                    scanf("%[^\n]", listaTrabajos[i].marcaBicicleta);
                    retorno=0;
                break;

                case 2:
                    printf("\n\t\t Ingrese nuevo servicio : ");
                    MostrarServicios(listaServicios,tamS);
                    scanf("%d",&codServ);
                    indexRetornado=BuscarServicioPorId(listaServicios,tamS,codServ);

                    	    while(indexRetornado==-1)
                    	    {
                    	    	 printf("\n\t Error el codigo no pertenece a ningun servicio,\n\t reingrese Codigo del Servicio a realizar: ");
                    	    	 scanf("%d",&codServ);
                    	    	 indexRetornado=BuscarServicioPorId(listaServicios,tamS,codServ);
                    	    }

                    listaTrabajos[i].idServicio=codServ;//obtengo el servicio

                    retorno=0;
                break;


            }
            break;
        }

    }
    return retorno;

}




int MostrarTodosLosTrabajos(eTrabajo unTrabajo[], int tamT,eServicio unServicio[], int tamS)
{
	int i;
	int cantidad = 0;
	char descripcionServicio[25];

	printf("\n\t ID \t MARCA DE BICI \t\t RODADO \t\tSERVICIO \t\t FECHA\n\n "); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	if (unTrabajo != NULL && tamT > 0)
	{

		for (i = 0; i < tamT; i++)
		{

			if (unTrabajo[i].isEmpty == OCUPADO)
			{
				ObtenerDescripcionServicio( unServicio,tamS,unTrabajo[i].idServicio,descripcionServicio);
				MostrarUnTrabajo(unTrabajo[i],descripcionServicio);

				cantidad++;
			}
		}
	}
	return 0;

}




int CargarTrabajos(eTrabajo listaTrabajos[] , int tamT, eServicio listaServicios[], int tamS)
{
  int index;
  int retorno=-1;
  eTrabajo aux;


  index=BuscarLibre(listaTrabajos, tamT);

  if(index!=-1  )
  {
      aux = ingreso(listaServicios,tamS);
      aux.idTrabajo = GenerarId();
      aux.isEmpty=OCUPADO;
      listaTrabajos[index] =aux;
      retorno=0;
  }

  return retorno;


}



