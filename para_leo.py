def upheap(arreglo,posicion,cmp):
    if posicion==0:
        return
    if cmp(arreglo[posicion],arreglo[padre]) < 0:
        return
    swap(arreglo[posicion],arreglo[posicion-padre])
    upheap(arreglo,posicion-padre,cmp)
