#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bst.h"

int main (int argc, char const *argv[]) {
    int N = atoi(argv[1]);

    srand(time(NULL));

    Bst *random = EmptyBst(),
        *sorted = EmptyBst();

    for (int i = 0 ; i < N; i++) {
        random = insertRandomBst(random, rand());
        sorted = insertRandomBst(sorted, i);
    }

    printf("Altura da arvore random: %d\n\n", HightBst(random));
    printf("Altura da arvore sorted: %d\n\n", HightBst(sorted));
    
    DestroyBst(random);
    return 0;
}
