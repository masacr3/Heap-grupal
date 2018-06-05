/*
  Hola marto, te comento que hay que organizar mas el codigo
  en el header tendriamos q poner la deficion de los prototipos
  auxiliares.

  te comento q las funciones faltan optimizarlas. como el tema de redimensionar
  el factor de carga, no lo tengo .. solo tengo lo q me diste de teoria

  cabe destacar q no vamos a usar vector_dinamico.h pero vamos a tomar bastantes ideas de maximo_hijo
  Bueno Exitos para fisica :P
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

/* prototipos funciones auxiliares */

//retorna NULL en caso que este fuera de rango
void* obtener(void** array,size_t n, size_t*pos);

//retorna la posicion max
//pre: valor1 y valor 2 son posiciones validas
size_t* obtener_max(void** array, size_t valor1, size_t valor2);




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


void uphead(void** arreglo, size_t pos, cmp_func_t cmp cmp){
  if ( pos == 0 ) return;

  //calculo padre
  size_t padre = ( pos - 1 ) / 2;

  if ( cmp ( arreglo[pos], arreglo[padre] ) < 0 ) return ;

  swap( arreglo[pos], arreglo[padre] );
  uphead ( arreglo , padre , cmp ) ;
}



bool heap_encolar(heap_t *heap, void *elem){
	if (!elem) return false;

  if (heap->cantidad == heap->capacidad ) redimensionar () // <--- redimensionar

  // agrego el elemento al arreglo
  // despues aplico upheap para que lo acomode solo
  heap->array[ heap->cantidad ] = elem;
  heap->cantidad++;

  upheap(heap->arreglo, heap->cantidad, heap->cmp );
	return true;
}

void downheap(void** array, size_t cantidad, size_t pibote ){
  if (pibote >= cantidad) return ;

  size_t pos_hijo_derecho = 2 * pibote + 1;
  size_t pos_hijo_izquierdo = 2 * pibote + 2;

  void* hijo_derecho = obtener(array, pos_hijo_derecho);
  void* hijo_izquierdo = obtener(array, pos_hijo_izquierdo);

  //termino de acomodar
  if ( !hijo_izquierdo && !hijo_derecho ) return ;

  //es por que existen los 2 hijos
  if (hijo_derecho){
    //calculo cual es el maximo
    size_t maximo_hijo = obtener_max( hijo_izquierdo,hijo_derecho);

    //cambio posiciones
    swap(array[pibote],array[maximo_hijo]);

    downheap(array,cantidad,maximo_hijo);
  }

  //si cai aca es por que solo existe el hijo derecho
  swap(array[pibote],array[pos_hijo_izquierdo]);

  downheap(array,cantidad,pos_hijo_izquierdo);
}

// deficion de las funciones auxiliares

void* obtener(void** array, size_t n, size_t pos){
  return pos >= n ? NULL : array[pos];
}

size_t obtener_max(void** array, size_t p, size_t p2){
  return cmp (array[p] < array[p2]) ? p : p2;
}

/*
        MACHETE :P
        padre = (pos - 1) / 2
        ultipadre = (len - 1 / 2);

        hijo-izq = 2 * pos + 1
        hijo-der = 2 * pos + 2

*/
