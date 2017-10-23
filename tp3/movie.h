#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED
typedef struct {
int idPelicula;
char titulo[50];
char genero[50];
unsigned int duracion;
char descripcion[200];
int puntaje;
char link_de_imagen[2048];
int flag_ocupado;
}sMovie;


#endif // MOVIE_H_INCLUDED

#define INDICE_LIBRE 0
#define INDICE_OCUPADO 1

int mov_InitLista(sMovie  listaPeliculas[], int limite);
int mov_obtenerEspacioLibre(sMovie  listaPeliculas[],int limite);
int mov_generar_Proximo_Id(sMovie listaPeliculas[], int len);
int mov_AgregarPelicula(sMovie listaPeliculas[], int idPelicula, int index, int limite);
int mov_BorrarPelicula(sMovie listaPeliculas[], int id,int limite);
int mov_BuscarChar(sMovie listaPeliculas[],int len, char texto[]);
int mov_modificarPelicula(sMovie listaPeliculas[],int len, int id);
int mov_buscarIndexPorId(sMovie listaPeliculas[],int len,int id);
int mov_Crear_Archivo_Peliculas(char* fileName ,sMovie listaPeliculas[],int limite);
