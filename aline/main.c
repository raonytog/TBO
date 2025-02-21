#include <stdio.h>
#include <stdlib.h>
#include "str.h"
#include "suffix.h"
#include <time.h>

extern void sort(Suffix** a, int N);

void query(Suffix** sfx, int size, int contexto){
    char palavra[100];
    while(scanf("%[^\n]%*c", palavra)){
        String* query = create_string(palavra);
        for(int i=0; i<size; i++){
            int ind = getIndSuffix(sfx[i]);
            String* text = getStringSuffix(sfx[i]);
            if(equals_substring(text, ind, 0, query)){
                int inicio = ind - contexto;
                if(inicio < 0) inicio = 0;
                int fim = ind + query->len + contexto;
                if(fim > size) fim = size;
                print_substring(text, inicio, fim);
            }
        }
        destroy_string(query);
        printf("\n");
    }
}

int main(int argc, char const *argv[]){
    // FILE* pText = fopen(argv[1], "r");
    FILE* pText = fopen("in/teste.txt", "r");

    int context = 0;
    if(argc == 3){
        // context = atoi(argv[2]);
        context = 15;
    }

    int len = 0;
    fscanf(pText, "%d%*c", &len);

    char* text = malloc((len+1)*sizeof(char));
    char c = '\0';
    int ind = 0;
    for(int i=0; fscanf(pText, "%c", &c) == 1; i++){
        if((c == ' ' || c == '\n') && ind>0){
            if(text[ind-1] == ' ') continue;
            else if(c == '\n') c = ' ';
        }
        else if (c == '\n') c = ' ';
        text[ind] = c;
        ind++;
    }
    text[ind] = '\0';

    String* string = create_string(text);
    free(text);
    fclose(pText);

    Suffix** suffix = fill_suf_array(ind, string);

    /*
    clock_t start = clock();
    qsort(suffix, ind, sizeof(Suffix*), suffix_compare);
    clock_t end = clock();
    printf("tempo qsort: %lf\n", ((double)end - (double)start)/CLOCKS_PER_SEC);
    */
   
    clock_t start = clock();
    sort(suffix, ind);
    clock_t end = clock();
    printf("tempo radix sort: %lf\n", ((double)end - (double)start)/CLOCKS_PER_SEC);

    print_suf_array(suffix, ind);

    query(suffix, ind, context);

    destroy_suf_array(suffix, ind);
    destroy_string(string);
      
    return 0;
}