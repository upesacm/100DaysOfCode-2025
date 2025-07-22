#include <stdio.h>

int main() {
    char expr[1000];
    int stack[1000];
    int top = -1;

    printf("Enter postfix expression (e.g. 231*+9-): ");
    scanf("%s", expr);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch >= '0' && ch <= '9') {
            top++;
            stack[top] = ch - '0';
        } else {
            int b = stack[top--];
            int a = stack[top--];
            int r;
            if (ch == '+') r = a + b;
            else if (ch == '-') r = a - b;
            else if (ch == '*') r = a * b;
            else if (ch == '/') r = a / b;
            top++;
            stack[top] = r;
        }
    }

    printf("Result: %d\n", stack[top]);
    return 0;
}
