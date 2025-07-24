#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
typedef struct {
    int* arr;
    int top;
    int capacity;
} Stack;

// Function to create a new stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack* stack, int item) {
    stack->arr[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack))
        return -1; // Should not happen in a correctly implemented algorithm
    return stack->arr[stack->top--];
}

// Function to peek at the top element of the stack
int peek(Stack* stack) {
    if (isEmpty(stack))
        return -1; // Should not happen in a correctly implemented algorithm
    return stack->arr[stack->top];
}

void findNextGreaterElements(int arr[], int n, int result[]) {
    Stack* stack = createStack(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!isEmpty(stack) && arr[i] >= peek(stack)) {
            pop(stack);
        }

        if (isEmpty(stack)) {
            result[i] = -1;
        } else {
            result[i] = peek(stack);
        }
        push(stack, arr[i]);
    }
    free(stack->arr);
    free(stack);
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int* result = (int*)malloc(n * sizeof(int));
    findNextGreaterElements(arr, n, result);

    for (int i = 0; i < n; i++) {
        printf("%d", result[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    free(arr);
    free(result);

    return 0;
}
