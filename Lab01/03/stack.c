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

void PrintStack(Stack *sp, int wichStack) {
    if (!sp) return;

    if (wichStack == 0) {
        printf("\tNumeros: ");
        for(int i = 0; i < sp->top+1; i++) {
            printf("%d ", sp->data[i]);
        }
        printf("\n");

    } else {
        printf("\tOperadores: ");
        for(int i = 0; i < sp->top+1; i++) {
            printf("%c ", sp->data[i]);
        }
        printf("\n");
    }
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
