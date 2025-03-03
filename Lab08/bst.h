#ifndef _BST_H_
#define _BST_H_

#include <stdbool.h>

typedef struct Bst Bst;

Bst *emptyBst();

bool isEmptyBst(Bst *tree);

Bst *initBst(int key);

Bst *insertFinalBst(Bst *tree, int key);

Bst *insertRootBst(Bst *tree, int key);

Bst *insertRootPartitionBst(Bst *tree, int key, int k);

int searchBst(Bst *tree, int key);

int getKeyBst(Bst *tree);

void destroyBst(Bst *tree);

int hightBst(Bst *tree);

void printBstContent(Bst *tree);

/** Recursion */
typedef void (*Visit)(Bst*);
void rec_preorder(Bst *tree, Visit visitFunc);
void rec_inorder(Bst *tree, Visit visitFunc);
void rec_postorder(Bst *tree, Visit visitFunc);

#endif