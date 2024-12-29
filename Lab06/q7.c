/**
 * quick sort com cutoff e mediana de 3 para o pivot
 */

#include "item.h"

void shuffle(Item *a, int N) {
    struct timeval tv; gettimeofday(&tv, NULL);
    srand48(tv.tv_usec);
    for (int i = N-1; i > 0; i--) {
        int j = (unsigned int) (drand48()*(i+1));
        exch(a[i], a[j]);
    }
}

int median(Item *array, int lo, int hi) {
    return (array[lo] + array[hi] + array[(lo+hi)/2])/3;
}

#define CUTOFF 10

void insertion_sort(Item *array, int lo, int hi) {
    for (int i = lo + 1; i <= hi; i++) {
        for (int j = i; j > lo && less(array[j], array[j-1]); j--) {
            exch(array[j], array[j-1]);
        }
    }
}

int partition(Item *array, int lo, int hi) {
    int i = lo, j = hi+1;
    Item v = median(array, lo, hi);
    while(1) {
        /** Percorre o vetor da esquerda pra direita enquanto 
         * o ponteiro i for menor que o pivot v 
         * 
         * Em outras palavras, ate achar i maior que o pivot*/
        while (less(array[++i], v))
            if (i == hi) break;

        /** Percorre o vetor da esquerda pra direita enquanto 
         * o ponteiro j for maior que o pivot v 
         * 
         * Em outras palavras, ate achar j menor que o pivot */
        while (less(v, array[--j]))
            if (j == lo) break;

        /** Verifica cruzamento */
        if (i >= j) break;
            exch(array[i], array[j]);
    }

    exch(array[lo], array[j]);
    return j;
}

void quick_sort(Item *array, int lo, int hi) {
    if (hi <= lo + CUTOFF - 1) {
        insertion_sort(array, lo, hi);
    }

    int j = partition(array, lo, hi);
    quick_sort(array, lo, j-1);
    quick_sort(array, j+1, hi);
}

