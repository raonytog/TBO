#include "utils.h"

#include <stdio.h>


void init_array(int *array, int N) {
    for (int i = 0; i < N; i++) array[i] = NOT_FOUND;
}

void print_array(int *array, int N) {
    printf("\nOs primos sao:\n\t");
    for (int i = 0; i < N; i++) 
        if (array[i] == NOT_FOUND) printf("%d ", i);

    printf("\n\n");
}

void mark_multiple(int *array, int N) {
    array[0] = array[1] = FOUND;
    for(int i = 2; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (j % i == NOT_FOUND) 
                array[j] = FOUND;
        }

        while (array[i] == FOUND) { i++; }
    }
}