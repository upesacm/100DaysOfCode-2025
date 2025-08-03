// 2. Min Stack
// A problem that introduces auxiliary data structure design and teaches how to maintain
// additional information while preserving constant-time operations for specialized stack
// requirements.
// Design a stack that supports push, pop, top, and retrieving the minimum
// element in constant time O(1). This operation requires understanding auxiliary storage
// techniques and invariant maintenance where you need to track additional
// metadata without compromising basic stack operations. The challenge is crucial in system
// design and data structure optimization where you need efficient minimum
// queries alongside standard stack functionality. This concept teaches space-time
// tradeoffs and auxiliary structure design that are essential for building efficient specialized
// data structures.
// This introduces auxiliary data structure design and constant-time optimization
// techniques that are crucial for specialized container implementations and system
// performance optimization.
// Your task: Design a stack with auxiliary storage to maintain minimum element information
// while ensuring all operations remain O(1) complexity.
// Examples
// Input:
// Push: 5, 3, 7 → Get Min
// Output:
// 3
// Input:
// Push: 8, 2, 6 → Pop → Get Min
// Output:
// 2
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *data;
    int *minData;
    int top;
    int minTop;
    int capacity;
} MinStack;
void initStack(MinStack *stack, int capacity) {
    stack->data = (int *)malloc(capacity * sizeof(int));
    stack->minData = (int *)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->minTop = -1;
    stack->capacity = capacity;
}
void push(MinStack *stack, int value) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
    if (stack->minTop == -1 || value <= stack->minData[stack->minTop]) {
        stack->minData[++stack->minTop] = value;
    }
}
void pop(MinStack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return;
    }
    if (stack->data[stack->top] == stack->minData[stack->minTop]) {
        stack->minTop--;
    }
    stack->top--;
}
int top(MinStack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];
}
int getMin(MinStack *stack) {
    if (stack->minTop == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->minData[stack->minTop];
}
int main() {
    MinStack stack;
    initStack(&stack, 100);
    
    push(&stack, 5);
    push(&stack, 3);
    push(&stack, 7);
    printf("Minimum element: %d\n", getMin(&stack));

    pop(&stack);
    printf("Top element: %d\n", top(&stack));
    printf("Minimum element: %d\n", getMin(&stack));

    push(&stack, 2);
    printf("Minimum element after pushing 2: %d\n", getMin(&stack)); 

    free(stack.data);
    free(stack.minData);
    
    return 0;
}