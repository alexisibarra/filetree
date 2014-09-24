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
#include <stdio.h>
#include <string.h>

typedef struct Nodo{
  char *nombre;
  bool file;
  int nFiles;
  struct Nodo *padre;
  struct Nodo *hermano;
  struct Nodo *hijo;
} Nodo;

typedef struct Nodo *Arbol;

Arbol nuevoNodo(){
  Arbol Temp = malloc(sizeof(Nodo)); 
	if (Temp==NULL){
		fprintf(stderr,"Se produjo un error de manejo de memoria. Fin del programa\n");
		exit(EX_DATAERR);
	}

  Temp->nombre  = "/";
  Temp->file    = false;
  Temp->nFiles  = 0;
  Temp->padre   = NULL;
  Temp->hermano = NULL;
  Temp->hijo    = NULL;

  return Temp;
}

int inicializar(Nodo * nodo){

  if ((nodo = (Nodo *) malloc (sizeof (Nodo))) == NULL)
    return -1;

  nodo->nombre  = "/";
  nodo->file    = false;
  nodo->nFiles  = 0;
  /* nodo->padre   = 0; */
  /* nodo->hermano = 0; */
  /* nodo->hijo    = 0; */

  return 1;
}

int createSon(Nodo * nodo, bool file, char *nombre ){
  Nodo * son = nuevoNodo();

  son->nombre = nombre;
  son->file = file;
  son->padre = nodo;
  
  nodo->hijo = son;

  return 1;
}


int insertarArchivo(Nodo * nodo, char *path){
  if ( !path ) {
    return -1;
  }

  char *firstElem;
  char *remainingPath;
  int firstElemSize = 0;

  /* firstElem = strchr(path, '/'); */

  if ( strchr(path, '/') != NULL ){
  /* if ( firstElem != NULL ) { */
    /* printf("Full path: %s\n", path); */ 

    // VERIFICAR SI firstElem ESTÁ EN EL ARBOL

    firstElem = strchr(path, '/');
    remainingPath = strchr(firstElem+1, '/');

    if ( remainingPath != NULL ) {
      firstElemSize = strlen(path) - strlen(remainingPath);
      firstElem = malloc(firstElemSize); // Implementar manejo de error
      strncpy(firstElem, path, firstElemSize); 

      firstElem = firstElem + 1;

      printf("First element: %s\n", firstElem);
      printf("Rest of the path: %s\n\n", remainingPath); 

      insertarArchivo(nodo, remainingPath); 
    } else {
    /*   // First elem es lo único que se tiene en el path, hay que agregarlo */
      firstElem = firstElem + 1;

      if(createSon(nodo, true, firstElem) > 0){
        printf("Hijo %s agregado", firstElem);
      } else{
        printf("No se pudo agregar %s", firstElem);
      }
    }
  } else {
    // El path no comienza con / no se puede agregar
    return -1;
  }
  return 1;
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
