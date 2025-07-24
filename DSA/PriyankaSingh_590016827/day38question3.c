
#include <stdio.h>
#include <string.h>

#define MAX 100

int isRedundant(char *expr) {
    char stack[MAX];
    int top = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == ')') {
            int count = 0;
            while (top != -1 && stack[top] != '(') {
                char ch = stack[top--];
                if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
                    count++;
            }
            top--; // pop '('
            if (count == 0)
                return 1;
        } else {
            stack[++top] = expr[i];
        }
    }
    return 0;
}

int main() {
    char expr[MAX];
    printf("Enter expression: ");
    scanf("%s", expr);

    if (isRedundant(expr))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
