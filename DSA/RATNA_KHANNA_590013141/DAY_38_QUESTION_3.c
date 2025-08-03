#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;
    }
}
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}
char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';
}
int hasRedundantBrackets(char *expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == ')') {
            int operatorFound = 0;
            char topChar = pop();
            while (topChar != '(' && top >= 0) {
                if (topChar == '+' || topChar == '-' || topChar == '*' || topChar == '/') {
                    operatorFound = 1;
                }
                topChar = pop();
            }
            if (!operatorFound) {
                return 1;  
            }
        } else {
            push(ch);  
        }
    }
    return 0;  
}
int main() {
    char expr[MAX];

    printf("Enter a mathematical expression: ");
    scanf("%s", expr);

    if (hasRedundantBrackets(expr)) {
        printf("Yes (Redundant brackets found)\n");
    } else {
        printf("No (No redundant brackets)\n");
    }

    return 0;
}
