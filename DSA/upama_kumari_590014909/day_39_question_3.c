#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct TwoStacks {
    int arr[MAX];
    int top1;
    int top2;
};

void init(struct TwoStacks *ts) {
    ts->top1 = -1;
    ts->top2 = MAX;
}

void push1(struct TwoStacks *ts, int x) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[++(ts->top1)] = x;
    } else {
        printf("Stack Overflow in Stack1\n");
    }
}

void push2(struct TwoStacks *ts, int x) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[--(ts->top2)] = x;
    } else {
        printf("Stack Overflow in Stack2\n");
    }
}

int pop1(struct TwoStacks *ts) {
    if (ts->top1 >= 0) {
        return ts->arr[(ts->top1)--];
    } else {
        printf("Stack Underflow in Stack1\n");
        return -1;
    }
}

int pop2(struct TwoStacks *ts) {
    if (ts->top2 < MAX) {
        return ts->arr[(ts->top2)++];
    } else {
        printf("Stack Underflow in Stack2\n");
        return -1;
    }
}

void printStacks(struct TwoStacks *ts) {
    printf("Stack1: ");
    for (int i = 0; i <= ts->top1; i++) {
        printf("%d ", ts->arr[i]);
    }

    printf("\nStack2: ");
    for (int i = MAX - 1; i >= ts->top2; i--) {
        printf("%d ", ts->arr[i]);
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

    printStacks(&ts);

    return 0;
}
