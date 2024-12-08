#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"

#define key(A) (A)
#define less(A, B) (key(A) < key(B)) /* se A é menor que B*/
#define greater(A, B) (key(A) > key(B))
#define exch(A, B) { int t = A; A = B; B = t; } /* troca os valores de A e B*/
#define compexch(A, B) if (less(B, A)) exch(A, B) /* se B for menor que A, troca os valores */

static int PQ_max_size(PQ *pq);
static void fix_up(PQ *pq, int N);
static void fix_down(PQ *pq, int size, int N);

/**
 * Pai é acessado por array[N/2]
 * Filhos são acessados por array[2*N] e array[2*N + 1]
 */
struct pq {
    int *array;
    int max_size;
    int current_size;
};

PQ* PQ_create(int max_N) {
    if (max_N <= 0) return NULL;

    PQ *queue = malloc(sizeof(PQ));
    queue->max_size = max_N;
    queue->current_size = 0;

    queue->array = calloc(max_N, sizeof(int));

    return queue;
}

void PQ_destroy(PQ *pq) {
    if (!pq) return;

    free(pq->array);
    free(pq);
}

void PQ_insert(PQ *pq, int data) {
    if (!pq || !data) return;
    if (PQ_size(pq) == PQ_max_size(pq)) return;

    pq->current_size++;
    pq->array[pq->current_size] = data;
    fix_up(pq, PQ_size(pq));
}

int PQ_delmin(PQ *pq) {
    if (!pq) return -1;

    int min = pq->array[0];
    exch(pq->array[PQ_size(pq)], pq->array[1]);
    pq->current_size--;

    fix_down(pq, PQ_size(pq), 1);

    return min;
}

bool PQ_is_empty(PQ *pq) {
    if (!pq) return false;
    return pq->current_size == 0;
}

int PQ_size(PQ *pq) {
    if (!pq) return false;
    return pq->current_size;
}

void PQ_print(PQ *pq) {
    if (!pq) return;
    for (int i = 1; i < PQ_size(pq)+1; i++) {
        printf("%d ", pq->array[i]);
    }
    printf("\n");
}

static int PQ_max_size(PQ *pq) { 
    if (!pq) return 0;
    return pq->max_size;
}

static void fix_up(PQ *pq, int N) {
    if (!pq || N <= 0) return;

    while (N > 1 && greater(pq->array[N/2], pq->array[N])) {
        exch(pq->array[N], pq->array[N/2]);
        N = N/2;
    }
}

static void fix_down(PQ *pq, int size, int N) {
    if (!pq || size <= 0 || N <= 0) return;

    while (2*N <= size) {
        int idx = 2*N;
        if (idx < size && greater(pq->array[idx], pq->array[idx+1]))
            idx++;

        if (!greater(pq->array[N], pq->array[idx]))
            break;

        exch(pq->array[N], pq->array[idx]);
        N = idx;
    }
}
