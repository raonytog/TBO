#include "primo.h"

#include "uf.h"
#include <stdio.h>

void analisa_primos(int *array, int size) {

    for(int i = 0; i < size-1; i++) {
        if (i == array[i]) {
            for(int j = i+1; j < size-1; j++) {
                if ( (j+2)%(i+2) == 0) UF_union()
            }
        }
    }
}
