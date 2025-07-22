#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int item) {
    if (s->top == MAX_SIZE - 1) {
        return;
    }
    s->arr[++s->top] = item;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->arr[s->top--];
}

int evaluatePostfix(char* expression) {
    Stack s;
    initStack(&s);
    int i;

    for (i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&s, expression[i] - '0');
        } else {
            int val2 = pop(&s);
            int val1 = pop(&s);
            switch (expression[i]) {
                case '+':
                    push(&s, val1 + val2);
                    break;
                case '-':
                    push(&s, val1 - val2);
                    break;
                case '*':
                    push(&s, val1 * val2);
                    break;
                case '/':
                    push(&s, val1 / val2);
                    break;
            }
        }
    }
    return pop(&s);
}

int main() {
    char expression[MAX_SIZE];
    scanf("%s", expression);
    printf("%d\n", evaluatePostfix(expression));
    return 0;
}
