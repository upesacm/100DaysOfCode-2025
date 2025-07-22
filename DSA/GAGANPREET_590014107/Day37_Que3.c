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

void deleteMiddle(struct Stack* s, int current, int size) {
    if (isEmpty(s)) return;

    int temp = pop(s);

    if (current == size / 2) {
        return;
    }

    deleteMiddle(s, current + 1, size);
    push(s, temp);
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
    push(&s, 4);
    push(&s, 5);

    printf("Original stack: ");
    printStack(&s);

    deleteMiddle(&s, 0, s.top + 1);

    printf("After deleting middle: ");
    printStack(&s);

    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("\nOriginal stack: ");
    printStack(&s);

    deleteMiddle(&s, 0, s.top + 1);

    printf("After deleting middle: ");
    printStack(&s);

    return 0;
}
