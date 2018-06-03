#include "heap.h"
#include "vector_dinamico.h"
#include <string.h>

#define TAMANIO_INICIAL :P //modify for work

/*struct*/
struct heap {
	size_t cant;
	size_t tam;
	vector_t* vector;
  cmp_func_t cmp;
};

heap_t *heap_crear(cmp_func_t cmp){
  heap_t* heap = malloc( sizeof(heap_t) );

  if(!heap) return NULL;

  vector_t *vector = vector_crear(TAMANIO_INICIAL);

  if(!vector){
    free(heap);
    return NULL;
  }

  heap->cant = 0;
  heap->tam = TAMANIO_INICIAL;
  heap->cmp = cmp;

  return heap;
}

size_t heap_cantidad(const heap_t *heap){
  return heap->cant;
}

void *heap_ver_max(const heap_t *heap){
  if ( heap->cant == 0 ) return NULL;

  return vector_obtener(heap->vector, 0) // el maximo se encuentra en la posicion maxima del vector
}

bool heap_esta_vacio(const heap_t *heap){
  return heap->cant == 0;
}
