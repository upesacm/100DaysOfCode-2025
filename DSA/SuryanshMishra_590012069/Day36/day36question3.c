// 3. Insert at Bottom of Stack
// A problem that teaches advanced stack manipulation techniques and demonstrates recursive operations combined with stack-based data structure modification.

// Given a stack and an element x, insert x at the bottom of the stack using recursion or additional stack operations without using auxiliary data structures like arrays. This operation challenges the natural LIFO behavior of stacks and requires creative manipulation to access the bottom position. The technique is important in stack-based algorithms where you need to modify stack foundations while preserving the existing order. This concept is essential for implementing advanced stack operations and understanding recursive stack manipulation in complex algorithmic scenarios.

// This teaches recursive stack operations and advanced stack manipulation techniques that are essential for complex data structure modifications and algorithmic problem solving.

// Your task: Insert an element at the stack's bottom position using recursive operations while maintaining the original order of existing elements.

// Examples
// Input:

// Stack: [1, 2, 3], x = 0
// Output:

// [0, 1, 2, 3]
// Input:

// Stack: [5, 6], x = 9
// Output:

// // [9, 5, 6]
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
struct Stack {
    int top;
    int items[MAX];
};
void initStack(struct Stack* stack) {
    stack->top = -1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, int value) {
    if (stack->top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->items[stack->top];
}
void insertAtBottom(struct Stack* stack, int x) {
    if (isEmpty(stack)) {
        push(stack, x);
        return;
    }
    int temp = pop(stack);
    insertAtBottom(stack, x);
    push(stack, temp);
}
void printStack(struct Stack* stack) {
    printf("[");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d", stack->items[i]);
        if (i != stack->top) printf(", ");
    }
    printf("]\n");
}