#include <stdio.h>
#include <stdlib.h>

typedef struct IntStack {
    int top;
    unsigned capacity;
    int* array;
} IntStack;

IntStack* createIntStack(unsigned capacity) {
    IntStack* stack = (IntStack*) malloc(sizeof(IntStack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int isIntStackFull(IntStack* stack) {
    return stack->top == stack->capacity - 1;
}

int isIntStackEmpty(IntStack* stack) {
    return stack->top == -1;
}

void pushInt(IntStack* stack, int item) {
    if (isIntStackFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int popInt(IntStack* stack) {
    if (isIntStackEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

void insertAtBottom(IntStack* stack, int item) {
    if (isIntStackEmpty(stack)) {
        pushInt(stack, item);
        return;
    }

    int temp = popInt(stack);
    insertAtBottom(stack, item);

    pushInt(stack, temp);
}

void printStack(IntStack* stack) {
    if (isIntStackEmpty(stack)) {
        printf("Stack: []\n");
        return;
    }
    printf("Stack: [");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d", stack->array[i]);
        if (i < stack->top) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    IntStack* stack1 = createIntStack(10);
    pushInt(stack1, 1);
    pushInt(stack1, 2);
    pushInt(stack1, 3);
    printf("Original ");
    printStack(stack1);

    int x1 = 0;
    insertAtBottom(stack1, x1);
    printf("After inserting %d: ", x1);
    printStack(stack1);

    printf("\n");

    IntStack* stack2 = createIntStack(10);
    pushInt(stack2, 5);
    pushInt(stack2, 6);
    printf("Original ");
    printStack(stack2);

    int x2 = 9;
    insertAtBottom(stack2, x2);
    printf("After inserting %d: ", x2);
    printStack(stack2);

    free(stack1->array);
    free(stack1);
    free(stack2->array);
    free(stack2);

    return 0;
}