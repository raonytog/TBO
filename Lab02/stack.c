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

void PushStack(Stack *sp, void *data) {
    if (!sp || !data || IsFullStack(sp)) return;

    sp->top++;
    sp->data[sp->top] = data;
}

void* PopStack(Stack *sp) {
    if (!sp  || IsEmptyStack(sp)) return '\0';

    void *ans = sp->data[sp->top];
    sp->data[sp->top] = '\0';
    sp->top--;
    return ans;
}

void* PeekStack(Stack *sp) {
    if (!sp  || IsEmptyStack(sp)) return '\0';
    return sp->data[sp->top];
}

void PrintStack(Stack *sp, printStack printSp) {
    if (!sp) return;

    for(int i = 0; i < sp->top+1; i++) {
        printSp(sp->data[i]);
    }
    printf("\n");
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