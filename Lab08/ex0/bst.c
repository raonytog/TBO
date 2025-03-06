#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

struct Bst {
    int key;
    Bst *left, *right;
};

Bst *EmptyBst() { return NULL; }

bool IsEmptyBst(Bst *tree) { return tree == NULL; }

Bst *InitBst(int key) {
    Bst *new = malloc(sizeof(Bst));
    new->key = key;
    new->left = new->right = NULL;

    return new;
}

Bst *InsertBst(Bst *tree, int key) {
    if (!tree) return InitBst(key);

    if (key > tree->key) tree->right = InsertBst(tree->right, key);
    else if (key < tree->key) tree->left = InsertBst(tree->left, key);

    return tree;
}

void DestroyBst(Bst *tree) {
    if (!tree) return;

    DestroyBst(tree->left);
    DestroyBst(tree->right);
    free(tree);
}

static int max(int a, int b) { return a>b ? a:b; }
 
int HightBst(Bst *tree) {
    if (!tree) return -1;
    if (!tree->left && !tree->right) return 0;
    return 1 + max(HightBst(tree->right), HightBst(tree->left));
}