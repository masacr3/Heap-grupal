def upheap(arreglo,posicion,cmp):
    if posicion==0:
        return
    if cmp(arreglo[posicion],arreglo[padre]) < 0:
        return
    swap(arreglo[posicion],arreglo[padre])
    upheap(arreglo,padre,cmp)

 #implements on C

void uphead(void** arreglo, size_t pos, cmp_func_t cmp cmp){
    if ( pos == 0 ) return;
    
    //calculo padre
    
    size_t padre = ( pos - 1 ) / 2;
    
    if ( cmp ( arreglo[pos], arreglo[padre] ) < 0 ) return ;
    
    swap( arreglo[pos], arreglo[padre] );
    
    uphead ( arreglo , padre , cmp ) ;
}
