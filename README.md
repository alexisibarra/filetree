# Filetree

Representación un árbol de directorio a través de listas en C

## Sinopsis
```bash
$ ./filetree ENTRADA
```

## Descripción

Lee la información de un arbol de directorio contenida en el archivo con
dirección absoluta ENTRADA, crea el árbol empleando listas enlazadas e imprime
el resultado por la salida estandar en orden de búsqueda en anchura (BFS-Breadth
First Search).

### Archivo de entrada

- ENTRADA debe ser una dirección absoluta al fichero con la secuencia de ordenes
  que desea procesar
- El archivo debe contener una sola orden por línea, sin líneas en blanco ni
  comentarios. Cada línea debe seguir el siguiente formato:
    

  ``` comando direccion ```
  
  Donde comando debe ser alguno de los siguientes:

  - *md*: agregar un directorio
  - *ma*: agregar un archivo
  - *rm*: eliminar un archivo o directorio 
  - *ls*: listar archivos o directorios de un directorio

  Ejemplo del contenido de un archivo de órdenes: 
  
``` 
  ma /file1.dat md /Cursos 
  md /Juegos md /Cursos/ci-3881 
  ma /Cursos/ci-3881/clases.tex 
  ls /Cursos 
  ma /file2.tex 
  rm /file1.dat 
  rm /Cursos/ci-3881 
  ls /Juegos 
```

### Consideraciones de implementación

1.  Los nodos del árbol representarán un archivo o un directorio. La información
    que cada nodo debe contener es:
  - Nombre del archivo o directorio.
  - Tipo (directorio o archivo)
  - Número de archivos (sólo si es un directorio)
  - Apuntadores necesarios para armar la estructura del árbol.

2.  El nodo raíz es el directorio / y es creado por defecto. Esto quiere decir
    que la lista que representa el árbol de directorio, inicialmente se creará
    con un solo nodo: el nodo de /.


3.  Sólo se permite borrar un directorio si no contiene archivos. Esto debe ser
    validado y el programa emitirá un mensaje de error si el directorio no está
    vacío.

## Autor

Desarrollado por Alexis Ramón Ibarra Salas en septiembre de 2014
