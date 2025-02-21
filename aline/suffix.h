#ifndef SUFFIX_H
#define SUFFIX_H

#include <stdbool.h>
#include "str.h"

typedef struct {
    String *s;
    int index;
} Suffix;

Suffix* create_suffix(String* s, int ind);
Suffix** create_suf_array(int N);
Suffix** fill_suf_array(int size, String *string);

String* getStringSuffix(Suffix* s);
int getIndSuffix(Suffix* s);

int suffix_compare(const void *a, const void *b);

void destroy_suffix(Suffix *s);
void destroy_suf_array(Suffix** a, int N);

void print_suffix(Suffix *s);
void print_suf_array(Suffix** a, int N);

#endif
