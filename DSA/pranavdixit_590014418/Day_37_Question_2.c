#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluate(char* expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            int b = pop();
            int a = pop();
            switch (ch) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }
    return pop();
}

int main() {
    char expr[] = "231*+9-";
    int result = evaluate(expr);
    printf("Result: %d\n", result);
    return 0;
}
