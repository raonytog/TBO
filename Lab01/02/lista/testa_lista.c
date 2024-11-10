#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "list.h"

int main(int argc, char const *argv[]) {
    clock_t start = clock();

    long unsigned int N = atol(argv[1]), M = 10; 

    List *lista = CreateList();
    for(int i = 0; i < N; i++) { AppendList(lista, i+1); }
    DefineCiclyc(lista);
    RemoveList(lista, M);
    DestroyList(lista);

    clock_t end = clock();
    double sec = ( (double)end - (double)start ) / CLOCKS_PER_SEC;
    printf (" % lf\n" , sec);

    return 0;
}