#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "movie.h"



/** \brief idAutoincrementable
 *
 * \param arrayLista recibe puntero al inicio del array
 * \param len es la cantidad de elementos del array
 * \return retorna el ultimo valor para utilizar en Id
 *
 */

int mov_generar_Proximo_Id(sMovie listaPeliculas[], int len)
{
    static int ultimoValorIdAutoincrementable = -1;
    ultimoValorIdAutoincrementable ++;
    return ultimoValorIdAutoincrementable;

}



/** \brief Inicializa la lista
 *
 * \param arrayLista recibe puntero al inicio del array
 * \param limite es la cantidad de elementos del array
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

int mov_InitLista(sMovie  listaPeliculas[], int limite)
{
    int retorno = -1;
    int i;

    if( listaPeliculas != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            listaPeliculas[i].flag_ocupado = INDICE_LIBRE;
            retorno=0;
        }

    }

    return retorno;
}

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int mov_obtenerEspacioLibre(sMovie  listaPeliculas[],int limite)
{

    int retorno = -1;
    int i;
    if(listaPeliculas != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            if(listaPeliculas[i].flag_ocupado == INDICE_LIBRE)
            {
                retorno = i;
                break;
            }
        }

    }
    return retorno;

}

/**--------------------------------------------------------------------------------------------------
*-----------------------------------------------------------------------------------------------*/


/** \brief Agrega persona a la lista
 *
 * @param  index el indice en el array, es decir la posicion.
 * @param  limite cantidad de elementos en el array
 * @return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

int mov_AgregarPelicula(sMovie listaPeliculas[], int idPelicula,int index, int limite)
{
    int retorno = -1;

    char genero[50];
    char bTitulo[50];
    char bDuracion[50];
    char bDescripcion[50];
    char bPuntaje[50];
    char bLink_imagen[50];



    if(listaPeliculas != NULL && index >= 0 && index <limite)
    {

            if  (val_getUnsignedInt(bDuracion,"\nIngrese la Duracion:\n","\nError:\n",3,50)==0 )
            {


                if (val_getAlfanumerico(bTitulo,"\n Ingrese el Titulo: \n"," NO VALIDO\n",3,50)== 0)
                {
                    if (val_getAlfanumerico(bDescripcion,"\nIngrese Descripcion\n","\nArchivo no valido\n",3,50)==0)

                    {
                        if (val_getUnsignedInt(bPuntaje ,"Ingrese el puntaje\n","ERROR",3,50) ==0 )
                        {
                             if (val_getAlfanumerico(bLink_imagen,"\nIngrese link a imagen\n","\nArchivo no valido\n",3,2048)==0)

                                    {
                                        listaPeliculas[index].duracion = atoi(bDuracion);
                                        strncpy(listaPeliculas[index].descripcion,bDescripcion,50);
                                        strncpy(listaPeliculas[index].genero,genero,50);
                                        strncpy(listaPeliculas[index].link_de_imagen,bLink_imagen,2048);
                                        strncpy(listaPeliculas[index].titulo,bTitulo,50);
                                        listaPeliculas[index].idPelicula= mov_generar_Proximo_Id(listaPeliculas,limite);
                                        listaPeliculas[index].flag_ocupado = INDICE_OCUPADO;
                                        listaPeliculas[index].puntaje= atoi(bPuntaje);
                                        retorno=0;

                        }
                    }

            }
        }
    }




}
return retorno;
}



/** \brief modifica un elemento del array
 *
 * @param  index el indice en el array, es decir la posicion.
 * @param  len cantidad de elementos en el array
 * @param  id elementos a modificar en el array
 * @return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */
int mov_modificarPelicula(sMovie listaPeliculas[],int len, int id , int limite)
{

    int retorno=-1;
    int index;
    char genero[50];
    char bTitulo[50];
    char bDuracion[50];
    char bDescripcion[50];
    char bPuntaje[50];
    char bLink_imagen[50];



    if (mov_buscarIndexPorId(listaPeliculas,len, id) != -1)
    {
        index = mov_buscarIndexPorId(listaPeliculas,len,id);
    }


            if  (val_getUnsignedInt(bDuracion,"\nIngrese la Duracion:\n","\nError:\n",3,50)==0 )
            {


                if (val_getAlfanumerico(bTitulo,"\n Ingrese el Titulo: \n"," NO VALIDO\n",3,50)== 0)
                {
                    if (val_getAlfanumerico(bDescripcion,"\nIngrese Descripcion\n","\nArchivo no valido\n",3,50)==0)

                    {
                       if (getStringNumerosFlotantes("Ingrese el puntaje",bPuntaje) ==0 )
                        {
                             if (val_getAlfanumerico(bLink_imagen,"\nIngrese link a imagen\n","\nArchivo no valido\n",3,50)==0)

                                    {
                                        listaPeliculas[index].duracion = atoi(bDuracion);
                                        strncpy(listaPeliculas[index].descripcion,bDescripcion,50);
                                        strncpy(listaPeliculas[index].genero,genero,50);
                                        strncpy(listaPeliculas[index].link_de_imagen,bLink_imagen,50);
                                        strncpy(listaPeliculas[index].titulo,bTitulo,50);
                                        listaPeliculas[index].idPelicula= mov_generar_Proximo_Id(listaPeliculas,limite);
                                        listaPeliculas[index].flag_ocupado = INDICE_OCUPADO;
                                        listaPeliculas[index].puntaje= atof(bPuntaje);
                                        retorno=0;

                        }

                    }
                }
            }
        }




    return retorno;


}



