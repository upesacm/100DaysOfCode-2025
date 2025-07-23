// 2. Min Stack
// A problem that introduces auxiliary data structure design and teaches how to maintain additional information while preserving constant-time operations for specialized stack requirements.

// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time O(1). This operation requires understanding auxiliary storage techniques and invariant maintenance where you need to track additional metadata without compromising basic stack operations. The challenge is crucial in system design and data structure optimization where you need efficient minimum queries alongside standard stack functionality. This concept teaches space-time tradeoffs and auxiliary structure design that are essential for building efficient specialized data structures.

// This introduces auxiliary data structure design and constant-time optimization techniques that are crucial for specialized container implementations and system performance optimization.

// Your task: Design a stack with auxiliary storage to maintain minimum element information while ensuring all operations remain O(1) complexity.

// Examples
// Input:

// Push: 5, 3, 7 → Get Min
// Output:

// 3
// Input:

// Push: 8, 2, 6 → Pop → Get Min
// Output:

// 2
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
void push(struct MinStack *s, int x) {
if (s->top >= MAX - 1) {
printf("Stack Overflow\n");
return;
}
s->mainStack[++s->top] = x;
if (s->top == 0) {
s->minStack[s->top] = x;
} else {
s->minStack[s->top] = x < s->minStack[s->top - 1] ? x : s->minStack[s->top - 1];
}
}
void pop(struct MinStack *s) {
if (s->top == -1) {
printf("Stack Underflow\n");
return;
}
s->top--;
}
int top(struct MinStack *s) {
if (s->top == -1) {
printf("Stack is empty\n");
return -1;
}
return s->mainStack[s->top];
}
int getMin(struct MinStack *s) {
if (s->top == -1) {
printf("Stack is empty\n");
return INT_MAX;
}
return s->minStack[s->top];
}