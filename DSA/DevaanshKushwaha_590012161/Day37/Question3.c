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

int getSize(Stack* s) {
    return s->top + 1;
}

void deleteMiddle(Stack* s, int currentSize, int originalSize) {
    if (currentSize == originalSize / 2 + 1) {
        pop(s);
        return;
    }

    int temp = pop(s);
    deleteMiddle(s, currentSize - 1, originalSize);
    push(s, temp);
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
    Stack s;
    initStack(&s);
    int numElements, element;

    scanf("%d", &numElements);

    for (int i = 0; i < numElements; i++) {
        scanf("%d", &element);
        push(&s, element);
    }

    if (!isEmpty(&s)) {
        deleteMiddle(&s, getSize(&s), getSize(&s));
    }

    printStack(&s);

    return 0;
}
