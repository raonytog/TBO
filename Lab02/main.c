#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bst.h"
#include "stack.h"
#include "queue.h"

void time_rec_preorder(Bst *tree);
void time_rec_inorder(Bst *tree);
void time_rec_postorder(Bst *tree);

void time_stack_preorder(Bst *tree, Stack *sp);
void time_stack_inorder(Bst *tree, Stack *sp);
void time_stack_postorder(Bst *tree, Stack *sp);

void time_queue_levelorder(Bst *tree, Queue *q);

int main (int argc, char const *argv[]) {
    int N = atoi(argv[1]);
    // int N = 10000000;

    srand(time(NULL));

    Queue *q = InitQueue();
    Stack *sp = InitStack();
    Bst *tree = EmptyBst();
    for (int i = 0 ;i < N; i++) { tree = InsertBst(tree, rand()); }
    printf("Altura da arvore: %d\n\n", HightBst(tree));

    time_rec_preorder(tree);
    time_rec_inorder(tree);
    time_rec_postorder(tree);
    printf("\n");

    time_stack_preorder(tree, sp);
    time_stack_inorder(tree, sp);
    time_stack_postorder(tree, sp);
    printf("\n");

    time_queue_levelorder(tree, q);
    printf("\n");
    
    DestroyQueue(q);    DestroyStack(sp);   DestroyBst(tree);
    return 0;
}

void time_rec_preorder(Bst *tree) {
    clock_t start = clock();
    rec_preorder(tree, PrintBstContent);
    clock_t end = clock();
    printf("Rec. Pre-Order: %lf\n", ((double)end - (double)start )/CLOCKS_PER_SEC);
}

void time_rec_inorder(Bst *tree) {
    clock_t start = clock();
    rec_inorder(tree, PrintBstContent);
    clock_t end = clock();
    printf("Rec. In-Order: %lf\n", ((double)end - (double)start )/CLOCKS_PER_SEC);
}

void time_rec_postorder(Bst *tree) {
    clock_t start = clock();
    rec_postorder(tree, PrintBstContent);
    clock_t end = clock();
    printf("Rec. Post-Order: %lf\n", ((double)end - (double)start )/CLOCKS_PER_SEC);
}

void time_stack_preorder(Bst *tree, Stack *sp) {
    clock_t start = clock();
    stack_preorder(tree, sp);
    clock_t end = clock();
    printf("Stack PreOrder: %lf\n", ((double)end - (double)start )/CLOCKS_PER_SEC);
}

void time_stack_inorder(Bst *tree, Stack *sp) {
    clock_t start = clock();
    stack_inorder(tree, sp);
    clock_t end = clock();
    printf("Stack InOrder: %lf\n", ((double)end - (double)start )/CLOCKS_PER_SEC);
}

void time_stack_postorder(Bst *tree, Stack *sp) {
    clock_t start = clock();
    stack_postorder(tree, sp);
    clock_t end = clock();
    printf("Stack PostOrder: %lf\n", ((double)end - (double)start )/CLOCKS_PER_SEC);
}

void time_queue_levelorder(Bst *tree, Queue *q) {
    clock_t start = clock();
    queue_levelorder(tree, q);
    clock_t end = clock();
    printf("Queue LevelOrder: %lf\n", ((double)end - (double)start )/CLOCKS_PER_SEC);
}