#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
    int N = 10;

    List *lista = CreateList();
    for(int i = 0; i < N; i++) {
        AppendList(lista, i);
    }
    
    printf("%d\n", getListLenght(lista));
    PrintList(lista);
    return 0;
}