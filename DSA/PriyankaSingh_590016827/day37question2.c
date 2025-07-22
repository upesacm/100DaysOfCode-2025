
#include <stdio.h>
#include <ctype.h>

#define MAX 100

int main() {
    char exp[MAX];
    int stack[MAX];
    int top = -1;

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            stack[++top] = exp[i] - '0';
        } else {
            int b = stack[top--];
            int a = stack[top--];
            switch (exp[i]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
            }
        }
    }

    printf("Result: %d\n", stack[top]);
    return 0;
}
