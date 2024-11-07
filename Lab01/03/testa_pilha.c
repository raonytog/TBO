#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

double AvaliaExpressao(char *expressao, DoubleStack *numero, CharStack *operacoes);

int main () {
    DoubleStack *numeros = InitDoubleStack();
    CharStack *operacoes = InitCharStack();

    char expressao[] = "(5*(((9+8)*(4*6))+7))";
    PrintDoubleStack(numeros);
    PrintCharStack(operacoes);

    double ans = AvaliaExpressao(expressao, numeros, operacoes);
    printf("\n%s = %.2lf\n\n", expressao, ans);

    DestroyDoubleStack(numeros); DestroyCharStack(operacoes);
    return 0;
}

double AvaliaExpressao(char *expressao, DoubleStack *numeros, CharStack *operacoes) {
    if (!expressao || !numeros || !operacoes) return 0;

    char c = '\0';
    for(int i = 0; i < strlen(expressao); i++) {
        c = expressao[i];

        if (c == '+' || c == '-' || c == '*' || c == '/') {
            PushCharStack(operacoes, c);

        } else if (c >= '0' && c <= '9') {
            double num = c - '0';
            PushDoubleStack(numeros, num);

        } else if (c == ')') {
            char op = PopCharStack(operacoes);
            double val1 = PopDoubleStack(numeros), val2 = PopDoubleStack(numeros), ans = 0;
            if      (op == '+') ans = val1 + val2;
            else if (op == '-') ans = val1 - val2; 
            else if (op == '*') ans = val1 * val2; 
            else if (op == '/') ans = val1 / val2; 
            PushDoubleStack(numeros, ans);
        }
    }
    
    return PopDoubleStack(numeros);
}