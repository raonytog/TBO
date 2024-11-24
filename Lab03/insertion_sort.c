#include "item.h"

void sort(Item *a, int lo, int hi) {
    for (int i = lo+1; i <= hi; i++) {
        for (int j = i-1; j > lo; j--) {
            if (less(a[j], a[j-1])) { 
                exch(a[j-1], a[j]); 
            }
        }
    }
}