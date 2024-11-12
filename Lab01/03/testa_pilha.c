#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

double AvaliaExpressao(char *expressao, Stack *numero, Stack *operacoes);

int main () {
    Stack *numeros = InitStack();
    Stack *operacoes = InitStack();

    char expressao[] = "(((5*1)+5)+2)";
    double ans = AvaliaExpressao(expressao, numeros, operacoes);
    printf("\n%s = %.2lf\n\n", expressao, ans);

    DestroyStack(numeros); DestroyStack(operacoes);
    return 0;
}

double AvaliaExpressao(char *expressao, Stack *numeros, Stack *operacoes) {
    if (!expressao || !numeros || !operacoes) return 0;

    char c = '\0';
    for (int i = 0; i < strlen(expressao); i++) {
        c = expressao[i];

        if (c == '+' || c == '-' || c == '*' || c == '/') {
            char *op = malloc(sizeof(char));
            *op = c;
            PushStack(operacoes, op);

        } else if (c >= '0' && c <= '9') {
            double *num = malloc(sizeof(double));
            *num = c - '0';
            PushStack(numeros, num);

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