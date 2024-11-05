#include <stdio.h>
#include <stdlib.h>

void fillVector(int *array, int size);
void printArray(int *array, int size);
void findLeader(int *array, int size, int cycle);

int main (int argc, char const *argv[]) {
    // int N = atoi(argv[1]), cycle = atoi(argv[2]);
    int N = 10, cycle = 2;
    int vetor[N];
    fillArray(vetor, N);
    findLeader(vetor, N, cycle);

    return 0;
}

void fillArray(int *array, int size) {
    if (!array || size <= 0) return;
    for (int i = 0; i < size; i++) array[i] = i+1;
}

void printArray(int *array, int size) {
    if (!array || size <= 0) return;
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
}

void findLeader(int *array, int size, int cycle) {
    int len = size, idx = 0;

    while (len != 1) {
        for(int i = 0; i < cycle; ) {
            if (array[idx] != 0) { i++, idx++; }
            else { idx++; }
            idx = idx % size;
        }
        array[idx] = 0;
        len--;
    }

    printf("O lider eh %d", idx);
}