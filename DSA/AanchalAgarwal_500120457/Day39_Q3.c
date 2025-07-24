#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top1;
    int top2;
} TwoStacks;

// Initialize both stacks
void init(TwoStacks* ts) {
    ts->top1 = -1;
    ts->top2 = MAX;
}

// Push in stack1
void push1(TwoStacks* ts, int x) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[++ts->top1] = x;
    } else {
        printf("Stack Overflow in Stack1\n");
    }
}

// Push in stack2
void push2(TwoStacks* ts, int x) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[--ts->top2] = x;
    } else {
        printf("Stack Overflow in Stack2\n");
    }
}

// Pop from stack1
int pop1(TwoStacks* ts) {
    if (ts->top1 >= 0)
        return ts->arr[ts->top1--];
    else {
        printf("Stack Underflow in Stack1\n");
        return -1;
    }
}

// Pop from stack2
int pop2(TwoStacks* ts) {
    if (ts->top2 < MAX)
        return ts->arr[ts->top2++];
    else {
        printf("Stack Underflow in Stack2\n");
        return -1;
    }
}

// Display Stack1
void display1(TwoStacks* ts) {
    printf("Stack1: ");
    for (int i = 0; i <= ts->top1; i++) {
        printf("%d ", ts->arr[i]);
    }
    printf("\n");
}

// Display Stack2
void display2(TwoStacks* ts) {
    printf("Stack2: ");
    for (int i = MAX - 1; i >= ts->top2; i--) {
        printf("%d ", ts->arr[i]);
    }
    printf("\n");
}

// Test
int main() {
    TwoStacks ts;
    init(&ts);

    // Scenario 1: Push 1, 2 in Stack1; Push 9, 8 in Stack2
    push1(&ts, 1);
    push1(&ts, 2);
    push2(&ts, 9);
    push2(&ts, 8);
    display1(&ts);  // Stack1: [1, 2]
    display2(&ts);  // Stack2: [8, 9]

    // Scenario 2: Push 3 in Stack1; Pop from Stack2
    push1(&ts, 3);
    pop2(&ts);      // Pops 8
    display1(&ts);  // Stack1: [1, 2, 3]
    display2(&ts);  // Stack2: [9]

    return 0;
}
