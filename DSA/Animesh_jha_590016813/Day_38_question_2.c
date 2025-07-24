#include <stdio.h>
#include <limits.h>

#define MAX 100

struct MinStack {
    int mainStack[MAX];
    int minStack[MAX];
    int top;
};

void init(struct MinStack *s) {
    s->top = -1;
}

int isEmpty(struct MinStack *s) {
    return s->top == -1;
}

void push(struct MinStack *s, int value) {
    if (s->top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    s->top++;
    s->mainStack[s->top] = value;

    if (s->top == 0)
        s->minStack[s->top] = value;
    else
        s->minStack[s->top] = (value < s->minStack[s->top - 1]) ? value : s->minStack[s->top - 1];
}

void pop(struct MinStack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return;
    }
    s->top--;
}

int top(struct MinStack *s) {
    if (isEmpty(s)) return INT_MIN;
    return s->mainStack[s->top];
}

int getMin(struct MinStack *s) {
    if (isEmpty(s)) return INT_MIN;
    return s->minStack[s->top];
}

int main() {
    struct MinStack s;
    init(&s);

    push(&s, 5);
    push(&s, 3);
    push(&s, 7);

    printf("Minimum: %d\n", getMin(&s)); 

    return 0;
}
