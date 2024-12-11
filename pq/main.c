#include <stdio.h>

#include "PQ.h"
#include "event.h"
#include <stdlib.h>


static int t;

int main() {
    PQ *pq = PQ_create(10);
    Particle *p = NULL, *q = NULL;
    Event *e = NULL;
    for (int i = 0; i < 10; i++) {
        t = rand() % 1000;
        p = create_random_particle();
        q = create_random_particle();

        e = create_event(t, p, q);
        PQ_insert(pq, e);
    }
    PQ_print(pq);

    for (int i = 0; i < 10; i++) {
        printf("\n---===---\n");
        Event *e = PQ_delmin(pq);
        PQ_print(pq);
        printf("---===---\n");
    }

    return 0;
}