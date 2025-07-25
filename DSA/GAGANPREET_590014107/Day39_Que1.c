#include <stdio.h>
#include <stdlib.h>

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
    return -1;
}

int top(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return -1;
}

void insertAtBottom(struct Stack* s, int val) {
    if (isEmpty(s)) {
        push(s, val);
        return;
    }

    int temp = pop(s);
    insertAtBottom(s, val);
    push(s, temp);
}

void reverseStack(struct Stack* s) {
    if (isEmpty(s)) return;

    int temp = pop(s);
    reverseStack(s);
    insertAtBottom(s, temp);
}

void printStack(struct Stack* s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    struct Stack s;
    init(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printf("Original stack: ");
    printStack(&s);

    reverseStack(&s);

    printf("Reversed stack: ");
    printStack(&s);

    init(&s);
    push(&s, 5);
    push(&s, 6);

    printf("\nOriginal stack: ");
    printStack(&s);

    reverseStack(&s);

    printf("Reversed stack: ");
    printStack(&s);

    return 0;
}
