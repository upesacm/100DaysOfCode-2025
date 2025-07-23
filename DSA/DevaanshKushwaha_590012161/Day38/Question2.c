#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MAX

// Structure to represent a stack node
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// Structure to represent a stack
typedef struct {
    StackNode* top;
} Stack;

// Function to create a new stack node
StackNode* newStackNode(int data) {
    StackNode* stackNode = (StackNode*)malloc(sizeof(StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    StackNode* stackNode = newStackNode(data);
    stackNode->next = stack->top;
    stack->top = stackNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack))
        return INT_MAX; // Or handle error appropriately
    StackNode* temp = stack->top;
    int popped = temp->data;
    stack->top = temp->next;
    free(temp);
    return popped;
}

// Function to get the top element of the stack
int peek(Stack* stack) {
    if (isEmpty(stack))
        return INT_MAX; // Or handle error appropriately
    return stack->top->data;
}

// Structure for Min Stack
typedef struct {
    Stack* mainStack;
    Stack* minStack;
} MinStack;

// Function to create a new MinStack
MinStack* createMinStack() {
    MinStack* minStack = (MinStack*)malloc(sizeof(MinStack));
    minStack->mainStack = (Stack*)malloc(sizeof(Stack));
    minStack->minStack = (Stack*)malloc(sizeof(Stack));
    minStack->mainStack->top = NULL;
    minStack->minStack->top = NULL;
    return minStack;
}

// Function to push an element onto the MinStack
void minStackPush(MinStack* minStack, int val) {
    push(minStack->mainStack, val);
    if (isEmpty(minStack->minStack) || val <= peek(minStack->minStack)) {
        push(minStack->minStack, val);
    }
}

// Function to pop an element from the MinStack
void minStackPop(MinStack* minStack) {
    int popped = pop(minStack->mainStack);
    if (popped == peek(minStack->minStack)) {
        pop(minStack->minStack);
    }
}

// Function to get the top element of the MinStack
int minStackTop(MinStack* minStack) {
    return peek(minStack->mainStack);
}

// Function to get the minimum element from the MinStack
int minStackGetMin(MinStack* minStack) {
    return peek(minStack->minStack);
}

// Function to free the MinStack memory
void freeMinStack(MinStack* minStack) {
    while (!isEmpty(minStack->mainStack)) {
        pop(minStack->mainStack);
    }
    while (!isEmpty(minStack->minStack)) {
        pop(minStack->minStack);
    }
    free(minStack->mainStack);
    free(minStack->minStack);
    free(minStack);
}

int main() {
    MinStack* ms = createMinStack();

    // Example 1
    printf("Example 1:\n");
    minStackPush(ms, 5);
    minStackPush(ms, 3);
    minStackPush(ms, 7);
    printf("Min: %d\n", minStackGetMin(ms)); // Output: 3
    printf("---\n");

    // Example 2
    printf("Example 2:\n");
    freeMinStack(ms); // Reset for the next example
    ms = createMinStack(); // Recreate a fresh MinStack
    minStackPush(ms, 8);
    minStackPush(ms, 2);
    minStackPush(ms, 6);
    minStackPop(ms);
    printf("Min: %d\n", minStackGetMin(ms)); // Output: 2
    printf("---\n");

    freeMinStack(ms);

    return 0;
}
