#include "uf.h"

#include <stdio.h>
#include <stdlib.h>

void UF_init(int N, int *id) {
    for (int i = 0; i < N; i++)
        id[i] = i;
}

void UF_union(int p, int q, int *id, int size) {
    int a = UF_find(p, id);
    int b = UF_find(q, id);
    id[a] = b;
}

int UF_find(int p, int *id) {
    while(p != id[p]) p = id[p];
    return p;
}

bool UF_connected(int p, int q, int *id) {
    return UF_find(p, id) == UF_find(q, id);
}
