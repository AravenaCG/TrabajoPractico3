#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "movie.h"

#define LIMITE_PELICULA 10

int main()
{

    char bufferInt[50];
    char bSeleccion_Pelicula_A[50];
    int id;

    sMovie listaPeliculas[LIMITE_PELICULA];
    mov_InitLista(listaPeliculas,LIMITE_PELICULA);


    do
    {
        val_getUnsignedInt(bufferInt,"\n1- Agregar Pelicula \n2- Borrar Pelicula \n3- Modificar Pelicula \n4- Armar Pagina Web  \n\n5- SALIR  \n","error",2,40);
        switch(atoi(bufferInt))
        {
        case 1:
            mov_AgregarPelicula(listaPeliculas,mov_generar_Proximo_Id(listaPeliculas,LIMITE_PELICULA),mov_obtenerEspacioLibre(listaPeliculas,LIMITE_PELICULA),LIMITE_PELICULA);

            break;

        case 2:
            val_getUnsignedInt(bSeleccion_Pelicula_A,"Ingrese el id de la Peliculla a Eliminar","NO VALIDO",3,50);

            mov_BorrarPelicula(listaPeliculas, atoi(bSeleccion_Pelicula_A),LIMITE_PELICULA);
            break;

        case 3:
            val_getUnsignedInt(bSeleccion_Pelicula_A,"Ingrese pelicula a Modificar", "No Valido",3,50);
            id=atoi(bSeleccion_Pelicula_A);
            mov_modificarPelicula(listaPeliculas,LIMITE_PELICULA,id);

            break;

        case 4:
            mov_Crear_Archivo_Peliculas("ListadoPeliculas.html",listaPeliculas,LIMITE_PELICULA);

            break;

        case 5:

            printf( " \n\n\n\n\n\nGRACIAS VUELVAS PRONTOS!!!!!!!!!!!!!\n\n\n\n\n\n!! ");

            break;
        }
    }
    while(atoi(bufferInt) != 5);

    return 0;
}
