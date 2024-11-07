#include "list.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
    int idx;
    struct Cell *next;
} Cell;

struct List {
    Cell *first, *last;
    int lenght;
};

static void DestroyCell(Cell *c) {
    if (!c) return;
    else free(c);
}

List *CreateList() {
    List *new = malloc(sizeof(List));
    new->first = new->last = NULL;
    new->lenght = 0;

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

    lista->lenght++;
}

void RemoveList(List *lista, int cycle) {
    if (!lista || cycle <= 0) return;

    // lista vazia
    if (!lista->first && !lista->last) return;

    // um item na lista
    if (lista->first == lista->last) { free(lista->first); lista->lenght--; return; }

    // demais itens na lista
    Cell *aux = lista->first, *last = lista->last;
    while (lista->lenght != 1) {
        for (int i = 0; i < cycle-1; i++) {
            last = aux;
            aux = aux->next;
        }

        last->next = aux->next;
        lista->lenght--;

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
