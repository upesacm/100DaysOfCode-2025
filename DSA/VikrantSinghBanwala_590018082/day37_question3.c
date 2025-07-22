#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}
int isEmpty(Stack* stack) {
    return stack->top == -1;
}
void push(Stack* stack, int value) {
    if (stack->top < MAX - 1) {
        stack->arr[++stack->top] = value;
    }
}
int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return -1;
}
int peek(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top];
    }
    return -1;
}
int getSize(Stack* stack) {
    return stack->top + 1;
}
void deleteMiddle(Stack* stack, int currentIndex, int size) {
    if (isEmpty(stack) || currentIndex >= size) {
        return;
    }
    int value = pop(stack);
    if (currentIndex == size / 2) {
        return;
    }   
    deleteMiddle(stack, currentIndex + 1, size);
    push(stack, value);
}
void removeMiddle(Stack* stack) {
    int size = getSize(stack);
    deleteMiddle(stack, 0, size);
}
void printStack(Stack* stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}
int main() {
    Stack* stack = createStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    printf("Original stack:\n");
    printStack(stack);
    removeMiddle(stack);
    printf("Stack after removing middle element:\n");
    printStack(stack);
    Stack* stack2 = createStack();
    push(stack2, 10);
    push(stack2, 20);
    push(stack2, 30);
    printf("Original stack:\n");
    printStack(stack2);
    removeMiddle(stack2);
    printf("Stack after removing middle element:\n");
    printStack(stack2);
    free(stack);
    free(stack2);
    return 0;
}