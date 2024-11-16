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

int SearchBst(Bst *tree, int key) { 
    if (!tree) { printf("Error, there's no tree in SearchBst!"); return -1;}
    if (key == tree->key) return 1;
    else if (key > tree->key) return SearchBst(tree->right, key);
    else if (key < tree->key) return SearchBst(tree->left, key);
}

int GetKeyBst(Bst *tree) {
    if (!tree) { printf("Error, there's no tree in GetKeyBst!"); return -1;}
    return tree->key;
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

void PrintBstContent(Bst *tree) {
    if (!tree) return;
    // printf("%d ", GetKeyBst(tree));
}

void rec_preorder(Bst *tree, Visit visitFunc) {
    if (tree) {
        visitFunc(tree);
        rec_preorder(tree->left, visitFunc);
        rec_preorder(tree->right, visitFunc);
    }
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

void stack_preorder(Bst *tree, Stack *sp) {
    Bst *aux = tree;
    while (true) {
        while (aux) {
            PrintBstContent(aux);
            PushStack(sp, aux);
            aux = aux->left;
        }

        if (IsEmptyStack(sp)) break;
        aux = PopStack(sp);
        aux = aux->right;
    }
}

void stack_inorder(Bst *tree, Stack *sp) {
    Bst *aux = tree;
    while (true) {
        while (aux) {
            PushStack(sp, aux);
            aux = aux->left;
        }

        if (IsEmptyStack(sp)) break;
        aux = PopStack(sp);
        PrintBstContent(aux);
        aux = aux->right;
    }
}

/** Nao ta funcionando direito essa joça */
void stack_postorder(Bst *tree, Stack *sp) {
    Bst *aux = tree;
    while (true) {
        while (aux) {
            PushStack(sp, aux);
            aux = aux->left;
        }

        aux = PopStack(sp);
        PrintBstContent(aux);
        aux = aux->right;

        if (IsEmptyStack(sp)) break;
    }
}

void queue_levelorder(Bst *tree, Queue *q) {
    if (!tree || !q) return;

    Bst *auxiliar = tree;
    Enqueue(q, auxiliar);
    while (!IsEmpityQueue(q)) {
        auxiliar = Dequeue(q);
        if (auxiliar->left)  { Enqueue(q, auxiliar->left); }
        if (auxiliar->right) { Enqueue(q, auxiliar->right); }
        PrintBstContent(auxiliar);
    }
}