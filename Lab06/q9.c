/**
 * quick sort padrao
 */

#include "item.h"
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b); // Converter ponteiros para int * antes da subtração
}

void sort(Item *array, int lo, int hi) {
    int n = hi - lo + 1; // Número de elementos no intervalo
    qsort(array + lo, n, sizeof(Item), compare); // Passar o subarray correto para qsort
}