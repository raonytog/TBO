#include <stdlib.h>

#include "suffix.h"

#define CUTOFF 10
#define R 256

static void exch(Suffix **a, int i, int j) {
    Suffix *aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

static int less(Suffix *a, Suffix *b) {
    return compare(getStringSuffix(a), getStringSuffix(b)) < 0;
}

void insertion_sort(Suffix **a, int lo, int hi) {
    for (int i = lo + 1; i <= hi; i++) {
        for (int j = i; j > lo && less(a[j], a[j-1]); j--) {
            exch(a, j, j-1);
        }
    }
}

int *create_count_array() {
    int *new = malloc((R+2) * sizeof(int));
    return new;
}

void clear_count_array(int *count) {
    for (int i = 0; i < R+2; i++) {
        count[i] = 0;
    }
}

void count_sort(Suffix **array, Suffix **aux, int *count,
    int lo, int hi, int d) {
    
    clear_count_array(count);
    // Count frequencies
    for (int i = lo; i <= hi; i++) {
        count[char_at(array[i], d) + 2]++;
    }

    // Compute cumulates
    for (int r = 0; r < R+1; r++) {
        count[r+1] += count[r];
    }

    // Move items
    for (int i = lo; i <= hi; i++) {
        int p = count[char_at(array[i], d) + 1]++;
        aux[p] = array[i];
    }
    
    // Copy back
    for (int i = lo; i <= hi; i++) {
        array[i] = aux[i - lo];
    }
}

void rec_MSD(Suffix **array, Suffix **aux, int lo, int hi, int d) {
    if (hi <= lo) return;

    int* count = create_count_array();

    // Key-indexed count.
    count_sort(array, aux, count, lo, hi, d);

    // Sort R arrays recursively.
    for (int r = 1; r < R+1; r++) {
        rec_MSD(array, aux, lo+count[r], lo+count[r+1]-1, d+1);
    }

    free(count);
}

void sort(Suffix **array, int N) {
    Suffix **aux = create_suf_array(N);
    rec_MSD(array, aux, 0, N-1, 0);
    free(aux);
}