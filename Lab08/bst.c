#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

struct Bst {
    int key;
    Bst *left, *right;
};

Bst *emptyBst() { return NULL; }

bool isEmptyBst(Bst *tree) { return tree == NULL; }

Bst *initBst(int key) {
    Bst *new = malloc(sizeof(Bst));
    new->key = key;
    new->left = new->right = NULL;

    return new;
}

Bst *insertFinalBst(Bst *tree, int key) {
    if (!tree) return initBst(key);

    if (key > tree->key) tree->right = insertFinalBst(tree->right, key);
    else if (key < tree->key) tree->left = insertFinalBst(tree->left, key);

    return tree;
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

Bst *insertRootBst(Bst *tree, int key) {
    if (!tree) return initBst(key);

    int cmp = key - getKeyBst(tree);
    
    if (cmp < 0) {
        tree->left = insertRootBst(tree->left, key);
        tree = rotate_right(tree);
    } 
    else if (cmp > 0) {
        tree->right = insertRootBst(tree->right, key);
        tree = rotate_left(tree);
    }

    return tree;
}

Bst *insertRootPartitionBst(Bst *tree, int key, int k) {
    if (!tree) return initBst(key);

    int t = sizeBst(tree->left);  // Contar nós da subárvore esquerda

    if (t > k) {
        tree->left = insertRootPartitionBst(tree->left, key, k);
        tree = rotate_right(tree);
    }
    else if (t < k) {
        tree->right = insertRootPartitionBst(tree->right, key, k - t - 1);
        tree = rotate_left(tree);
    }
    
    return tree;
}


int searchBst(Bst *tree, int key) { 
    if (!tree) { printf("Error, there's no tree in SearchBst!"); return -1;}
    if (key == tree->key) return 1;
    else if (key > tree->key) return searchBst(tree->right, key);
    else if (key < tree->key) return searchBst(tree->left, key);
}

int getKeyBst(Bst *tree) {
    if (!tree) { printf("Error, there's no node in GetKeyBst!"); return -1;}
    return tree->key;
}

void destroyBst(Bst *tree) {
    if (!tree) return;

    destroyBst(tree->left);
    destroyBst(tree->right);
    free(tree);
}

static int max(int a, int b) { return a>b ? a:b; }
 
int hightBst(Bst *tree) {
    if (!tree || (!tree->left && !tree->right)) return 0;
    return 1 + max(hightBst(tree->right), hightBst(tree->left));
}

int sizeBst(Bst *tree) {
    if (!tree) return 0;
    return 1 + sizeBst(tree->left) + sizeBst(tree->right);
}

void printBstContent(Bst *tree) {
    if (!tree) return;
    printf("%d ", getKeyBst(tree));
}

void rec_preorder(Bst *tree, Visit visitFunc) {
    printf("(");
    if (tree) {
        visitFunc(tree);
        rec_preorder(tree->left, visitFunc);
        rec_preorder(tree->right, visitFunc);
    }
    printf(")");
}

void rec_inorder(Bst *tree, Visit visitFunc) {
    if (tree) {
        rec_inorder(tree->left, visitFunc);
        visitFunc(tree);
        rec_inorder(tree->right, visitFunc);
    }
}

void rec_postorder(Bst *tree, Visit visitFunc) {
    if (tree) {
        rec_postorder(tree->left, visitFunc);
        rec_postorder(tree->right, visitFunc);
        visitFunc(tree);
    }
}