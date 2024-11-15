#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>

#define MAX 10

typedef struct Stack Stack;
typedef void(*printStack)(void*);

Stack *InitStack();

void PushStack(Stack *sp, void *data);

void* PopStack(Stack *sp);

void PrintStack(Stack *sp, printStack printSp);

void DestroyStack(Stack *sp);

bool IsEmptyStack(Stack *sp);

bool IsFullStack(Stack *sp);


#endif