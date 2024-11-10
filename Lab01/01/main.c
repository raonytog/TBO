#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "crivo.h"

int main () {
    clock_t start = clock();

    Crivo *crivo = InitCrivo();
    ExecuteCrivo(crivo);
    DestroyCrivo(crivo);

    clock_t end = clock();
    double sec = ( (double)end - (double)start ) / CLOCKS_PER_SEC;
    printf (" % lf\n" , sec);
    return 0;
}