/** \brief busca un id en la lista
 * @param  listaDuenios el array donde busca
 * @param  len cantidad de elementos en el array
 * @return retorno :posicion donde se encontro o -1 si no se encontro
 *
 */
int mov_buscarIndexPorId(sMovie listaPeliculas[],int len,int id)
{
    int i;
    int retorno=-1;
    if (listaPeliculas != NULL && len >0 && id >0 )
    {
        for (i=0; i<len; i++)
        {
            if (listaPeliculas[i].flag_ocupado == INDICE_OCUPADO)
            {


                if (id == listaPeliculas[i].idPelicula)
                {
                    retorno=i;
                    break;

                }
            }
        }
    }
    return retorno;
}

/** \brief pone el estado del elemento en libre para "borrarlo"
 *
 * \param listaDuenios es el array que recibe
 * \param limite la cantidad de elementos para el array
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

int mov_BorrarPelicula(sMovie listaPeliculas[], int idABorrar,int limite)
{
    int retorno = -1;
    int i = 0;

    if(listaPeliculas != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            if(listaPeliculas[i].flag_ocupado == INDICE_OCUPADO && listaPeliculas[i].idPelicula == idABorrar)
            {
                listaPeliculas[i].flag_ocupado = INDICE_LIBRE;
                printf("\nPelicula Eliminada!!!\n");
                retorno=0;
            }
        }

    }



    return retorno;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int mov_Crear_Archivo_Peliculas(char* fileNAme, sMovie listaPeliculas[],int limite )
{
    int retorno=0;
    int i;
    FILE* punteroArchivo;

    punteroArchivo =  fopen( fileNAme, "w");

    fprintf(punteroArchivo,"<!DOCTYPE html>\
<!-- Template by Quackit.com -->\
<html lang='en'>\
<head>\
    <meta charset='utf-8'>\
    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\
    <meta name='viewport' content='width=device-width, initial-scale=1'>\
    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\
    <title>Lista peliculas</title>\
    <!-- Bootstrap Core CSS -->\
    <link href='css/bootstrap.min.css' rel='stylesheet'>\
    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\
    <link href='css/custom.css' rel='stylesheet'>\
    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\
    <!--[if lt IE 9]>\
        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\
        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\
    <![endif]-->\
</head>\
<body>\
    <div class='container'>\
        <div class='row'>");



    for (i=0; i<limite; i++)
    {
        if (listaPeliculas[i].flag_ocupado==INDICE_OCUPADO)
        {

            fprintf(punteroArchivo,"<!-- Repetir esto para cada pelicula -->\
            <article class='col-md-4 article-intro'>\
                <a href='#'>\
                    <img class='img-responsive img-rounded' src='%s' alt=''>\
                </a>\
                <h3>\
                    <a href='#'>Titulo:%s</a>\
                </h3>\
				<ul>\
					<li>Genero:%s</li>\
					<li>Puntaje:%d</li>\
					<li>Duración:%d</li>\
				</ul>\
                <p>%s.</p>\
            </article>\
			<!-- Repetir esto para cada pelicula -->",listaPeliculas[i].link_de_imagen, listaPeliculas[i].titulo,listaPeliculas[i].genero,listaPeliculas[i].puntaje,listaPeliculas[i].duracion,listaPeliculas[i].descripcion);

        }
    }

    fprintf(punteroArchivo,"</div>\
        <!-- /.row -->\
    </div>\
    <!-- /.container -->\
    <!-- jQuery -->\
    <script src='js/jquery-1.11.3.min.js'></script>\
    <!-- Bootstrap Core JavaScript -->\
    <script src='js/bootstrap.min.js'></script>\
	<!-- IE10 viewport bug workaround -->\
	<script src='js/ie10-viewport-bug-workaround.js'></script>\
	<!-- Placeholder Images -->\
	<script src='js/holder.min.js'></script>\
</body>\
</html>");

    fclose(punteroArchivo);


    return retorno;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */



