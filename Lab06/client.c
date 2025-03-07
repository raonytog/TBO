#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "item.h"

extern void sort(Item *a, int lo, int hi);
Item* CreateItem(char const *path, int *hi);
void PrintItem(Item *a, int size);
void DestroyItem(Item *a);
double GetTimeToSort(Item *a, int lo, int hi);

#define K 1000
#define M K*K

int main(int argc, char const *argv[]) {
    if (argc <= 1) {
        printf("ERROR: file directory not found\n"); 
        exit(1);
    }

    char path[500];     strcpy(path, argv[1]);

    int hi = 0;
    Item *itens = CreateItem(path, &hi);
    double time = GetTimeToSort(itens, 0, hi);
    PrintItem(itens, hi);

    printf("\n\nTime spent: %.4lf\n", time);
    DestroyItem(itens);
    return 0;
}

Item* CreateItem(char const *path, int *hi) {
    if (!path || !hi) return NULL;

    FILE *fInput = fopen(path, "r");
    if (!fInput) { printf("Error while opening fInput!"); exit(EXIT_FAILURE); }

    int size = 1, i = 0;   char c = path[0];

    /** find array max size and stor it in 'hi' */
    while (c != '1') { i++; c = path[i]; }
    i++; c = path[i];
    while (c != 'M' && c != '.') { i++; size *= 10; c = path[i]; }

    if (c == '.') *hi = size;
    else *hi = size * M;

    /** fill array */
    Item *array = malloc((*hi) * sizeof(int));
    for (int i = 0; i < *hi; i++) { fscanf(fInput, "%d", &array[i]); }
    fclose(fInput);

    return array;
}

void PrintItem(Item *a, int size) {
    if (!a || size < 0) return;

    for (int i = 0; i < size; i++) {
        printf("%d\n", key(a[i]));
    }
}

void DestroyItem(Item *a) {
    if (!a) return;
    free(a);
}

double GetTimeToSort(Item *a, int lo, int hi) {
    clock_t start = clock();
    sort(a, lo, hi);
    clock_t end = clock();
    return ((double)end - (double)start)/CLOCKS_PER_SEC;
}

