#ifndef _UF_H_
#define _UF_H_

#include <stdbool.h>

// Inicializa estrutura com N objetos numerados de 0 a N-1.
void *UF_init(int N, int *id);

// Adiciona uma conexao entre p e q.
void UF_union(int p, int q, int *id, int size);

// Retorna o identificador do componente de p (entre 0 a N-1).
int UF_find(int p, int *id, int size);

// Os objetos p e q estao no mesmo componente?
bool UF_connected(int p, int q, int *id, int size);

#endif
