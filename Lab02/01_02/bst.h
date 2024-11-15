#ifndef _BST_H_
#define _BST_H_

typedef struct Bst Bst;

Bst *EmptyBst();

Bst *InitBst(int key);

Bst *InsertBst(Bst *tree, int key);

int SearchBst(Bst *tree, int key);

int GetKeyBst(Bst *tree);

void DestroyBst(Bst *tree);

int HightBst(Bst *tree);

void PrintBstContent(Bst *tree);

typedef void (*Visit)(Bst*);
void rec_preorder(Bst *tree, Visit visitFunc);
void rec_inorder(Bst *tree, Visit visitFunc);
void rec_postorder(Bst *tree, Visit visitFunc);

#endif