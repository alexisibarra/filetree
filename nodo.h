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

typedef struct NodoArbol {
  char *nombre;
  bool file;
  int nFiles;
} Nodo;

void inicializar(Nodo * nodo){
  nodo->nombre = "/";
  nodo->file = false;
  nodo->nFiles = 0;
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
