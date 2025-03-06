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

static Bst* rotate_right(Bst *n) {
    Bst *t = n->left;
    n->left = t->right;
    t->right = n;
    return t;
}

static Bst* rotate_left(Bst *n) {
    Bst *t = n->right;
    n->right = t->left;
    t->left = n;
    return t;
}

Bst *InsertBst(Bst *tree, int key) {
    if (!tree) return InitBst(key);

    if (key > tree->key) {
        tree->right = InsertBst(tree->right, key);
        tree = rotate_left(tree);

    } else if (key < tree->key) {
        tree->left = InsertBst(tree->left, key);
        tree = rotate_right(tree);
    }

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