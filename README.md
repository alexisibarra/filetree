# Filetree

## Consideraciones


1.  Los nodos del árbol representarán un archivo o un directorio. La
    información que cada nodo debe contener es:
  - Nombre del archivo o directorio.
  - Tipo (directorio o archivo)
  - Número de archivos (sólo si es un directorio)
  - Apuntadores necesarios para armar la estructura del árbol.

2.  El nodo raíz debe ser el directorio / y debe estar creado por defecto. Esto
    quiere decir que la lista que representa el árbol de directorio,
    inicialmente se creará con un solo nodo: el nodo de /.

3.  El resto de los archivos y directorios se irán agregando con las órdenes:

```bash
$ md < nombre absoluto del nuevo directorio>
```
  md < nombre absoluto del nuevo directorio>

  ma < nombre absoluto del nuevo archivo>

4.  Adicionalmente se podrán eliminar archivos o directorios con la orden:

  rm < nombre absoluto del archivo o directorio>

  Listar los archivos o directorios de un directorio con la orden:

  ls < nombre absoluto del directorio>

**Sólo se permite borrar un directorio si no contiene archivos. Esto debe ser
validado y el programa emitirá un mensaje de error si el directorio no está
vacío.**


5.  La secuencia de órdenes para agregar/eliminar archivos/directorios será
    leída desde un archivo cuyo nombre es pasado como parámetro al momento de
    la ejecución. Habrá una orden por línea, sin líneas en blanco ni
    comentarios.  Ejemplo del contenido de un archivo de órdenes:

  ma /file1.dat

  md /Cursos
  
  md /Juegos
  
  md /Cursos/ci-3881
  
  ma /Cursos/ci-3881/clases.tex
  
  ls /Cursos
  
  ma /file2.tex
  
  rm /file1.dat
  
  rm /Cursos/ci-3881
  
  ls /Juegos

6. Luego de ejecutar todos los comandos se debe imprimir por pantalla el árbol
   resultante, en orden de búsqueda en anchura (BFS-Breadth First Search).

7. Para iniciar la ejecución del programa se usará la orden: filetree <nombre
   del archivo de órdenes>

