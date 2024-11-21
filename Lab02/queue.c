#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

typedef struct Cell Cell;

struct Cell {
    void* data;
    Cell *next;
};

struct Queue {
    struct Cell *first, *last;
};

Queue *InitQueue() {
    Queue *new = malloc(sizeof(Queue));
    new->first = new->last = NULL;
    return new;
}

void Enqueue(Queue *q, void* data) {
    if (!q) { printf("Error, no queue in Enqueue.\n"); return; }

    Cell *new = malloc(sizeof(Cell));
    new->data = data;
    new->next = NULL;

    // empity
    if (IsEmpityQueue(q)) { q->first = q->last = new; }

    // only one in queue
    else if (q->first == q->last) {
        q->first->next = new;
        q->last = new;
    }

    // more than one in queue
    else {
        q->last->next = new;
        q->last = new;
    }
}

void* Dequeue(Queue *q) {
    if (!q || IsEmpityQueue(q)) return NULL;

    void *aux = NULL;

    // only one in queue
    if (q->first == q->last) {
        aux = q->first->data;
        
        free(q->first);
        q->first = q->last = NULL;
        return aux;
    }

    // more than one in queue
    else {
        Cell *toDestroy = q->first;
        aux = q->first->data;

        q->first = q->first->next;
        free(toDestroy);
        return aux;
    }
}

void PrintQueue(Queue *q, print_fcptr printData) {
    if (!q) return;

    for (Cell *aux = q->first; aux; aux = aux->next) {
        printData(aux->data);
    }
    printf("\n");
}

void DestroyQueue(Queue *q) {
    if (!q) return;

    Cell *aux = q->first;
    while (aux) {
        aux = aux->next;
        free(q->first);
        q->first = aux;
    }
    free(q);
}

bool IsEmpityQueue(Queue *q) { return !q->first && !q->first; }