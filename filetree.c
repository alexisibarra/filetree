/*
 * =====================================================================================
 *
 *       Filename:  filetree.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/09/14 21:33:36
 *       Revision:  
 *       Compiler:  gcc
 *
 *         Author:  Alexis Ibarra (), ar.ibarrasalas@gmail.com
 *   Organization:  Universidad Simón Bolívar
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>

#include "nodo.h"

int main(int argc, char *argv[]) {
  FILE* fp = NULL;
  char command[4];
  char path[30];

  Arbol arbol = nuevoNodo();

	if (argc != 2) {
		puts("Se debe pasar exactamente un argumento.");
		exit(EX_USAGE);
	}
	if ((fp = fopen(argv[1], "r")) == 0){
    perror("El archivo no existe; fopen");
    exit(EX_USAGE);
  }

  while (1){
    if (fscanf(fp, "%s %s", command, path) == 2){
      if (strncmp( command, "ma", 2) == 0){
        printf ( "PATH: %s\n", path );
        if ( insertarArchivo(arbol, path) < 0 ) {
          printf("No es posible insertar el archivo %s\n",path);
        }
      } else
      if (strncmp( command, "md", 2) == 0){
        /* proc_md(path);  */
      } else
      if (strncmp( command, "ls", 2) == 0){
        /* proc_ls(path);  */
      } else
      if (strncmp( command, "rm", 2) == 0){
        /* proc_rm(path);  */
      }
    } else {
      break;
    }
  }

  imprimir(arbol);

  fclose(fp);
}

