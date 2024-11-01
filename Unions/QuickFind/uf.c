#include "uf.h"

void uf_init(int size) {
    N = size;
    for (int i = 0; i < size; i++) {
        id[i] = i;
    }
}

void uf_union(int p, int q) {
    // check p or q is equal or bigger than N, also with p or q being negative
    if ( (p >= N || q >= N) || (p < 0 || q < 0) ) {
        printf("Union is impossible!\n");
        return;
    }
     
    int idp = id[p];
    int idq = id[q];
    for (int i = 0; i < N; i++) {
        if (id[i] == idp) id[i] = idq;
    }
}

int uf_find(int p) {
    return id[p];
}

bool uf_connected(int p, int q) {
    return id[p] == id[q];
}

void uf_print() {
    for (int i = 0; i < N; i++) {
        printf("%d ", id[i]);
    }
    printf("\n");
}
