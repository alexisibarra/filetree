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

int createSon(Nodo * nodo, bool file, char *nombre ){
  Nodo * son = nuevoNodo();

  if (son == NULL){
    return -1;
  }

  son->nombre = nombre;
  son->file = file;
  son->padre = nodo;
  
  nodo->hijo = son;

  return 1;
}

void imprimir(Nodo * nodo){
  // No debería poder imprimir un nodo vacío
  printf("%s\n", nodo->nombre);
  if(nodo->hermano != NULL){
    imprimir(nodo->hermano);
  }
  if(nodo->hijo != NULL){
    imprimir(nodo->hijo);
  }
}

bool checkPath(char *path, char **firstElem, char **remainingPath){
  *firstElem = strchr(path, '/');

  if(path[0] == '/' && path != "/") {
    if ( firstElem != NULL ) {
      *remainingPath = strchr(*firstElem+1, '/');
      if ( *remainingPath != NULL ) {
        int firstElemSize = strlen(path) - strlen(*remainingPath);
        char *firstElemDummy = malloc(firstElemSize); // Implementar manejo de error
        strncpy(firstElemDummy, path, firstElemSize); 

        *firstElem = firstElemDummy;
      }
    }
  } else {
    *firstElem = NULL;
    *remainingPath = NULL;
  }
}


int insertarArchivo(Nodo * nodo, char *path){
  char *firstElem;
  char *remainingPath;

  checkPath(path, &firstElem, &remainingPath);

  if ( firstElem != NULL ){
    if ( remainingPath == NULL ) {
      //Debo insertar firstElem como hijo del nodo actual
      // printf ( "%s\n", firstElem+1 );
      createSon(nodo, true, firstElem+1);
    }
  } else {
    // El path no comienza con / no se puede agregar
    return -1;
  }
  return 1;
}

/* 
 *

  // Si entra aquí es porque el path comienza con /
    // VERIFICAR SI firstElem ESTÁ EN EL ARBOL

    firstElem = strchr(path, '/');
    remainingPath = strchr(firstElem+1, '/');

    if ( remainingPath != NULL ) {

      // Si entra acá es porque firstElem es un directorio que hay que crear

      firstElemSize = strlen(path) - strlen(remainingPath);
      firstElem = malloc(firstElemSize); // Implementar manejo de error
      strncpy(firstElem, path, firstElemSize); 

      firstElem = firstElem + 1;

      if(createSon(nodo, true, firstElem) > 0){
        printf ( "Agregué %s\n", firstElem );
      }
      printf("First element: %s\n", firstElem);
      printf("Rest of the path: %s\n\n", remainingPath); 

      insertarArchivo(nodo, remainingPath); 
    } else {
    // First elem es lo único que se tiene en el path, hay que agregarlo /
      firstElem = firstElem + 1;

      if(createSon(nodo, true, firstElem) > 0){
        // printf("Hijo %s agregado", nodo->hijo->nombre);
        // imprimir(nodo);
      } else{
        // printf("No se pudo agregar %s", firstElem);
      }
    }
 *
 *
 * */
