#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>

#define MAX 10

typedef struct Stack Stack;



Stack *InitStack();

void Push(Stack *sp, void *data);

void *Pop(Stack *sp);

void DestroyStack(Stack *sp);

bool IsEmptyStack(Stack *sp);

bool IsFullStack(Stack *sp);

#endif