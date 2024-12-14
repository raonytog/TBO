#include "item.h"

void merge(Item *a, Item *aux, int lo, int mid, int hi) {
    for (int k = lo; k <= hi; k++)
        aux[k] = a[k];

    int i = lo, j = mid+1;
    for (int k = lo; k <= hi; k++) {
        if (i > mid) a[k] = aux[j++];
        else if (j > hi) a[k] = aux[i++];
        else if (less(aux[j], aux[i])) a[k] = aux[j++];
        else a[k] = aux[i++];
    }   
}

void merge_sort(Item *array, Item *aux, int lo, int hi) {
    if (hi <= lo) return;

    int mid = lo + (hi-lo) / 2;
    merge_sort(array, aux, lo, mid);
    merge_sort(array, aux, mid+1, hi);
    merge(array, aux, lo, mid, hi);
}

void sort(Item *array, int lo, int hi) {
    if (!array || lo < 0) return;

    int size = (hi - lo) + 1;
    Item *aux = malloc(size * sizeof(Item));
    merge_sort(array, aux, lo, hi);
    free(aux);
}