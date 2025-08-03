#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

typedef struct {
    int mainStack[MAX];
    int maxStack[MAX];
    int top;
} MaxStack;

void init(MaxStack* s) {
    s->top = -1;
}

// Push element and update max
void push(MaxStack* s, int val) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->mainStack[++(s->top)] = val;

    if (s->top == 0)
        s->maxStack[s->top] = val;
    else
        s->maxStack[s->top] = (val > s->maxStack[s->top - 1]) ? val : s->maxStack[s->top - 1];
}

// Pop element from stack
int pop(MaxStack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    return s->mainStack[(s->top)--];
}

// Get current maximum
int getMax(MaxStack* s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return s->maxStack[s->top];
}
