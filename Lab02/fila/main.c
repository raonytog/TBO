#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

void PrintInt(void *data) { printf("%d ", *(int*)data); }

int main () {
    Queue *fila = InitQueue();
    int *num1 = malloc(sizeof(int)),
        *num2 = malloc(sizeof(int)),
        *num3 = malloc(sizeof(int)),
        *num4 = malloc(sizeof(int));

    *num1 = 1,
    *num2 = 2,
    *num3 = 3,
    *num4 = 4,

    Enqueue(fila, num1);
    Enqueue(fila, num2);
    Enqueue(fila, num3);
    Enqueue(fila, num4);
    PrintQueue(fila, PrintInt);

    Dequeue(fila);
    Dequeue(fila);
    PrintQueue(fila, PrintInt);

    free(num1); free(num2); free(num3); free(num4);
    DestroyQueue(fila);

    return 0;
}