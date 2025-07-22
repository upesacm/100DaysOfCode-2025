#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

int is_match(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int main() {
    char expr[MAX];
    printf("Enter an expression: ");
    scanf("%s", expr);

    int len = strlen(expr);
    for (int i = 0; i < len; i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
            stack[++top] = expr[i];
        else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
            if (top == -1 || !is_match(stack[top--], expr[i])) {
                printf("Not Balanced\n");
                return 0;
            }
        }
    }
    if (top == -1)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
