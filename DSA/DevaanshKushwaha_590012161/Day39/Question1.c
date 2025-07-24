#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

void insertAtBottom(struct Stack* stack, int item) {
    if (isEmpty(stack)) {
        push(stack, item);
        return;
    }

    int temp = pop(stack);
    insertAtBottom(stack, item);
    push(stack, temp);
}

void reverseStack(struct Stack* stack) {
    if (!isEmpty(stack)) {
        int temp = pop(stack);
        reverseStack(stack);
        insertAtBottom(stack, temp);
    }
}

void printStack(struct Stack* stack) {
    printf("Reversed stack: ");
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
    printf("\n");
}

int main() {
    int n, value;

    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);

    struct Stack* stack = createStack(n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(stack, value);
    }

    reverseStack(stack);

    printStack(stack);
    
    free(stack->array);
    free(stack);

    return 0;
}
