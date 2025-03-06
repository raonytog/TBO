#ifndef _BST_H_
#define _BST_H_

#include <stdbool.h>

typedef struct Bst Bst;

Bst *EmptyBst();

bool IsEmptyBst(Bst *tree);

Bst *InitBst(int key);

Bst *InsertBst(Bst *tree, int key);

Bst *insertRandomBst(Bst * tree, int key);

void DestroyBst(Bst *tree);

int HightBst(Bst *tree);

int getSize(Bst *tree);

#endif