#include <stdio.h>
#include <string.h>

int isRedundant(char* expr) {
    char stack[1000];
    int top = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == ')') {
            int count = 0;
            while (stack[top] != '(') {
                char topChar = stack[top--];
                if (topChar == '+' || topChar == '-' || topChar == '*' || topChar == '/')
                    count++;
            }
            top--;  // pop the '('
            if (count == 0)
                return 1;  // Redundant
        } else {
            stack[++top] = ch;
        }
    }

    return 0;
}

int main() {
    char expr1[] = "((a+b))";
    char expr2[] = "(a+b)";
    printf("Expression 1: %s -> %s\n", expr1, isRedundant(expr1) ? "Yes" : "No");  // Yes
    printf("Expression 2: %s -> %s\n", expr2, isRedundant(expr2) ? "Yes" : "No");  // No
    return 0;
}
