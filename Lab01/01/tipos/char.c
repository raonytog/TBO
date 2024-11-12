#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "crivo.h"

struct Crivo {
    char *array;
    unsigned long int size;
};

Crivo *InitCrivo(unsigned long int size) {
    Crivo *this_crivo = malloc(sizeof(Crivo));
    this_crivo->size = size;
    
    // Aloca um bloco de memória contíguo para 'size' caracteres
    this_crivo->array = malloc(size * sizeof(char));
    
    FillCrivoArray(this_crivo);
    return this_crivo;
}

void FillCrivoArray(Crivo *this_crivo) {
    if (!this_crivo) return;

    // Inicializa o array
    this_crivo->array[0] = '1';
    this_crivo->array[1] = '1';
    for(unsigned long int i = 2; i < this_crivo->size; i++) {
        this_crivo->array[i] = '0';
    }
}

void ExecuteCrivo(Crivo *this_crivo) {
    for (unsigned long int i = 2; i < this_crivo->size; i++) {
        if (this_crivo->array[i] == '1') continue;
        for (unsigned long int j = i * 2; j < this_crivo->size; j += i) {
            this_crivo->array[j] = '1';
        }
    }
}

void PrintCrivoPrimes(Crivo *this_crivo) {
    if (!this_crivo) return;

    for(unsigned long int i = 0; i < this_crivo->size; i++) { 
        if (this_crivo->array[i] == '0') { printf("%lu ", i); }
    }
    printf("\n");
}

void DestroyCrivo(Crivo *this_crivo) {
    if (!this_crivo) return;

    free(this_crivo->array);
    free(this_crivo);
}
