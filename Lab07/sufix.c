#include <stdlib.h>
#include <stdio.h>

#include "sufix.h"

struct Sufix {
    String *str;
    int idx;
};

Sufix *createSufix(String *s, int idx) {
    if(!s || idx < 0) return NULL;

    Sufix *new = malloc(sizeof(Sufix));
    new->str = s;
    new->idx = idx;
    return new;
}

Sufix **createArraySufix(int size) {
    if (size <= 0) return NULL;

    Sufix **new = malloc(size * sizeof(Sufix*));
    if (!new) return NULL;
    return new;
}

Sufix **copyArraySufix(Sufix **sfx, int size) {
    Sufix **new = malloc(size * sizeof(Sufix*));
    
    for(int i = 0; i < size; i++) {
        new[i] = createSufix(sfx[i]->str, sfx[i]->idx);
    }

    return new;
}

Sufix **fillSufixArray(int size, String *string) {
    if (!string || size <= 0) return NULL;
    
    Sufix **sfx = createArraySufix(size);
    if (!sfx) return NULL;
    
    for(int i = 0; i < size; i++) {
        sfx[i] = createSufix(string, i);
    }

    return sfx;
}

String *getStringSufix(Sufix *sfx) {
    if (!sfx) return NULL;
    return sfx->str;
}

int getLenSufix(Sufix *sfx) {
    if (!sfx) return 0;
    return sfx->str->len;
}

int getIdxSufix(Sufix *sfx) {
    if (!sfx) return -1;
    return sfx->idx;
}

char char_at(Sufix *sfx, int i) {
    if (!sfx || i < 0 || i >= sfx->str->len - sfx->idx) return -1;
    return sfx->str->c[sfx->idx + i];
}


void printSufix(Sufix *sfx) {
    if (!sfx) return;
    print_substring(sfx->str, sfx->idx, sfx->str->len);
}

void printArraySufix(Sufix **sfx, int size) {
    if (!sfx || size <= 0) return;
    for(int i = 0; i < size; i++) {
        printSufix(sfx[i]);
    }
    printf("\n");
}

/** Nao libera memoria da string */
void destroySufix(Sufix *sfx) {
    if (!sfx) return;
    free(sfx);
}

void destroArraySufix(Sufix **sfx, int size) {
    if (!sfx || size <= 0) return;
    for(int i = 0; i < size; i++) {
        destroySufix(sfx[i]);
    }
    free(sfx);
}

int sufixCompare(const void *r, const void *s) {
    if (!r || !s) return 0;

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

int sfxCmp(Sufix *a, Sufix *b) {
    int sizeA = a->str->len - a->idx;
    int sizeB = b->str->len - b->idx;
    int min = sizeA < sizeB ? sizeA : sizeB;

    for(int count = 0, i = a->idx, j = b->idx; 
            count < min; 
            count++, i++, j++) {
        
        if(a->str->c[i] < b->str->c[j]) return -1;
        if(a->str->c[i] > b->str->c[j]) return 1;
    }

    return 0;
}
