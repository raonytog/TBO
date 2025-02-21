#ifndef _ITEM_H_
#define _ITEM_H_

#include <stdlib.h>
#include "str.h"

typedef String* Item;

#define less(A, B) (compare(A, B) < 0)
#define less_from(A, B, d) (compare_from(A, B, d) < 0)
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

#endif