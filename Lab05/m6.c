#include "item.h"

#define SZ2 (sz + sz)
#define MIN(X, Y) ((X < Y) ? (X) : (Y))

#define CUTOFF 1000

void insertion_sort(Item *a, int lo, int hi) {
    for (int i = lo+1; i <= hi; i++) {
        for (int j = i-1; j > lo; j--) {
            if (less(a[j], a[j-1])) { 
                exch(a[j-1], a[j]); 
            }
        }
    }
}

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

    // implementacao de cutoff
    if (hi <= lo + CUTOFF -1) { insertion_sort(array, lo, hi); return; }

    int mid = lo + (hi-lo) / 2;
    merge_sort(array, aux, lo, mid);
    merge_sort(array, aux, mid+1, hi);
    merge(array, aux, lo, mid, hi);
}

void sort(Item *a, int lo, int hi) {
    int N = (hi - lo) + 1;
    int y = N - 1;
    Item *aux = malloc(N * sizeof(Item));
    for (int sz = 1; sz < N; sz = SZ2) {
        for (int lo = 0; lo < N - sz; lo += SZ2) {
            int x = lo + SZ2 - 1;
            merge(a, aux, lo, lo + sz - 1, MIN(x, y));
        }
    }
    free(aux);
}