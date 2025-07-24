#include <stdio.h>
#include <ctype.h>  
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = val;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(const char* expr) {
    int i = 0;
    char ch;

    while ((ch = expr[i]) != '\0') {
        if (ch == ' ') {
            i++;
            continue;
        }

        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            int b = pop();
            int a = pop();
            int result;

            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default:
                    printf("Unsupported operator: %c\n", ch);
                    exit(1);
            }
            push(result);
        }
        i++;
    }

    return pop();  
}

int main() {
    char expr[MAX];

    printf("Enter a postfix expression ");
    scanf("%s", expr);  

    int result = evaluatePostfix(expr);
    printf("Result: %d\n", result);

    return 0;
}
