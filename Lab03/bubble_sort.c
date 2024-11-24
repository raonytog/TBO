#include "item.h"

#define true 1
#define false 0

void sort(Item *a, int lo, int hi) {
    /** Verify if is need to sort */
    for (int i = lo, j = i+1; i < hi-1, j < hi; i++, j++) {
        if (less(a[i], a[j] == false)) { return; }
    }

    for (int i = lo; i < hi-1; i++) {
        for(int j = i+1; j < hi; j++) {
            compexch(a[i], a[j]);
        }
    }
}