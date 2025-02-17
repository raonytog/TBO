#include <stdlib.h>
#include <stdio.h>

#include "sufix.h"

struct Sufix {
    String *str;
    int idx;
};

Sufix *createSufix(String *s, int idx) {
    Sufix *new = malloc(sizeof(Sufix));
    new->str = s;
    new->idx = idx;
    return new;
}

Sufix **createArraySufix(int size) {
    Sufix **new = malloc(size * sizeof(Sufix*));
    return new;
}

void printSufix(Sufix *sfx) {
    print_substring(sfx->str, sfx->idx, sfx->str->len);
}

void printArraySufix(Sufix **sfx, int size) {
    for(int i = 0; i < size; i++) {
        printSufix(sfx[i]);
        printf("\n");
    }
}

/** Nao libera memoria da string */
void destroySufix(Sufix *sfx) {
    free(sfx);
}

void destroArraySufix(Sufix **sfx, int size) {
    for(int i = 0; i < size; i++) {
        destroySufix(sfx[i]);
    }
    free(sfx);
}

Sufix **fillSufixArray(int size, String *string) {
    Sufix **sfx = createArraySufix(size);
    
    for(int i = 0; i < size; i++) {
        sfx[i] = createSufix(string, i);
    }

    return sfx;
}

int sufixCompare(const void *r, const void *s) {
    Sufix *a = *(Sufix**)r;
    Sufix *b = *(Sufix**)s;

    /** Tamanho real de cada sufixo */
    int sizeA = a->str->len - a->idx;
    int sizeB = b->str->len - b->idx;
    int min = sizeA < sizeB ? sizeA : sizeB;

    for(int count = 0, i = a->idx, j = b->idx; 
            count < min; 
            count++, i++, j++) {
        
        if(a->str->c[i] < b->str->c[j]) return -1;
        if(a->str->c[i] > b->str->c[j]) return 1;
    }

    return sizeA - sizeB;
}
