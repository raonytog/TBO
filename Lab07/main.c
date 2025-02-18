#include <stdio.h>
#include <stdlib.h>

#include "str.h"
#include "sufix.h"

String* readStringFromFile(FILE *input, int *size);
void doQuery(Sufix **array, int size);
extern void sort(Sufix **array, int N);

int main() {
    FILE *input = fopen("in/moby.txt", "r");
    if (!input) { printf("Error with file!\n"); exit(EXIT_FAILURE); }

    int size = 0;

    String *str = readStringFromFile(input, &size);
    Sufix **arraySufix = fillSufixArray(size, str);

    /** Pre ordenar */
    // printf("Array de sufixos desordenados:\n");
    // printArraySufix(arraySufix, size);

    /** Ordenacao com qsort */
    // printf("\nArray de sufixos ordenado com qsort:\n");
    qsort(arraySufix, size, sizeof(Sufix*), sufixCompare);
    // printArraySufix(arraySufix, size);

    printf("\nEtapa de query!\n");
    doQuery(arraySufix, size);
    /** Ordenacao com msd raxis sort */
    // printf("\nArray de sufixos ordenado com radix sort:\n");
    // sort(arraySufix, size);
    // printArraySufix(arraySufix, size);

    destroArraySufix(arraySufix, size);
    destroy_string(str);
    fclose(input);

    return 0;
}

String* readStringFromFile(FILE *input, int *size) {
    if (!input || !size) return NULL;

    if (fscanf(input, "%d%*c", size) != 1 || *size <= 0) return NULL;

    char *str = malloc((*size+1) * sizeof(char));
    if (!str) return NULL;

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
    str[idx] = '\0';

    String *new = create_string(str);
    free(str);

    return new;
}

void doQuery(Sufix **array, int size) {
    char queryString[100];
    int context = 15;
    printf("Digite uma chave de pesquisa: ");
    while( scanf("%[^\n]%*c", queryString) == 1 ) {
        String *query = create_string(queryString);

        for(int i = 0; i < size; i++) {
            String *aux = getStringSufix(array[i]);
            int idx = getIdxSufix(array[i]);

            if (equals_substring(aux, idx, 0, query)) {
                int start = idx - context;
                if (start < 0) start = 0;
                
                int end = idx + query->len + context;
                if (end > size) end = size;
                
                print_substring(aux, start, end);
            }
        }

        destroy_string(query);
        printf("Digite uma chave de pesquisa: ");
    }
}