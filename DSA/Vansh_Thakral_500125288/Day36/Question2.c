#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(char* expr) {
    for (int i = 0; expr[i]; i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[')
            push(c);
        else if (c == ')' || c == '}' || c == ']') {
            if (top == -1 || !isMatchingPair(pop(), c))
                return false;
        }
    }
    return top == -1;
}

int main() {
    char expr[MAX];
    printf("Enter expression: ");
    scanf("%s", expr);

    if (isBalanced(expr))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}
