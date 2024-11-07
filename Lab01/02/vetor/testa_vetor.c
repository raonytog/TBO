#include <stdio.h>
#include <stdlib.h>

void fillVector(int *array, int size);
void printArray(int *array, int size);
void findLeader(int *array, int size, int cycle);

int main () { //0m0,137s
    int N = 100000, cycle = 10;
    int vetor[N];fillArray(vetor, N);
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

    int contador;
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
    
    int ans = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] != 0) { printf("O lider eh %d", array[i]); break;}
    }
}