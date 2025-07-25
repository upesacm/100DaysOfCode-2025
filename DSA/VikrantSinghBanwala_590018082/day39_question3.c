#include<stdio.h>
#include<stdlib.h>
struct DualStack {
    int* array;
    int capacity;
    int top1;
    int top2;
};
struct DualStack* createDualStack(int capacity) {
    struct DualStack* stack = (struct DualStack*)malloc(sizeof(struct DualStack));
    stack->capacity = capacity;
    stack->array = (int*)malloc(capacity * sizeof(int));
    stack->top1 = -1;
    stack->top2 = capacity; 
    return stack;
}
int isFull(struct DualStack* stack) {
    return stack->top1 + 1 == stack->top2;
}
int isEmpty1(struct DualStack* stack) {
    return stack->top1 == -1;
}
int isEmpty2(struct DualStack* stack) {
    return stack->top2 == stack->capacity;
}
void push1(struct DualStack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack 1 Overflow\n");
        return;
    }
    stack->array[++stack->top1] = item;
}
void push2(struct DualStack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack 2 Overflow\n");
        return;
    }
    stack->array[--stack->top2] = item;
}
int pop1(struct DualStack* stack) {
    if (isEmpty1(stack)) {
        printf("Stack 1 Underflow\n");
        return -1;
    }
    return stack->array[stack->top1--];
}
int pop2(struct DualStack* stack) {
    if (isEmpty2(stack)) {
        printf("Stack 2 Underflow\n");
        return -1;
    }
    return stack->array[stack->top2++];
}
void printStacks(struct DualStack* stack) {
    printf("Stack 1: [");
    for (int i = 0; i <= stack->top1; i++) {
        printf("%d", stack->array[i]);
        if (i < stack->top1) printf(", ");
    }
    printf("]\n");
    printf("Stack 2: [");
    for (int i = stack->capacity - 1; i >= stack->top2; i--) {
        printf("%d", stack->array[i]);
        if (i > stack->top2) printf(", ");
    }
    printf("]\n");
}
int main() {
    struct DualStack* stack = createDualStack(10);
    push1(stack, 1);
    push1(stack, 2);
    push2(stack, 9);
    push2(stack, 8);
    printStacks(stack);
    push1(stack, 3);
    pop2(stack);
    printStacks(stack);   
    free(stack->array);
    free(stack);
    return 0;
}