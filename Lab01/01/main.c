#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tipos/crivo.h"

int main (int argc, char const *argv[]) {
    clock_t start = clock();

    unsigned long int size = atol(argv[1]);
    Crivo *crivo = InitCrivo(size);
    ExecuteCrivo(crivo);
    DestroyCrivo(crivo);

    clock_t end = clock();
    double sec = ( (double)end - (double)start ) / CLOCKS_PER_SEC;
    printf (" % lf\n" , sec);
    return 0;
}
