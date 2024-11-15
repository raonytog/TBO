#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "stack.h"

bool isNumber(char c);
bool isOperation(char c);
double AvaliaExpressao(char *expressao, Stack *numero, Stack *operacoes);

int main (int argc, char const *argv[]) {
    clock_t start = clock();

    Stack *numeros = InitStack(), *operacoes = InitStack();

    char expressao[500];    strcpy(expressao, argv[1]);
    double ans = AvaliaExpressao(expressao, numeros, operacoes);
    printf("\n%s = %.2lf\n\n", expressao, ans);

    DestroyStack(numeros); DestroyStack(operacoes);

    clock_t end = clock();
    double sec = ( (double)end - (double)start ) / CLOCKS_PER_SEC;
    printf (" % lf\n" , sec);

    return 0;
}

bool isNumber(char c) { return c >= '0' && c <= '9'; }
bool isOperation(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }

double AvaliaExpressao(char *expressao, Stack *numeros, Stack *operacoes) {
    if (!expressao || !numeros || !operacoes) return 0;

    char c = '\0';
    for (int i = 0; i < strlen(expressao); i++) {
        c = expressao[i];

        if (c == '(') { continue;
 
        } else if (isNumber(c)) {
            double *num = malloc(sizeof(double));
            *num = c - '0';

            int j = ++i, entrou = 0;
            for(char d = expressao[j]; isNumber(d); d = expressao[++j]) {
                *num *= 10;
                *num += d - '0';
                entrou = 1;
            }

            if (entrou == 0) { --i; }
            PushStack(numeros, num);

        } else if (isOperation(c)) {
            char *op = malloc(sizeof(char));
            *op = c;
            PushStack(operacoes, op);

        } else if (c == ')') {
            char    *op = (char *)PopStack(operacoes);
            double  *val1 = (double *)PopStack(numeros),
                    *val2 = (double *)PopStack(numeros),
                    *ans = malloc(sizeof(double));

            if (*op == '+') *ans = *val2 + *val1;
            else if (*op == '-') *ans = *val2 - *val1;
            else if (*op == '*') *ans = *val2 * *val1;
            else if (*op == '/') *ans = *val2 / *val1;

            PushStack(numeros, ans);
            free(op);   free(val1);     free(val2);
        }
    }
    
    double *aux = (double*) PopStack(numeros);
    double result = *aux;
    free(aux);

    return result;
}