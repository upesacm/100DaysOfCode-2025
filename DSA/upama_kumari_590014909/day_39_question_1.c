#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

void init(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int value) {
    if (s->top == MAX - 1) return;
    s->arr[++(s->top)] = value;
}

int pop(struct Stack* s) {
    if (isEmpty(s)) return -1;
    return s->arr[(s->top)--];
}

void insertAtBottom(struct Stack* s, int value) {
    if (isEmpty(s)) {
        push(s, value);
        return;
    }

    int temp = pop(s);
    insertAtBottom(s, value);
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
        printf("%d ", s->arr[i]);
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

    return 0;
}
