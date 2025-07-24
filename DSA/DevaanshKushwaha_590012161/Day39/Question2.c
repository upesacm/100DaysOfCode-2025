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

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) return;
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

void calculateSpan(int price[], int n, int S[]) {
    struct Stack* stack = createStack(n);
    push(stack, 0);
    S[0] = 1;

    for (int i = 1; i < n; i++) {
        while (!isEmpty(stack) && price[peek(stack)] <= price[i]) {
            pop(stack);
        }

        S[i] = isEmpty(stack) ? (i + 1) : (i - peek(stack));
        
        push(stack, i);
    }
    free(stack->array);
    free(stack);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of days: ");
    scanf("%d", &n);

    int* price = (int*)malloc(n * sizeof(int));
    printf("Enter the stock prices for %d days:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }

    int* S = (int*)malloc(n * sizeof(int));

    calculateSpan(price, n, S);

    printf("Stock Spans: ");
    printArray(S, n);
    
    free(price);
    free(S);

    return 0;
}
