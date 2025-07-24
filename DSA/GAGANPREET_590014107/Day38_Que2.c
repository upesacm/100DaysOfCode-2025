#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int data[MAX];
    int top;
};

void init(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int val) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = val;
    }
}

int pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return -1;
}

int top(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return -1;
}

struct MinStack {
    struct Stack main;
    struct Stack min;
};

void initMinStack(struct MinStack* ms) {
    init(&ms->main);
    init(&ms->min);
}

void minPush(struct MinStack* ms, int val) {
    push(&ms->main, val);
    if (isEmpty(&ms->min) || val <= top(&ms->min)) {
        push(&ms->min, val);
    }
}

void minPop(struct MinStack* ms) {
    int popped = pop(&ms->main);
    if (popped == top(&ms->min)) {
        pop(&ms->min);
    }
}

int minTop(struct MinStack* ms) {
    return top(&ms->main);
}

int getMin(struct MinStack* ms) {
    return top(&ms->min);
}

int main() {
    struct MinStack ms;
    initMinStack(&ms);

    minPush(&ms, 5);
    minPush(&ms, 3);
    minPush(&ms, 7);
    printf("Min after pushing 5, 3, 7: %d\n", getMin(&ms));  

    initMinStack(&ms);
    minPush(&ms, 8);
    minPush(&ms, 2);
    minPush(&ms, 6);
    minPop(&ms);  
    printf("Min after pushing 8, 2, 6 and popping: %d\n", getMin(&ms));  

    return 0;
}
