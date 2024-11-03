#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int main (int argc, char const *argv[]) {
    if (argc <= 1) {
        printf("Sem diretorio informado\n"); exit(1);
    }
    int N = atoi(argv[1]);

    int array[N];
    init_array(array, N);
    mark_multiple(array, N);
    // print_array(array, N);

    return 0;
}