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
void sortStack(Stack* input) {
    Stack* tempStack = createStack();
    while (!isEmpty(input)) {
        int temp = pop(input);
        while (!isEmpty(tempStack) && peek(tempStack) > temp) {
            push(input, pop(tempStack));
        }
        push(tempStack, temp);
    }
    while (!isEmpty(tempStack)) {
        push(input, pop(tempStack));
    }
    free(tempStack);
}
void printStack(Stack* stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}
int main() {
    Stack* stack = createStack();
    push(stack, 3);
    push(stack, 1);
    push(stack, 4);
    push(stack, 2);
    printf("Original stack:\n");
    printStack(stack);
    sortStack(stack);
    printf("Sorted stack:\n");
    printStack(stack);
    free(stack);
    return 0;
}
