#ifndef _BST_H_
#define _BST_H_

#include <stdbool.h>

#include "stack.h"
#include "queue.h"

typedef struct Bst Bst;

Bst *EmptyBst();

bool IsEmptyBst(Bst *tree);

Bst *InitBst(int key);

Bst *InsertBst(Bst *tree, int key);

int SearchBst(Bst *tree, int key);

int GetKeyBst(Bst *tree);

void DestroyBst(Bst *tree);

int HightBst(Bst *tree);

void PrintBstContent(Bst *tree);

/** Recursion */
typedef void (*Visit)(Bst*);
void rec_preorder(Bst *tree, Visit visitFunc);
void rec_inorder(Bst *tree, Visit visitFunc);
void rec_postorder(Bst *tree, Visit visitFunc);

/** Stack */
void stack_preorder(Bst *tree, Stack *sp);
void stack_inorder(Bst *tree, Stack *sp);
void stack_postorder(Bst *tree, Stack *sp);

/** Queue */
void queue_levelorder(Bst *tree, Queue *q);

#endif