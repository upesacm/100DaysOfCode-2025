#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int max;
} StackItem;

typedef struct {
    StackItem *data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (StackItem*)malloc(sizeof(StackItem)*capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push(Stack* stack, int val) {
    int maxVal = (stack->top == -1) ? val : (val > stack->data[stack->top].max ? val : stack->data[stack->top].max);
    stack->data[++stack->top].val = val;
    stack->data[stack->top].max = maxVal;
}

int pop(Stack* stack) {
    if (stack->top == -1) return -1;
    return stack->data[stack->top--].val;
}

int getMax(Stack* stack) {
    if (stack->top == -1) return -1000000000;
    return stack->data[stack->top].max;
}

int max(int a, int b) { return a > b ? a : b; }

void move(Stack* in, Stack* out) {
    while (in->top != -1) {
        int val = pop(in);
        int maxVal = (out->top == -1) ? val : (val > getMax(out) ? val : getMax(out));
        out->data[++out->top].val = val;
        out->data[out->top].max = maxVal;
    }
}

void slidingWindowMax(int arr[], int n, int k) {
    Stack* in = createStack(n);
    Stack* out = createStack(n);

    for (int i = 0; i < n; i++) {
        push(in, arr[i]);
        if (i >= k-1) {
            if (out->top == -1) move(in, out);
            int windowMax = max(getMax(in), getMax(out));
            printf("%d ", windowMax);
            pop(out);
        }
    }
    printf("\n");
}

int main() {
    int arr1[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    slidingWindowMax(arr1, n1, 3);  // Output: 3 3 5 5 6 7

    int arr2[] = {4, 2, 1, 5};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    slidingWindowMax(arr2, n2, 2);  // Output: 4 2 5

    return 0;
}
