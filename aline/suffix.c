#include <stdio.h>
#include <stdlib.h>
#include "suffix.h"

Suffix* create_suffix(String* s, int ind){
    Suffix* suf = malloc(sizeof(Suffix));
    suf->index = ind;
    suf->s = s;
    return suf;
}

Suffix** create_suf_array(int N){
    Suffix** arr = malloc(N*sizeof(Suffix*));
    return arr;
}

Suffix** fill_suf_array(int size, String *string){
    Suffix** suf_arr = create_suf_array(size);
    for(int i=0; i<size; i++){
        suf_arr[i] = create_suffix(string, i);
    }
    return suf_arr;
}

String* getStringSuffix(Suffix* s){
    return s->s;
}

int getIndSuffix(Suffix* s){
    return s->index;
}

int suffix_compare(const void *a, const void *b){
    Suffix* s = *(Suffix**) a;
    Suffix* t = *(Suffix**) b;

    int s_ind = s->index, t_ind = t->index, s_tam = s->s->len - s->index, t_tam = t->s->len - t->index;
    int min = s_tam < t_tam ? s_tam : t_tam;

    for (int i = 0; i < min; i++) {
        if (s->s->c[i + s_ind] < t->s->c[i + t_ind]) { return -1; }
        if (s->s->c[i + s_ind] > t->s->c[i + t_ind]) { return  1; }
    }

    return s_tam - t_tam;
}

void destroy_suffix(Suffix *s){
    free(s);
}

void destroy_suf_array(Suffix** a, int N){
    for(int i=0; i<N; i++){
        destroy_suffix(a[i]);
    }
    free(a);
}

void print_suffix(Suffix *s){
    print_substring(s->s, s->index, s->s->len);
}

void print_suf_array(Suffix** a, int N){
    for(int i=0; i<N; i++){
        print_suffix(a[i]);
        // printf("\n");
    }
}