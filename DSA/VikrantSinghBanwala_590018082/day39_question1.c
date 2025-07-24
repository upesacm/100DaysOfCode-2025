#include<stdio.h>
#include<stdlib.h>
struct Stack {
    int top;
    int capacity;
    int* array;
};
struct Stack* createStack(int capacity) {
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
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}
int pop(struct Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top--];
}
int peek(struct Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top];
}
void insertAtBottom(struct Stack* stack, int item) {
    if (isEmpty(stack)) {
        push(stack, item);
    } else {
        int temp = pop(stack);
        insertAtBottom(stack, item);
        push(stack, temp);
    }
}
void reverseStack(struct Stack* stack) {
    if (!isEmpty(stack)) {
        int temp = pop(stack);
        reverseStack(stack);
        insertAtBottom(stack, temp);
    }
}
void printStack(struct Stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}
int main() {
    struct Stack* stack = createStack(3);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printf("Original Stack:\n");
    printStack(stack);
    reverseStack(stack);
    printf("Reversed Stack:\n");
    printStack(stack);   
    return 0;
}