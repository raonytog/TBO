#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct CharStack {
    char data[MAX];
    int base, top;
};

CharStack *InitCharStack() {
    CharStack *new = malloc(sizeof(CharStack));
    new->base = 0;
    new->top = -1;
    return new;
}

void PushCharStack(CharStack *sp, char data) {
    if (!sp || !data || IsFullCharStack(sp)) return;

    sp->top++;
    sp->data[sp->top] = data;
}

char PopCharStack(CharStack *sp) {
    if (!sp  || IsEmptyCharStack(sp)) return '\0';

    char ans = sp->data[sp->top];
    sp->data[sp->top] = '\0';
    sp->top--;
    return ans;
}

void PrintCharStack(CharStack *sp) {
    if (!sp) return;

    printf("\tOperacoes: ");
    for(int i = 0; i < sp->top+1; i++) {
        printf("%c ", sp->data[i]);
    }
    printf("\n");
}

void DestroyCharStack(CharStack *sp) {
    if (!sp) return;
    free(sp);
}

bool IsEmptyCharStack(CharStack *sp) {
    if (!sp) return false;
    return sp->top == -1;
}

bool IsFullCharStack(CharStack *sp) {
    if (!sp) return false;
    return sp->top == MAX-1;
}

// -------------------------------------------------------------------------

struct DoubleStack {
    double data[MAX];
    int base, top;
};

DoubleStack *InitDoubleStack() {
    DoubleStack *new = malloc(sizeof(DoubleStack));
    new->base = 0;
    new->top = -1;
    return new;
}

void PushDoubleStack(DoubleStack *sp, double data) {
    if (!sp || !data || IsFullDoubleStack(sp)) return;

    sp->top++;
    sp->data[sp->top] = data;
}

double PopDoubleStack(DoubleStack *sp) {
    if (!sp  || IsEmptyDoubleStack(sp)) return 0;

    double ans = sp->data[sp->top];
    sp->data[sp->top] = 0;
    sp->top--;
    return ans;
}

void PrintDoubleStack(DoubleStack *sp) {
    if (!sp) return;

    printf("\tNumeros: ");
    for(int i = 0; i < sp->top+1; i++) {
        printf("%lf ", sp->data[i]);
    }
    printf("\n");
}

void DestroyDoubleStack(DoubleStack *sp) {
    if (!sp) return;
    free(sp);
}

bool IsEmptyDoubleStack(DoubleStack *sp) {
    if (!sp) return false;
    return sp->top == -1;
}

bool IsFullDoubleStack(DoubleStack *sp) {
    if (!sp) return false;
    return sp->top == MAX-1;
}
