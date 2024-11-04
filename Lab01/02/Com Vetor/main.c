#include <stdio.h>
#include <stdlib.h>

void fillVector(int *array, int size);
void printArray(int *array, int size);
void findLeader(int *array, int size, int cycle);

int main () {
    int N = 9, cycle = 5;
    int vetor[N];
    fillArray(vetor, N);
    printArray(vetor, N);
    findLeader(vetor, N, cycle);

    return 0;
}

void fillArray(int *array, int size) {
    for (int i = 0; i < size; i++) array[i] = i+1;
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
}

void findLeader(int *array, int size, int cycle) {
    
}