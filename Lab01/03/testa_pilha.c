#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int AvaliaExpressao(char *expressao, Stack *operador, Stack *operando);

int main () {
    Stack *operador = InitStack();
    Stack *operando = InitStack();

    // char expressao[] = "(5*(((9+8)*(4*6))+7))";
    char expressao[] = "(5*20)";
    printf("%s = %d\n\n", expressao, AvaliaExpressao(expressao, operador, operando));
    return 0;
}

int AvaliaExpressao(char *expressao, Stack *operador, Stack *operando) {
    if (!expressao || !operador || !operando) return 0;

    for(int i = 0; i < strlen(expressao); i++) {

        if (expressao[i] >= '0' && expressao[i] <= '9') {
            
        }

        else if (expressao[i] == ')') {

        } else if (expressao[i] == '*') {

        } else if (expressao[i] == '/') {

        } else if (expressao[i] == '+') {

        } else if (expressao[i] == '-');
    }
}