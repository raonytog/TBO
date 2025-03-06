#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bst.h"

int main (int argc, char const *argv[]) {
    int N = atoi(argv[1]);

    srand(time(NULL));

    Bst *tree = EmptyBst();
    for (int i = 0 ;i < N; i++)
        tree = InsertBst(tree, rand());
    printf("Altura da arvore: %d\n", HightBst(tree));
    
    DestroyBst(tree);
    return 0;
}
