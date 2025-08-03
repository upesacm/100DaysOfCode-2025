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
int peek(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return -1;
}

void sortStack(struct Stack* input) {
    struct Stack temp;
    init(&temp);

    while (!isEmpty(input)) {
        int tmp = pop(input);

        while (!isEmpty(&temp) && peek(&temp) > tmp) {
            push(input, pop(&temp));
        }

        push(&temp, tmp);
    }

    while (!isEmpty(&temp)) {
        push(input, pop(&temp));
    }
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

    push(&s, 3);
    push(&s, 1);
    push(&s, 4);
    push(&s, 2);

    printf("Original stack: ");
    printStack(&s);

    sortStack(&s);

    printf("Sorted stack: ");
    printStack(&s);

    return 0;
}
