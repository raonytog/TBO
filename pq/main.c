#include <stdio.h>

#include "PQ.h"

int main() {
    int values[] = {10, 7, 11, 5, 4, 13};

    PQ *queue = PQ_create(10);
    for (int i = 0; i < 6; i++) {
        PQ_insert(queue, values[i]);

        printf("min heap with %d insert: ", values[i]);
        PQ_print(queue);
    }

    int min = PQ_delmin(queue);
    printf("min heap without %d: ", min);
    PQ_print(queue);

    PQ_destroy(queue);

    return 0;
}