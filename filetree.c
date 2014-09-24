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

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  proc_ma
 *  Description:  
 * =====================================================================================
 */
  void
proc_ma ( char *command )
{
  printf("Encontré un ma %s\n", command);
}		/* -----  end of function proc_ma  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  proc_md
 *  Description:  
 * =====================================================================================
 */
  void
proc_md ( char *command )
{
  printf("Encontré un md %s\n", command);
}		/* -----  end of function proc_md  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  proc_ls
 *  Description:  
 * =====================================================================================
 */
  void
proc_ls ( char *command )
{
  printf("Encontré un ls %s\n", command);
}		/* -----  end of function proc_ls  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  proc_rm
 *  Description:  
 * =====================================================================================
 */
  void
proc_rm ( char *command )
{
  printf("Encontré un rm %s\n", command);
}		/* -----  end of function proc_rm  ----- */



int main(int argc, char *argv[]) {
  FILE* fp = NULL;
  char command[4];
  char *path;
  /* Nodo * arbol; */

  Arbol arbol = nuevoNodo();

  /* printf ( "%s\n", arbol->nombre ); */

	if (argc != 2) {
		puts("Se debe pasar exactamente un argumento.");
		exit(EX_USAGE);
	}
	if ((fp = fopen(argv[1], "r")) == 0){
    perror("El archivo no existe; fopen");
    exit(EX_USAGE);
  }

  imprimir(arbol);

  path = "ma /history.bat";

  if ( insertarArchivo(arbol, path) < 0 ) {
    printf("No es posible insertar el archivo %s\n",path);
  }


  /* if (inicializar(arbol) < 0 ) exit(EX_USAGE); //Mejorar código de error */

  /* imprimir(arbol); */

  /* while (fscanf(fp, "%s %s", command, path) == 2){ */
  /*   if (strncmp( command, "ma", 2) == 0){ */
  /*     if ( insertarArchivo(arbol, path) < 0 ) { */
  /*       printf("No es posible insertar el archivo %s\n",path); */
  /*     } */
  /*     printf("\n"); */
  /*   } else */
  /*   if (strncmp( command, "md", 2) == 0){ */
  /*     /1* proc_md(path); *1/ */
  /*   } else */
  /*   if (strncmp( command, "ls", 2) == 0){ */
  /*     /1* proc_ls(path); *1/ */
  /*   } else */
  /*   if (strncmp( command, "rm", 2) == 0){ */
  /*     /1* proc_rm(path); *1/ */
  /*   } */
  /* } */

  /* fclose(fp); */
}


