#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

struct Stack {
    int data[MAX];
    int top;
};

void init(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int val) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = val;
    }
}

int pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return 0;
}

int evaluatePostfix(const char* expr) {
    struct Stack s;
    init(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

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
    printf("Result: %d\n", evaluatePostfix("231*+9-"));  
    printf("Result: %d\n", evaluatePostfix("52+"));      
    return 0;
}
