#include "wqu.h"

void uf_init(int size) {
    N = size;
    for (int i = 0; i < size; i++) {
        id[i] = i;
        weight[i] = -1;
    }
}

void uf_union(int p, int q) {
    int i = uf_find(p), j = uf_find(q);

    if (i == j) return;
    
    if (weight[i] > weight[j]) { 
        id[j] = i;
        weight[i] += weight[j]; 

    } else { 
        id[i] = j; 
        weight[j] += weight[i];
    }
}

int uf_find(int p) {
    while (p != id[p]) {
        id[p] = id[id[p]];
        p = id[p];
    }
    return p;
}

bool uf_connected(int p, int q) {
    return uf_find(p) == uf_find(q);
}

void uf_print() {
    for (int i = 0; i < N; i++) {
        printf("%d ", id[i]);
    }
    printf("\n");
}
