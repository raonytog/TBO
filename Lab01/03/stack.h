#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>

#define MAX 10

typedef struct CharStack CharStack;
typedef struct DoubleStack DoubleStack;

CharStack *InitCharStack();

void PushCharStack(CharStack *sp, char data);

char PopCharStack(CharStack *sp);

void PrintCharStack(CharStack *sp);

void DestroyCharStack(CharStack *sp);

bool IsEmptyCharStack(CharStack *sp);

bool IsFullCharStack(CharStack *sp);



DoubleStack *InitDoubleStack();

void PushDoubleStack(DoubleStack *sp, double data);

double PopDoubleStack(DoubleStack *sp);

void PrintDoubleStack(DoubleStack *sp);

void DestroyDoubleStack(DoubleStack *sp);

bool IsEmptyDoubleStack(DoubleStack *sp);

bool IsFullDoubleStack(DoubleStack *sp);


#endif