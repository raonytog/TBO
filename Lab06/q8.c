/**
 * quick sort com cutoff e mediana de 3 para o pivot
 */

#include "item.h"

void partition(Item *array, int lo, int hi, 
              int *lt, int *gt, int *i) {
    Item pivot = array[lo];
    while (*i <= *gt) {
        if (array[*i] < pivot) {
            exch(array[*lt], array[*i]);
            (*lt)++; (*i)++;

        } else if (array[*i] > pivot) {
            exch(array[*i], array[*gt]);
            (*gt)--;

        } else {
            (*i)++;
        }
    }
}

void quick_sort(Item *array, int lo, int hi) {
    if (hi <= lo) return;

    Item pivot = array[lo];
    int lt = lo, gt = hi, i = lo;
    partition(array, lo, hi, &lt, &gt, &i);
    quick_sort(array, lo, lt-1);
    quick_sort(array, gt+1, hi);
}

void sort(Item *array, int lo, int hi) {
    quick_sort(array, lo, hi);
}
