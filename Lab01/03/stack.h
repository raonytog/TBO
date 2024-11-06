#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>

#define MAX 10

typedef struct Stack Stack;



Stack *InitStack();

void Push(Stack *sp, void *data);

void *Pop(Stack *sp);


/// @brief print stack
/// @param sp stack pointer
/// @param wichStack 0 if numbers, 1 if operations
void PrintStack(Stack *sp, int wichStack);

void DestroyStack(Stack *sp);

bool IsEmptyStack(Stack *sp);

bool IsFullStack(Stack *sp);

#endif