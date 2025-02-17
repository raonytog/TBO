#include <stdio.h>
#include <stdlib.h>

#include "str.h"
#include "sufix.h"

String* readStringFromFile(FILE *input, int *size);
extern void sort(Sufix **array, int N);

int main() {
    FILE *input = fopen("in/abra.txt", "r");
    if (!input) { printf("Error with file!\n"); exit(EXIT_FAILURE); }

    int size = 0;

    String *str = readStringFromFile(input, &size);
    Sufix **arraySufix = fillSufixArray(size, str);

    /** Pre ordenar */
    printf("Array de sufixos desordenados:\n");
    printArraySufix(arraySufix, size);

    /** Ordenacao com qsort */
    // printf("\nArray de sufixos ordenado com qsort:\n");
    // qsort(arraySufix, size, sizeof(String*), sufixCompare);
    // printArraySufix(arraySufix, size);

    /** Ordenacao com msd raxis sort */
    printf("\nArray de sufixos ordenado com radix sort:\n");
    sort(arraySufix, size);
    printArraySufix(arraySufix, size);

    destroArraySufix(arraySufix, size);
    destroy_string(str);
    fclose(input);

    return 0;
}

String* readStringFromFile(FILE *input, int *size) {
    if (!input) return NULL;

    fscanf(input, "%d%*c", size);

    char *str = malloc((*size+1) * sizeof(char));

    char aux = '\0';
    int i = 0, idx = 0, count = 0;

    for (i = 0; fscanf(input, "%c", &aux) == 1; i++) {
        if (aux == ' ' && i > 0) {
            if (str[idx-1] == ' ') continue;

        } else if (aux == '\n') {
            aux = ' ';
            if (count) continue;
            else count = 1;

        } else count = 0;

        str[idx++] = aux;
    }
    str[i] = '\0';

    String *new = create_string(str);
    free(str);

    return new;
}