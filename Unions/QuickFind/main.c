#include <stdio.h>
#include "uf.h"

int main () {
    uf_init(10);
    
    uf_union(1, 0);
    uf_union(5, 6);
    uf_union(9, 8);
    uf_print();

    uf_union(1, 9);
    uf_print();
    return 0;
}