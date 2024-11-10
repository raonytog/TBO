#include "crivo.h"
#include "bitmap.h"

#include <stdio.h>
#include <stdlib.h>

struct Crivo {
    bitmap *map;
};

Crivo *InitCrivo() {
    Crivo *this_crivo = malloc(sizeof(Crivo));
    this_crivo->map = bitmapInit(MAX);
    FillCrivoArray(this_crivo);
    return this_crivo;
}

void FillCrivoArray(Crivo *this_crivo) {
    if (!this_crivo) return;

    bitmapAppendLeastSignificantBit(this_crivo->map, 1);
    bitmapAppendLeastSignificantBit(this_crivo->map, 1);
    
    for(int i = 2; i < MAX; i++) { 
        bitmapAppendLeastSignificantBit(this_crivo->map, 0);
    }
}


void ExecuteCrivo(Crivo *this_crivo) {
    for (int i = 2; i < MAX; i++) {
        if (bitmapGetBit(this_crivo->map, i) == '1') continue;
        for (int j = i*2; j < MAX; j += i) {
            bitmapSetBit(this_crivo->map, j, 1);
        }
    }
}

void PrintCrivoArray(Crivo *this_crivo) {
    if (!this_crivo) return;

    for(int i = 0; i < MAX; i++) { printf("%0x ", bitmapGetBit(this_crivo->map, i)); }
    printf("\n");
}

void PrintCrivoPrimes(Crivo *this_crivo) {
    for(int i = 0; i < MAX; i++) { 
        if (bitmapGetBit(this_crivo->map, i) == 0) { printf("%d ", i); }
    }
    printf("\n");
}

void DestroyCrivo(Crivo *this_crivo) {
    if (!this_crivo) return;
    else { bitmapLibera(this_crivo->map); free(this_crivo); }
}