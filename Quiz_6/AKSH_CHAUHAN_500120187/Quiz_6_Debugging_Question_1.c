#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int top;
    int minTop;
} MinStack;

void init(MinStack *s) {
    s->top = -1;
    s->minTop = -1;
}

void push(MinStack *s, int val) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->stack[++(s->top)] = val;

    if (s->minTop == -1 || val <= s->minStack[s->minTop])
        s->minStack[++(s->minTop)] = val;
}

int pop(MinStack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    int popped = s->stack[(s->top)--];

    if (popped == s->minStack[s->minTop])
        s->minTop--;

    return popped;
}

int getMin(MinStack *s) {
    if (s->minTop == -1)
        return INT_MAX;
    return s->minStack[s->minTop];
}

int main() {
    MinStack s;
    init(&s);

    push(&s, 5);
    push(&s, 2);
    push(&s, 8);

    printf("Min: %d\n", getMin(&s)); // 2
    pop(&s); // pop 8
    pop(&s); // pop 2
    printf("Min: %d\n", getMin(&s)); // 5

    return 0;
}
