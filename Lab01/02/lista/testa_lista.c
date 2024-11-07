#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
    int N = 10000000, M = 10; //0m19,615s

    List *lista = CreateList();
    for(int i = 0; i < N; i++) { AppendList(lista, i+1); }
    DefineCiclyc(lista);
    RemoveList(lista, M);
    DestroyList(lista);

    return 0;
}