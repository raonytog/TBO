#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillVector(int *array, long unsigned int size);
void printArray(int *array, long unsigned int size);
void findLeader(int *array, long unsigned int size, int cycle);

int main (int argc, char const *argv[]) {
    clock_t start = clock();

    long unsigned int N = atol(argv[1]), cycle = 10;
    int *vetor = malloc(N * sizeof(int));
    fillArray(vetor, N);
    findLeader(vetor, N, cycle);
    free(vetor);

    clock_t end = clock();
    double sec = ( (double)end - (double)start ) / CLOCKS_PER_SEC;
    printf (" % lf\n" , sec);

    return 0;
}

void fillArray(int *array, long unsigned int size) {
    if (!array || size <= 0) return;
    for (long unsigned int i = 0; i < size; i++) array[i] = i+1;
}

void printArray(int *array, long unsigned int size) {
    if (!array || size <= 0) return;
    for (long unsigned int i = 0; i < size; i++) printf("%ld ", array[i]);
    printf("\n");
}

void findLeader(int *array, long unsigned int size, int cycle) {
    long unsigned int len = size, idx = 0;

    long unsigned int contador;
    while (len != 1) {
        contador = 0;
        while (contador < cycle) {
            if (array[idx] != 0) contador++;
            if (contador != cycle) idx++;
            idx = idx % size;
        }

        array[idx] = 0;
        len--;
    }
    
    long unsigned int ans = 0;
    for (long unsigned int i = 0; i < size; i++) {
        if (array[i] != 0) { printf("O lider eh %ld", array[i]); break;}
    }
}