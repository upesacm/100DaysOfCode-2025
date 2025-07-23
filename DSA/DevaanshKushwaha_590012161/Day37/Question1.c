#include <stdio.h>
#include <stdlib.h>

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

int isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack* s, int item) {
    if (isFull(s)) {
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

int peek(Stack* s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->arr[s->top];
}

void sortStack(Stack* s) {
    Stack tempStack;
    initStack(&tempStack);

    while (!isEmpty(s)) {
        int current = pop(s);

        while (!isEmpty(&tempStack) && peek(&tempStack) > current) {
            push(s, pop(&tempStack));
        }
        push(&tempStack, current);
    }

    while (!isEmpty(&tempStack)) {
        push(s, pop(&tempStack));
    }
}

void printStack(Stack* s) {
    if (isEmpty(s)) {
        printf("[]\n");
        return;
    }
    printf("[");
    for (int i = 0; i <= s->top; i++) {
        printf("%d", s->arr[i]);
        if (i < s->top) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    Stack originalStack;
    initStack(&originalStack);
    int numElements, element;

    scanf("%d", &numElements);

    for (int i = 0; i < numElements; i++) {
        scanf("%d", &element);
        push(&originalStack, element);
    }

    sortStack(&originalStack);

    printStack(&originalStack);

    return 0;
}
