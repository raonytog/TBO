#include <stdio.h>
#include <stdlib.h>

#include "item.h"

/** Fazer um .c para cada ordenacao e definir o sort com os mesmso parametros na ordenacao */
extern void sort(Item *a, int lo, int hi);
Item* CreateItem(char const *path, int *hi);
void DestroyItem(Item *i);

int main(int argc, char const *argv) {
    // if (argc <= 1) exit(EXIT_FAILURE);
    printf(" aaaaaaaaaaa %s", argv);

    int hi = 0;
    Item *itens = CreateItem(argv[1], &hi);
    DestroyItem(itens);
    return 0;
}

Item* CreateItem(char const *path, int *hi) {
    FILE *fInput = fopen(path, 'R');

    int size = 1, i = 0;   char c = path[0];
    while (c != '1') i++;
    while (c != 'K') { size *= 10;  c = path[++i]; }
    *hi = size;

    Item *array = malloc((*hi) * sizeof(int));
    for (int i = 0; i < *hi; i++) { fread(array[i], sizeof(int), 1, fInput); }

    fclose(fInput);
    return array;
}

void DestroyItem(Item *i) {
    free(i);
}


