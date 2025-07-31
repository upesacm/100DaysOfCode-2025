// 3. Implement 2 Stacks in an Array
// A problem that teaches space-efficient data structure design and demonstrates optimal memory utilization techniques for implementing multiple stacks within shared storage constraints.

// Design a data structure that implements two stacks in one array such that neither stack overflows until the total space is used. This operation requires understanding space partitioning strategies and dynamic boundary management where you need to maximize space utilization while maintaining stack properties. The technique is crucial in embedded systems and memory-constrained environments where you need efficient multi-stack implementations without wasting allocated space. This concept teaches optimal space allocation and collision detection that are essential for building efficient container classes and system-level data structures.

// This teaches space-efficient container design and memory optimization techniques that are essential for system programming and resource-constrained data structure implementations.

// Your task: Design a dual-stack array implementation with optimal space utilization by managing dynamic boundaries and preventing premature overflow conditions.

// Examples
// Input:

// Push 1, 2 in stack1, Push 9, 8 in stack2
// Output:

// Stack1: [1, 2], Stack2: [8, 9]
// Input:

// Push 3 in stack1, Pop stack2
// Output:

// Stack1: [1, 2, 3], Stack2: [8]
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct TwoStacks {
int arr[MAX];
int top1;
int top2;
} TwoStacks;
void initTwoStacks(TwoStacks *ts) {
ts->top1 = -1;
ts->top2 = MAX;
}
void push1(TwoStacks *ts, int x) {
if (ts->top1 + 1 == ts->top2) {
printf("Stack Overflow in Stack1\n");
return;
}
ts->arr[++(ts->top1)] = x;
}
void push2(TwoStacks *ts, int x) {
if (ts->top1 + 1 == ts->top2) {
printf("Stack Overflow in Stack2\n");
return;
}
ts->arr[--(ts->top2)] = x;
}
int pop1(TwoStacks *ts) {
if (ts->top1 == -1) {
printf("Stack Underflow in Stack1\n");
return -1;
}
return ts->arr[(ts->top1)--];
}
int pop2(TwoStacks *ts) {
if (ts->top2 == MAX) {
printf("Stack Underflow in Stack2\n");
return -1;
}
return ts->arr[(ts->top2)++];
}
void printStack1(TwoStacks *ts) {
printf("Stack1: ");
for (int i = 0; i <= ts->top1; i++) {
printf("%d ", ts->arr[i]);
}
printf("\n");
}
void printStack2(TwoStacks *ts) {
printf("Stack2: ");
for (int i = MAX - 1; i >= ts->top2; i--) {
printf("%d ", ts->arr[i]);
}
printf("\n");
}