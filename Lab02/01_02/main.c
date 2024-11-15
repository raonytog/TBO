#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bst.h"

int main (int argc, char const *argv[]) {
    int N = atoi(argv[1]), r = 0;
    srand(time(NULL));

    Bst *tree = EmptyBst();
    for (int i = 0 ;i < N; i++) {
        r = rand() % 100;
        tree = InsertBst(tree, r);
    }

    printf("Altura: %d\n", HightBst(tree));

    rec_preorder(tree, PrintBstContent);   printf("\n");
    rec_inorder(tree, PrintBstContent);     printf("\n");
    rec_postorder(tree, PrintBstContent); printf("\n");

    DestroyBst(tree);

    return 0;
}