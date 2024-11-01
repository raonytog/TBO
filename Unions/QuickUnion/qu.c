#include "qu.h"

void uf_init(int size) {
    N = size;
    for (int i = 0; i < size; i++) {
        id[i] = i;
    }
}

void uf_union(int p, int q) {
   int i, j;
   i = uf_find(p);
   j = uf_find(q);
   id[i] = j;
}

int uf_find(int p) {
    while (p != id[p]) p = id[p];
    return p;
}

bool uf_connected(int p, int q) {
    int i, j;
    i = uf_find(p);
    j = uf_find(q);
    return i == j;
}

void uf_print() {
    for (int i = 0; i < N; i++) {
        printf("%d ", id[i]);
    }
    printf("\n");
}
