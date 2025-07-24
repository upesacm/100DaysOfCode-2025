#include<stdio.h>
#include<stdlib.h>
struct Stack {
    int top;
    int* array;
};
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}
int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}
int peek(struct Stack* stack) {
    return stack->array[stack->top];
}
void calculateStockSpan(int prices[], int n, int span[]) {
    struct Stack* stack = createStack(n);   
    for (int i = 0; i < n; i++) {
        while (!isEmpty(stack) && prices[peek(stack)] <= prices[i]) {
            pop(stack);
        }
        span[i] = isEmpty(stack) ? i + 1 : i - peek(stack);
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
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(prices[0]);
    int* span = (int*)malloc(n * sizeof(int));
    calculateStockSpan(prices, n, span);
    printf("Stock Spans:\n");
    printArray(span, n);    
    free(span);
    return 0;
}
