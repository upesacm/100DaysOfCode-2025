#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool hasRedundantBrackets(char* expr) {
    char stack[MAX];
    int top = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == ')') {
            bool operatorFound = false;

            while (top != -1 && stack[top] != '(') {
                if (isOperator(stack[top])) {
                    operatorFound = true;
                }
                top--; 
            }
            if (top != -1)
                top--;
            if (!operatorFound)
                return true;
        } else {
            stack[++top] = ch;
        }
    }

    return false;
}

int main() {
    char expr[MAX];

    printf("Enter the expression: ");
    scanf("%s", expr);

    if (hasRedundantBrackets(expr)) {
        printf("Yes\n");  
    } else {
        printf("No\n");  
    }

    return 0;
}
