#include <stdio.h>
#include <ctype.h>

#define MAX 100

typedef struct Stack {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int val) {
    s->data[++(s->top)] = val;
}

int pop(Stack *s) {
    return s->data[(s->top)--];
}

int evaluatePostfix(char* expr) {
    Stack s;
    init(&s);
    int i = 0;

    while (expr[i]) {
        if (isdigit(expr[i])) {
            push(&s, expr[i] - '0');
        } else {
            int b = pop(&s);
            int a = pop(&s);
            switch (expr[i]) {
                case '+': push(&s, a + b); break;
                case '-': push(&s, a - b); break;
                case '*': push(&s, a * b); break;
                case '/': push(&s, a / b); break;
            }
        }
        i++;
    }

    return pop(&s);
}

int main() {
    char expr[MAX];
    scanf("%s", expr);
    int result = evaluatePostfix(expr);
    printf("%d\n", result);
    return 0;
}
