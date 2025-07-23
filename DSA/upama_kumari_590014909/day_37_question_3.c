#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int size;
    int *arr;
};

void init(struct Stack* s, int size) {
    s->top = -1;
    s->size = size;
    s->arr = (int*)malloc(sizeof(int) * size);
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

int isFull(struct Stack* s) {
    return s->top == s->size - 1;
}

void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int peek(struct Stack* s) {
    if (isEmpty(s)) return -1;
    return s->arr[s->top];
}

void deleteMiddle(struct Stack* s, int curr, int mid) {
    if (isEmpty(s)) return;

    int x = pop(s);

    if (curr != mid) {
        deleteMiddle(s, curr + 1, mid);
        push(s, x);
    } else {
    }
}

void deleteMiddleElement(struct Stack* s) {
    int n = s->top + 1;      
    int mid = n / 2;         
    deleteMiddle(s, 0, mid);
}

void printStack(struct Stack* s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack s;
    init(&s, 10);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);

    printf("Original stack: ");
    printStack(&s);

    deleteMiddleElement(&s);

    printf("After deleting middle element: ");
    printStack(&s);

    free(s.arr);
    return 0;
}
