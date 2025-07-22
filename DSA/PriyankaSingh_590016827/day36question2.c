
#include <stdio.h>
#include <string.h>

#define MAX 100

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char *exp) {
    char stack[MAX];
    int top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            stack[++top] = exp[i];
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1 || !isMatchingPair(stack[top--], exp[i]))
                return 0;
        }
    }
    return top == -1;
}

int main() {
    char exp[MAX];
    printf("Enter expression: ");
    scanf("%s", exp);

    if (isBalanced(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
