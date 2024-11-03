#include "list.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
    int idx;
    struct Cell *next;
} Cell;

struct List {
    Cell *first, *last;
};


List *CreateList() {
    List *new = malloc(sizeof(List));
    new->first = new->last = NULL;

    return new;
}

void AppendList(List *lista, int idx) {
    if (!lista || idx < 0) return;

    Cell *new = malloc(sizeof(Cell));
    new->idx = idx;
    new->next = NULL;

    if (!lista->first && !lista->last) {
        lista->first = lista->last = new;

    } else {
        lista->last->next = new;
        lista->last = new;
    }
}

List *RemoveList(List *lista, int cycle) {
    if (!lista || cycle <= 0) return NULL;

    Cell *aux = lista->first;
    while (getListLenght(lista) != 1) {
        for (int i = 0; i < cycle; aux = aux->next) { }
        // tenho que ver como remove mesmo heh
    }
}

void PrintList(List *lista) {
    if (!lista) return;

    Cell *aux = lista->first;
    while (aux) {
        printf("%d ", aux->idx);
        aux = aux->next;
    }
}

int getListLenght(List *lista) {
    if (!lista) return 0;

    int counter = 0;
    Cell *aux = lista->first;
    while (aux) { aux = aux->next; counter++; }

    return counter;
}
