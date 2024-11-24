#include "item.h"

#define true 1
#define false 0

/**
 * Ordena da esquerda a direita
 * Verifica se houve alguma troca (caso contrario, o vetor ja esta ordenado)
 * Se houver troca, decrementa o limite superior
 * Ordena da direita a esquerda
 * Verifica se houve alguma troca (caso contrario, o vetor ja esta ordenado)
 * Se houver troca, decrementa o limite inferior
 * 
 * Repete até que nao aconteca trocas nas iteracoes
 */
void sort(Item *a, int lo, int hi) {
    int trade = true;
    int start = lo;
    int end = hi;

    while(trade) {
        /** Ordena da esquerda pra direita */
        trade = false;
        for(int i = start; i < end-1; i++) {
            if (less(a[i+1], a[i])) {
                exch(a[i], a[i+1]);
                trade = true;
            }
        }

        if (!trade) break;  /** Quer dizer que ja ta ordenado */
        trade = false;      /** Reseta para começar a ordenar da direita pra esquerda*/
        end--; /** Aqui, o final ja esta ordenado, necessariamente */

        for(int j = end-2; j >= start; j--) {
            if (less(a[j+1], a[j])) {
                exch(a[j], a[j+1]);
                trade = true;
            }
        }

        start++; /** Aqui, o começo ja é o menor, necessariamente */
        if (!trade) break;  /** Quer dizer que ja ta ordenado */
    }
}