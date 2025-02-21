#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "str.h"
#include "sufix.h"

String* readStringFromFile(FILE *input, int *size);
void binarySearch(Sufix **array, int lo, int hi, int max, String *query, int *newLo, int *newHi);
void doQuery(Sufix **array, int size, int context);
extern void sort(Sufix **array, int N);
void qSortPrintf(Sufix **sfx, int size);
void radixSortPrintf(Sufix **sfx, int size);

int main(int argc, char const *argv[]) {
    if (argc <= 1) return 0;

    FILE *input = fopen(argv[1], "r");
    // FILE *input = fopen("in/tale.txt", "r");
    if (!input) { printf("Error with file!\n"); }

    int size = 0;

    String *str = readStringFromFile(input, &size);
    Sufix **sfx = fillSufixArray(size, str);
    Sufix **sfxCopy = copyArraySufix(sfx, size);

    radixSortPrintf(sfxCopy, getLenSufix(sfxCopy[0]));
    qSortPrintf(sfx, getLenSufix(sfx[0]));

    // printArraySufix(sfx, size);
    int context = atoi(argv[2]);
    // int context = 15;
    doQuery(sfx, getLenSufix(sfx[0]), context);

    destroArraySufix(sfx, size);
    destroArraySufix(sfxCopy, size);
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

void doQuery(Sufix **array, int size, int context) {
    if (!array || size <= 0) return;

    char queryString[100];

    printf("\nEtapa de query!\n");
    printf("Digite uma chave de pesquisa: ");

    int lo = 0, hi = 1;
    while( scanf("%[^\n]%*c", queryString) == 1 ) {
        String *query = create_string(queryString);
        if (!query) { printf("Falha ao ler query!\n"); continue; }

        binarySearch(array, 0, size, size, query, &lo, &hi);

        for(int i = lo; i < hi; i++) {
            String *s = getStringSufix(array[i]);
            int start = getIdxSufix(array[i]) - context;
            if (start< 0) start = 0;

            int end = getIdxSufix(array[i])  + query->len + context;
            if (end > size) end = size;

            print_substring(s, start, end);
        }

        destroy_string(query);
        printf("\nDigite uma chave de pesquisa: ");
    }
}

void binarySearch(Sufix **array, int lo, int hi, int max, String *query, int *newLo, int *newHi) {
    if (!array || !query || (lo > hi)) return;

    int mid = lo + (hi - lo)/2;
    Sufix *r = array[mid], 
          *s = createSufix(query, 0);
    int cmp = sfxCmp(r, s);
    destroySufix(s);

    if (cmp < 0) { binarySearch(array, mid+1, hi, max, query, newLo, newHi); }
    else if (cmp > 0) { binarySearch(array, lo, mid-1, max ,query, newLo, newHi); }
    else {
        int i = 0, j = 0, idx = 0;
        for(i = mid-1; i >= 0; i--) {
            String *t = getStringSufix(array[i]);
            idx = getIdxSufix(array[i]);
            if (equals_substring(t, idx, 0, query) == false) 
                break;
        }
        *newLo = i+1;
        
        for(j = *newLo; j < max; j++) {
            String *t = getStringSufix(array[j]);
            idx = getIdxSufix(array[j]);
            if (equals_substring(t, idx, 0, query) == false) 
                break;
        }
        *newHi = j;
    } 
}

void qSortPrintf(Sufix **sfx, int size) {
    clock_t start = clock();
    printf("\nArray de sufixos ordenado com qsort:\n");
    qsort(sfx, size, sizeof(Sufix*), sufixCompare);
    // printArraySufix(sfx, size);
    clock_t end = clock();
    printf("qsort time spent: %f\n", ((double)end - (double)start)/CLOCKS_PER_SEC);
}

void radixSortPrintf(Sufix **sfx, int size) {
    clock_t start = clock();
    printf("\nArray de sufixos ordenado com radix sort:\n");
    sort(sfx, size);
    // printArraySufix(sfx, size);
    clock_t end = clock();
    printf("radix sort time spent: %f\n", ((double)end - (double)start)/CLOCKS_PER_SEC);
}