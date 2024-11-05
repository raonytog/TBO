#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND 0
#define FOUND 1

void init_array(int *array, int N);
void print_array(int *array, int N);
void mark_multiple(int *array, int N);

int main (int argc, char const *argv[]) {
    if (argc <= 1) {
        printf("Sem diretorio informado\n"); exit(1);
    }
    int N = atoi(argv[1]);

    int array[N];
    init_array(array, N);
    mark_multiple(array, N);
    // print_array(array, N);

    return 0;
}


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
















    
    // array[0] = array[1] = FOUND;
    // for(int i = 2; i < N; i++) {
    //     for (int j = i+1; j < N; j++) {
    //         if (j % i == NOT_FOUND) 
    //             array[j] = FOUND;
    //     }

    //     while (array[i] == FOUND) { i++; }
    // }
}