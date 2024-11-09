#ifndef _BST_H_
#define _BST_H_

typedef struct Bst Bst;

Bst *EmptyBst();

Bst *InitBst(int key);

Bst *InsertBst(Bst *tree, int key);

int SearchBst(Bst *tree, int key);

void DestroyBst(Bst *tree);

int HightBst(Bst *tree);

void PrintBst(Bst *tree);

#endif