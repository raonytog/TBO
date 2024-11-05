#include "stack.h"

#include <stdio.h>
#include <stdlib.h>


struct Stack {
    void *data[MAX];
    int base, top;
};

Stack *InitStack() {
    Stack *new = malloc(sizeof(Stack));
    
    new->base = 0;
    new->top = -1;
    return new;
}

void Push(Stack *sp, void *data) {
    if (!sp || !data || IsFullStack(sp)) return;

    sp->top++;
    sp->data[sp->top] = data;
}

void *Pop(Stack *sp) {
    if (!sp  || IsEmptyStack(sp)) return NULL;

    void *ans = sp->data[sp->top];
    sp->data[sp->top] = NULL;
    sp->top--;
    return ans;
}

void DestroyStack(Stack *sp) {
    if (!sp) return;
    free(sp);
}

bool IsEmptyStack(Stack *sp) {
    if (!sp) return false;
    return sp->top == -1;
}

bool IsFullStack(Stack *sp) {
    if (!sp) return false;
    return sp->top == MAX-1;
}
