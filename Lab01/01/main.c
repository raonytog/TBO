#include <stdio.h>
#include <stdlib.h>

#include "crivo.h"

int main () {
    Crivo *crivo = InitCrivo();
    ExecuteCrivo(crivo);
    PrintCrivoPrimes(crivo);
    DestroyCrivo(crivo);
    return 0;
}
