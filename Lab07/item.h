#ifndef _ITEM_H_
#define _ITEM_H_

#include <stdlib.h>
#include "str.h"

#define key(A) (A)
#define less(A, B) (key(A) < key(B)) /* se A é menor que B*/
#define exch(A, B) { String *t = A; A = B; B = t; } /* troca os valores de A e B*/
#define compexch(A, B) if (less(B, A)) exch(A, B) /* se B for menor que A, troca os valores */

#endif