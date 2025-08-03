#include <stdio.h>
#include <string.h>
#define MAX 100
int main() {
    char expr[MAX], stack[MAX];
    int top = -1;
    printf("Enter an expression: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0';
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                printf("Not Balanced\n");
                return 0;
            }
            char last = stack[top--];
            if ((ch == ')' && last != '(') ||
                (ch == '}' && last != '{') ||
                (ch == ']' && last != '[')) {
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
