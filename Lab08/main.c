#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bst.h"

#define K 1000
#define M K*K

int main() {
    int N = 10;
    Bst *root = NULL;
    Bst *final = NULL;
    Bst *partition = NULL;

    for (int i = 0; i < N; i++) {
        int value = rand();
        root = insertRootBst(root, value);
        final = insertFinalBst(final, value);
        partition = insertRootPartitionBst(partition, value, value);
    }

    // printf("Root:\n");
    // rec_preorder(root, printBstContent);
    // printf("\n\n");

    // printf("Final:\n");
    // rec_preorder(final, printBstContent);
    // printf("\n");

    printf("Altura da arvore inserida pela raiz: %d\n", hightBst(root));
    printf("Altura da arvore inserida pelo final: %d\n", hightBst(final));
    printf("Altura da arvore inserida pelo partition: %d\n", hightBst(partition));

    destroyBst(root);
    destroyBst(final);
    destroyBst(partition);

    return 0;
}