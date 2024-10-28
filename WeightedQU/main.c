#include <stdio.h>
#include "wqu.h"

int main () {
    uf_init(10);

    uf_union(2, 9);
    uf_union(2, 8);
    uf_union(2, 6);
    uf_union(2, 3);
    uf_print();

    printf("3 e 9 estao conectados? %d\t", uf_connected(3, 9));
    return 0;
}