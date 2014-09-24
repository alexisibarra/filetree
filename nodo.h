/*
 * =====================================================================================
 *
 *       Filename:  nodo.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/09/14 17:21:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdbool.h>

typedef struct Nodo{
  char *nombre;
  bool file;
  int nFiles;
  struct Nodo *padre;
  struct Nodo *hermano;
  struct Nodo *hijo;
} Nodo;

int inicializar(Nodo * nodo){

  if ((nodo = (Nodo *) malloc (sizeof (Nodo))) == NULL)
    return -1;

  nodo->nombre  = "/";
  nodo->file    = false;
  nodo->nFiles  = 0;
  nodo->padre   = 0;
  nodo->hermano = 0;
  nodo->hijo    = 0;

  return 1;
}

void insertar(Nodo * nodo, char *path){
  printf("%s\n", path);
}

void imprimir(Nodo * nodo){
  // No debería poder imprimir un nodo vacío
  printf("Nombre: %s\n", nodo->nombre);
  if(nodo->file){
    printf("Archivo\n");
  }else{
    printf("Directorio con %d archivos\n", nodo->nFiles);
  }
}

int agregarElemento(Nodo * nodo){
  if(!nodo->file){
    nodo->nFiles =+ 1;
  }
}
