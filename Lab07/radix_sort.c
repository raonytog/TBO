#include <stdlib.h>

#include "sufix.h"

#define R 256

int *create_count_array() {
    int *new = malloc(R * sizeof(int));
    return new;
}

void clear_count_array(int *count) {
    for (int i = 0; i < R; i++) {
        count[i] = 0;
    }
}

void count_sort(Sufix **array, Sufix **aux, int *count,
    int lo, int hi, int d) {
    
    clear_count_array(count);
    for (int i = lo; i <= hi; i++) { // Count frequencies.
        count[char_at(array[i], d) + 2]++;
    }

    for (int r = 0; r < R+1; r++) { // Compute cumulates.
        count[r+1] += count[r];
    }

    for (int i = lo; i <= hi; i++) { // Move items.
        int p = count[char_at(array[i], d) + 1]++;
        aux[p] = array[i];
    }
    
    for (int i = lo; i <= hi; i++) { // Copy back.
        array[i] = aux[i - lo];
    }
}

void rec_MSD(Sufix **array, Sufix **aux, int lo, int hi, int d) {
    if (hi <= lo) return;

    int* count = create_count_array();
    count_sort(array, aux, count, lo, hi, d); // Key-indexed count.

    for (int r = 1; r < R+1; r++) // Sort R arrays recursively.
        rec_MSD(array, aux, lo+count[r], lo+count[r+1]-1, d+1);
    free(count);
}

void sort(Sufix **array, int N) {
    Sufix **aux = createArraySufix(N);
    rec_MSD(array, aux, 0, N-1, 0);
    free(aux);
}