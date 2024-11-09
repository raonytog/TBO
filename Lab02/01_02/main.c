#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bst.h"

int main (int argc, char const *argv[]) {
    int N = atoi(argv[1]), r = 0;
    srand(time(NULL));

    Bst *tree = EmptyBst();
    for (int i = 0 ;i < N; i++) {
        r = rand();
        tree = InsertBst(tree, r);
    }

    // PrintBst(tree); printf("\n");

    printf("Altura: %d\n", HightBst(tree));

    DestroyBst(tree);

    return 0;
}