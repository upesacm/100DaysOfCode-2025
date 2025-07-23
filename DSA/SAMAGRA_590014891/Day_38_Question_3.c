#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isRedundant(char* expr) {
    char stack[100];
    int top = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == ')') {
            int elementsInside = 0;
            while (top != -1 && stack[top] != '(') {
                elementsInside++;
                top--;
            }
            top--;
            if (elementsInside <= 1) return true;
        } else {
            stack[++top] = expr[i];
        }
    }
    return false;
}

int main() {
    char expr1[] = "((a+b))";
    char expr2[] = "(a+b)";

    printf("%s\n", isRedundant(expr1) ? "Yes" : "No"); 
    printf("%s\n", isRedundant(expr2) ? "Yes" : "No"); 

    return 0;
}
