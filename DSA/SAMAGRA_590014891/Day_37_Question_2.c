#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE], top = -1;

void push(int val) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = val;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return 0;
    }
    return stack[top--];
}

int evaluatePostfix(char* expr) {
    int i = 0, a, b;
    while (expr[i] != '\0') {
        if (isdigit(expr[i])) {
            push(expr[i] - '0');
        } else {
            b = pop();
            a = pop();
            switch (expr[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
        i++;
    }
    return pop();
}

int main() {
    char expr1[] = "231*+9-";
    printf("Postfix: %s\nResult: %d\n", expr1, evaluatePostfix(expr1)); 

    char expr2[] = "52+";
    printf("Postfix: %s\nResult: %d\n", expr2, evaluatePostfix(expr2));

    return 0;
}
