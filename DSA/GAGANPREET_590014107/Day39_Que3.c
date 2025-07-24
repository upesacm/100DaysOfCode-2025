#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct TwoStacks {
    int data[MAX];
    int top1;
    int top2;
};

void init(struct TwoStacks* ts) {
    ts->top1 = -1;
    ts->top2 = MAX;
}

void push1(struct TwoStacks* ts, int val) {
    if (ts->top1 + 1 < ts->top2) {
        ts->data[++(ts->top1)] = val;
    } else {
        printf("Stack1 Overflow\n");
    }
}

void push2(struct TwoStacks* ts, int val) {
    if (ts->top2 - 1 > ts->top1) {
        ts->data[--(ts->top2)] = val;
    } else {
        printf("Stack2 Overflow\n");
    }
}

int pop1(struct TwoStacks* ts) {
    if (ts->top1 >= 0) {
        return ts->data[(ts->top1)--];
    }
    printf("Stack1 Underflow\n");
    return -1;
}

int pop2(struct TwoStacks* ts) {
    if (ts->top2 < MAX) {
        return ts->data[(ts->top2++)];
    }
    printf("Stack2 Underflow\n");
    return -1;
}

void printStack1(struct TwoStacks* ts) {
    printf("Stack1: ");
    for (int i = 0; i <= ts->top1; i++) {
        printf("%d ", ts->data[i]);
    }
    printf("\n");
}

void printStack2(struct TwoStacks* ts) {
    printf("Stack2: ");
    for (int i = MAX - 1; i >= ts->top2; i--) {
        printf("%d ", ts->data[i]);
    }
    printf("\n");
}

int main() {
    struct TwoStacks ts;
    init(&ts);

    push1(&ts, 1);
    push1(&ts, 2);
    push2(&ts, 9);
    push2(&ts, 8);

    printStack1(&ts);  
    printStack2(&ts);  

    push1(&ts, 3);
    pop2(&ts);       

    printStack1(&ts);  
    printStack2(&ts);  

    return 0;
}
