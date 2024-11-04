#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
    int N = 9;

    List *lista = CreateList();
    for(int i = 0; i < N; i++) { AppendList(lista, i+1); }
    DefineCiclyc(lista);
    RemoveList(lista, 5);
    DestroyList(lista);
    return 0;
}