/*
  Hola marto, tendriamos que  modificar el comportamiento del
  vector dinamico para que agarre cosas void. por lo cual
  tendriamos que Recodificar el como eliminamos los elementos
  del vector dinamico
*/


#include "heap.h"
#include <string.h>

#define TAMANIO_INICIAL :P //modify for work

/*struct*/
struct heap {
  size_t cantidad;
  size_t capacidad;
  void** vector;
  cmp_func_t cmp;
};

heap_t *heap_crear(cmp_func_t cmp){
  heap_t* heap = malloc( sizeof(heap_t) );

  if(!heap) return NULL;

  void** vector = vector_crear(TAMANIO_INICIAL);

  if(!vector){
    free(heap);
    return NULL;
  }

  heap->cantidad = 0;
  heap->capacidad = TAMANIO_INICIAL;
  heap->cmp = cmp;

  return heap;
}

size_t heap_cantidad(const heap_t *heap){
  return heap->cantidad;
}

void *heap_ver_max(const heap_t *heap){
  if ( heap->cantidad == 0 ) return NULL;

  return vector_obtener(heap->vector, 0) // el maximo se encuentra en la posicion maxima del vector
}

bool heap_esta_vacio(const heap_t *heap){
  return heap->cantidad == 0;
}



bool heap_encolar(heap_t *heap, void *elem){
	if (!elem) return false;

  if (heap->cantidad == heap->capacidad ) redimensionar () // <--- redimensionar

  // agrego el elemento al arreglo
  // despues aplico upheap para que lo acomode solo
  heap->array[ heap->cantidad ] = elem;
  heap->cantidad++;

  upheap(heap);
	return true;
}

/*

        padre = (pos - 1) / 2
        ultipadre = (len - 1 / 2);

        hijo-izq = 2 * pos + 1
        hijo-der = 2 * pos + 2

*/
