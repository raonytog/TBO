#include <stdio.h>
#include "qu.h"

int main () {
    uf_init(10);

    uf_union(2, 9);
    uf_union(3, 4);
    uf_union(4, 9);
    uf_union(5, 6);
    // 0 1 2 3 4 5 6 7 8 9
    // 0 1 9 4 9 6 6 7 8 9
    // 0   1   9   6   7   8
    //        2 4  5
    uf_print();

    printf("3 e 9 estao conectados? %d\t", uf_connected(3, 9));
    return 0;
}