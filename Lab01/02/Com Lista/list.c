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

static void DestroyCell(Cell *c) {
    if (!c) return;
    else free(c);
}


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

void *RemoveList(List *lista, int cycle) {
    if (!lista || cycle <= 0) return NULL;

    // lista vazia
    if (!lista->first && !lista->last) return;

    // um item na lista
    if (lista->first == lista->last) { free(lista->first); return; }

    // demais itens na lista
    Cell *aux = lista->first, *last = lista->last;
    while (getListLenght(lista) != 1) {
        for (int i = 0; i < cycle-1; i++) {
            last = aux;
            aux = aux->next;
        }
        printf("Saiu o %d\n", aux->idx);
        last->next = aux->next;

        if (aux == lista->first) { lista->first = lista->first->next; } 
        else if (aux == lista->last) { lista->last = last; }

        DestroyCell(aux);
        aux = last->next;
    }
    printf("O lider eh o %d\n", aux->idx);
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
    Cell *first = lista->first;
    Cell *aux = lista->first;
    if (aux) counter++;;

    aux = aux->next;
    while (first != aux) { aux = aux->next; counter++; }
    return counter;
}

List *DefineCiclyc(List *lista) {
    if (!lista) return NULL;
    lista->last->next = lista->first;
    return lista;
}

void DestroyList(List *lista) {
    if (!lista) return;
    free(lista->first);
    free(lista);
}
