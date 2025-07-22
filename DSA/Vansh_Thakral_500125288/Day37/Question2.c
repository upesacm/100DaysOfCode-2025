#include <stdio.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void push(Stack *s, int val) {
    s->data[++s->top] = val;
}

int pop(Stack *s) {
    return s->data[s->top--];
}

int evaluatePostfix(char *exp) {
    Stack s;
    s.top = -1;

    for (int i = 0; exp[i]; i++) {
        char ch = exp[i];

        if (isdigit(ch)) {
            push(&s, ch - '0');
        } else {
            int b = pop(&s);
            int a = pop(&s);
            switch (ch) {
                case '+': push(&s, a + b); break;
                case '-': push(&s, a - b); break;
                case '*': push(&s, a * b); break;
                case '/': push(&s, a / b); break;
            }
        }
    }

    return pop(&s);
}

int main() {
    char expr1[] = "231*+9-";
    char expr2[] = "52+";

    printf("Result: %d\n", evaluatePostfix(expr1));  
    printf("Result: %d\n", evaluatePostfix(expr2));  

    return 0;
}

