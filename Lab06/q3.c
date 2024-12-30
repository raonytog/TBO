/**
 * quick sort com mediana de 3 para o pivot
 */

#include "item.h"

int bigger(Item *array, int lo, int hi) {
    if (array[lo] > array[hi]) return lo;
    return hi;
}

int median(Item *array, int lo, int hi) {
    int mid = (lo+hi)/2;

    int maior = bigger(array, lo, hi);
    if (maior == lo) return bigger(array, mid, hi);
    if (maior == hi) return bigger(array, lo, mid);
    return bigger(array, lo, hi);
}

int partition(Item *array, int lo, int hi) {
    int i = lo, j = hi+1;
    Item pivot = array[lo];
    while(1) {
        /** Percorre o vetor da esquerda pra direita enquanto 
         * o ponteiro i for menor que o pivot v 
         * 
         * Em outras palavras, ate achar i maior que o pivot*/
        while (less(array[++i], pivot))
            if (i == hi) break;

        /** Percorre o vetor da esquerda pra direita enquanto 
         * o ponteiro j for maior que o pivot v 
         * 
         * Em outras palavras, ate achar j menor que o pivot */
        while (less(pivot, array[--j]))
            if (j == lo) break;

        /** Verifica cruzamento */
        if (i >= j) break;
            exch(array[i], array[j]);
    }

    exch(array[lo], array[j]);
    return j;
}

void quick_sort(Item *array, int lo, int hi) {
    if (hi <= lo) return;

    int mediana = median(array, lo, hi);
    exch(array[lo], array[mediana]);

    int j = partition(array, lo, hi);
    quick_sort(array, lo, j-1);
    quick_sort(array, j+1, hi);
}

void sort(Item *array, int lo, int hi) {
    quick_sort(array, lo, hi);
}