#ifndef _LIST_H_
#define _LIST_H_

typedef struct List List;

List *CreateList();

void AppendList(List *lista, int idx);

void *RemoveList(List *lista, int cycle);

void PrintList(List *lista);

int getListLenght(List *lista);

List *DefineCiclyc(List *lista);

void DestroyList(List *lista);

#endif // !_LISTA_H_