#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int top;
    int capacity;
} Stack;

Stack* createStack3(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push3(Stack* stack, int x) {
    stack->arr[++stack->top] = x;
}

int pop3(Stack* stack) {
    return stack->arr[stack->top--];
}

int isEmpty3(Stack* stack) {
    return stack->top == -1;
}

void insertAtBottom(Stack* stack, int x) {
    if (isEmpty3(stack)) {
        push3(stack, x);
        return;
    }
    int temp = pop3(stack);
    insertAtBottom(stack, x);
    push3(stack, temp);
}

void printStack(Stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack* stack = createStack3(10);
    push3(stack, 1);
    push3(stack, 2);
    push3(stack, 3);
    
    insertAtBottom(stack, 0);
    printStack(stack); 
    return 0;
}
