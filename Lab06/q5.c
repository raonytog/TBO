/**
 * quick sort padrao
 */

#include "item.h"

/** Stack */
int *stack = NULL;
int maxSize = 0;
int top = -1;

void stack_init(int max) {
    stack = malloc(max * sizeof(int));
    top = -1;
    maxSize = max;
}

void push(int item) {
    top++;
    stack[top] = item;
}

void push2(int a, int b) { push(a); puhs(b); }

int pop() {
    top--;
    return stack[top];
}

int partition(Item *array, int lo, int hi) {
    int i = lo, j = hi+1;
    Item pivot = array[lo];
    while(1) {
        /** Percorre o vetor da esquerda pra direita enquanto 
         * o ponteiro i for menor que o pivot v 
         * 
         * Em outras palavras, ate achar i maior que o pivot*/
        while (less(array[++i], pivot))
            if (i == hi) break;

        /** Percorre o vetor da esquerda pra direita enquanto 
         * o ponteiro j for maior que o pivot v 
         * 
         * Em outras palavras, ate achar j menor que o pivot */
        while (less(pivot, array[--j]))
            if (j == lo) break;

        /** Verifica cruzamento */
        if (i >= j) break;
            exch(array[i], array[j]);
    }

    exch(array[lo], array[j]);
    return j;
}

void quick_sort(Item *array, int lo, int hi) {
    stack_init(hi);
    push2(lo, hi);

    while(!stack_empty()) {
        lo = pop(); hi = pop();

        if (hi <= lo) continue;

        int i = partition(array, lo, hi);

        if (i-lo > hi-i) {
            push2(lo, i-1);
            push2(i+1, hi);

        } else {
            push2(i+1, hi);
            push2(lo, i-1);
        }
    }

    free(stack);
}