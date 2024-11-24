#include "item.h"

/** Ordena em subgrupos, mas so realiza uma troca por indice i, sendo sempre
 * com o menor valor encontrado dos valors dos indices superiores ao indcie i
 */
void sort(Item *a, int lo, int hi) {
    for (int i = lo; i < hi; i++) {
        int min = i;
        for (int j = i+1; j < hi; j++) {
            if (less(a[j], a[min])) { min = j; }
        }
        exch(a[min], a[i]);
    }
}