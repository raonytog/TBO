#ifndef _SUFIX_H_
#define _SUFIX_H_

typedef struct Sufix Sufix;

#include "str.h"

Sufix *createSufix(String *s, int idx);

Sufix **createArraySufix(int size);

void printSufix(Sufix *sfx);

void printArraySufix(Sufix **sfx, int size);

void destroySufix(Sufix *sfx);

void destroArraySufix(Sufix **sfx, int size);

Sufix **fillSufixArray(int size, String *string);

int sufixCompare(const void *r, const void *s);

int sufixCompareFrom(Sufix *s, Sufix *t);

#endif // !_SUFIX_H_
#define _SUFIX_H_

