#include "crivo.h"

#include <stdio.h>
#include <stdlib.h>

struct Crivo {
    int array[MAX];
};

Crivo *InitCrivo() {
    Crivo *this_crivo = malloc(sizeof(Crivo));
    FillCrivoArray(this_crivo);
    return this_crivo;
}

void FillCrivoArray(Crivo *this_crivo) {
    if (!this_crivo) return;

    this_crivo->array[0] = this_crivo->array[1] = 1;
    for(int i = 2; i < MAX; i++) { this_crivo->array[i] = 0; }
}

void ExecuteCrivo(Crivo *this_crivo) {
    for (int i = 2; i < MAX; i++) {
        if (this_crivo->array[i] == 1) continue;
        for (int j = i*2; j < MAX; j += i) {
            this_crivo->array[j] = 1;
        }
    }
}

void PrintCrivoArray(Crivo *this_crivo) {
    if (!this_crivo) return;

    for(int i = 0; i < MAX; i++) { printf("%d ", this_crivo->array[i]); }
    printf("\n");
}

void PrintCrivoPrimes(Crivo *this_crivo) {
    for(int i = 0; i < MAX; i++) { 
        if (this_crivo->array[i] == 0) { printf("%d ", i); }
    }
    printf("\n");
}

void DestroyCrivo(Crivo *this_crivo) {
    if (!this_crivo) return;
    else free(this_crivo);
}