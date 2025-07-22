#include <stdio.h>
#include <ctype.h>
#define MAX 100

int main() {
    char expr[MAX];
    int stack[MAX], top = -1;

    scanf("%s", expr);

    for(int i = 0; expr[i]; i++) {
        if(isdigit(expr[i])) {
            stack[++top] = expr[i] - '0';
        } else {
            int b = stack[top--];
            int a = stack[top--];
            if(expr[i] == '+') stack[++top] = a + b;
            else if(expr[i] == '-') stack[++top] = a - b;
            else if(expr[i] == '*') stack[++top] = a * b;
            else if(expr[i] == '/') stack[++top] = a / b;
        }
    }

    printf("%d\n", stack[top]);
    return 0;
}
