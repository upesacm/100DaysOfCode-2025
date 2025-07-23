
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void push(Stack *s, int val) {
    s->arr[++s->top] = val;
}

int pop(Stack *s) {
    return s->arr[s->top--];
}

int peek(Stack *s) {
    return s->arr[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void sortStack(Stack *input) {
    Stack temp;
    temp.top = -1;

    while (!isEmpty(input)) {
        int tempVal = pop(input);
        while (!isEmpty(&temp) && peek(&temp) > tempVal) {
            push(input, pop(&temp));
        }
        push(&temp, tempVal);
    }

    while (!isEmpty(&temp)) {
        push(input, pop(&temp));
    }
}

void printStack(Stack *s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    s.top = -1;

    push(&s, 3);
    push(&s, 1);
    push(&s, 4);
    push(&s, 2);

    sortStack(&s);
    printStack(&s);  

    return 0;
}
