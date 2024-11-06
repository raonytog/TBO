#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int AvaliaExpressao(char *expressao, Stack *operador, Stack *operando);

int main () {
    Stack *numeros = InitStack(); // numero
    Stack *operacoes = InitStack(); // operacao

    // char expressao[] = "(5*(((9+8)*(4*6))+7))";
    char expressao[] = "(5*20)";
    int ans = AvaliaExpressao(expressao, numeros, operacoes);
    PrintStack(numeros, 0);
    PrintStack(operacoes, 1);

    printf("\n%s = %d\n\n", expressao, ans);

    DestroyStack(numeros); DestroyStack(operacoes);
    return 0;
}

int AvaliaExpressao(char *expressao, Stack *numeros, Stack *operacoes) {
    if (!expressao || !numeros || !operacoes) return 0;

    char c = '\0';
    for(int i = 0, c = expressao[i]; i < strlen(expressao); c = expressao[i++]) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            Push(operacoes, c);

        } else if (c >= '0' && c <= '9') {
            Push(numeros, atof(c));

        } else if (c == ')') {
            char op = Pop(operacoes);
            double val1 = Pop(numeros), val2 = Pop(numeros), ans = 0;
            if      (op == '+') ans = val1 + val2;
            else if (op == '-') ans = val1 - val2; 
            else if (op == '*') ans = val1 * val2; 
            else if (op == '/') ans = val1 / *val2; 
            Push(numeros, ans);
        }
    }
    
    return Pop(numeros);
}