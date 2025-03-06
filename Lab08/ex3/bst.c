#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

struct Bst {
    int key;
    int size;
    Bst *left, *right;
};

Bst *EmptyBst() { return NULL; }

bool IsEmptyBst(Bst *tree) { return tree == NULL; }

Bst *InitBst(int key) {
    Bst *new = malloc(sizeof(Bst));
    new->key = key;
    new->left = new->right = NULL;
    new->size = 1;

    return new;
}

static Bst* rotate_right(Bst *n) {
    Bst *t = n->left;
    n->left = t->right;
    t->right = n;

    t->size = getSize(n);
    n->size = 1 + getSize(n->right) + getSize(n->left);

    return t;
}

static Bst* rotate_left(Bst *n) {
    Bst *t = n->right;
    n->right = t->left;
    t->left = n;

    t->size = getSize(n);
    n->size = 1 + getSize(n->right) + getSize(n->left);

    return t;
}

Bst *InsertBst(Bst *tree, int key) {
    if(!tree) return InitBst(key);

    tree->size++;

    if (key > tree->key){
        tree->right = InsertBst(tree->right, key);
        tree = rotate_left(tree);

    } else if(key < tree->key){
        tree->left = InsertBst(tree->left, key);
        tree = rotate_right(tree);
    }

    return tree;
}

Bst *insertRandomBst(Bst * tree, int key) {
    if(!tree) return InitBst(key);
    double prob = (double) RAND_MAX / (getSize(tree) + 1);

    tree->size++;

    if(rand() < prob) return InsertBst(tree, key);
    
    if (key > tree->key) tree->right = insertRandomBst(tree->right, key);
    else if (key < tree->key) tree->left = insertRandomBst(tree->left, key);

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

int getSize(Bst *tree) {
    if (!tree) return 0;
    return tree->size;
}