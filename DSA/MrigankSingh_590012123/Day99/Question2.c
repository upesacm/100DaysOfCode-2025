#include <stdio.h>
#include <stdlib.h>

// Stack structure
typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    stack->data = (int*)malloc(capacity * sizeof(int));
    if (stack->data == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push(Stack* stack, int value) {
    if (stack->top < stack->capacity - 1) {
        stack->data[++stack->top] = value;
    }
}

int pop(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    return -1; // Stack empty
}

int peek(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top];
    }
    return -1; // Stack empty
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void freeStack(Stack* stack) {
    free(stack->data);
    free(stack);
}

void maxSlidingWindow(int* arr, int n, int k, int* result) {
    Stack* stack = createStack(n);
    int resultIndex = 0;

    // Process first k elements
    for (int i = 0; i < k; i++) {
        // Remove smaller elements from stack
        while (!isEmpty(stack) && arr[peek(stack)] < arr[i]) {
            pop(stack);
        }
        push(stack, i);
    }
    result[resultIndex++] = arr[peek(stack)];

    // Process rest of the elements
    for (int i = k; i < n; i++) {
        // Remove elements outside current window
        while (!isEmpty(stack) && peek(stack) <= i - k) {
            pop(stack);
        }
        // Remove smaller elements
        while (!isEmpty(stack) && arr[peek(stack)] < arr[i]) {
            pop(stack);
        }
        push(stack, i);
        result[resultIndex++] = arr[peek(stack)];
    }

    freeStack(stack);
}

int main() {
    int n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the window size (k): ");
    scanf("%d", &k);

    if (n < 1 || k < 1 || k > n) {
        printf("Invalid input: Ensure n > 0 and 1 <= k <= n.\n");
        return 1;
    }

    // Dynamically allocate input array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    // Dynamically allocate result array
    int *result = (int *)malloc((n - k + 1) * sizeof(int));
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        free(arr);
        return 1;
    }

    maxSlidingWindow(arr, n, k, result);

    printf("[");
    for (int i = 0; i < n - k + 1; i++) {
        printf("%d", result[i]);
        if (i < n - k) printf(", ");
    }
    printf("]\n");

    free(arr);
    free(result);
    return 0;
}
