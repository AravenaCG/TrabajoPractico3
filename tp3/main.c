#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "movie.h"

#define LIMITE_PELICULA 10

int main()
{

    char bufferInt[50];
    char bPelicula_A_Borrar[50];


    sMovie listaPeliculas[LIMITE_PELICULA];
    mov_InitLista(listaPeliculas,LIMITE_PELICULA);


    do
    {
        val_getUnsignedInt(bufferInt,"\n1- Agregar Pelicula \n2- Borrar Pelicula \n3- Modificar Pelicula \n4- Armar Pagina Web  \n\n5-  \n","error",2,40);
        switch(atoi(bufferInt))
        {
        case 1:
            mov_AgregarPelicula(listaPeliculas,mov_generar_Proximo_Id(listaPeliculas,LIMITE_PELICULA),mov_obtenerEspacioLibre(listaPeliculas,LIMITE_PELICULA),LIMITE_PELICULA);

            break;

        case 2:
            val_getUnsignedInt(bPelicula_A_Borrar,"Ingrese el id de la Peliculla a Eliminar","NO VALIDO",3,50);

            mov_BorrarPelicula(listaPeliculas, atoi(bPelicula_A_Borrar),LIMITE_PELICULA);
            break;

        case 3:

            break;

        case 4:
            mov_Crear_Archivo_Peliculas("prueba.html",listaPeliculas,LIMITE_PELICULA);

            break;

        case 5:



            break;
        }
    }
    while(atoi(bufferInt) != 9);

    return 0;
}
