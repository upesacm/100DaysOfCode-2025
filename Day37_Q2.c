#include <stdio.h>
#include <ctype.h>

#define MAX 100

int evaluatePostfix(char* expr) {
    int stack[MAX];
    int top = -1;

    for (int i = 0; expr[i]; i++) {
        char ch = expr[i];

        if (isdigit(ch)) {
            stack[++top] = ch - '0';
        } else {
            int b = stack[top--];
            int a = stack[top--];

            switch (ch) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
            }
        }
    }

    return stack[top];
}

int main() {
    char expr1[] = "231*+9-"; // Output: -4
    char expr2[] = "52+";     // Output: 7

    printf("%d\n", evaluatePostfix(expr1));
    printf("%d\n", evaluatePostfix(expr2));

    return 0;
}
