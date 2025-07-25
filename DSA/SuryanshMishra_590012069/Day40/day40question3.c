// 3. Design a Stack that Supports getMax()
// A problem that teaches specialized container design and demonstrates auxiliary data structure techniques for maintaining maximum element tracking with constant-time query operations.

// Implement a stack that supports push, pop, and also retrieving the maximum element in constant time O(1). This operation requires understanding auxiliary storage optimization and maximum tracking algorithms where you need to maintain metadata efficiently alongside standard stack operations. The technique involves parallel data structure management to track maximum values without compromising performance. This concept is crucial in system design, database indexing, and real-time analytics where efficient maximum queries are essential for performance monitoring and statistical analysis operations.

// This teaches auxiliary metadata management and constant-time optimization techniques that are essential for specialized container implementations and high-performance data structure design.

// Your task: Design a stack with auxiliary maximum tracking to maintain peak element information while ensuring all operations remain O(1) complexity.

// Examples
// Input:

// Push: 3, 5, 2 → getMax
// Output:

// 5
// Input:

// Pop → getMax
// Output:

// 3
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct {
int mainStack[MAX];
int maxStack[MAX];
int top;
} MaxStack;
void init(MaxStack *s) {
s->top = -1;
}
void push(MaxStack *s, int x) {
if (s->top >= MAX - 1) {
printf("Stack Overflow\n");
return;
}
s->mainStack[++(s->top)] = x;
if (s->top == 0)
s->maxStack[s->top] = x;
else
s->maxStack[s->top] = (x > s->maxStack[s->top - 1]) ? x : s->maxStack[s->top - 1];
}
void pop(MaxStack *s) {
if (s->top == -1) {
printf("Stack Underflow\n");
return;
}
s->top--;
}
int top(MaxStack *s) {
if (s->top == -1) {
printf("Stack is empty\n");
return -1;
}
return s->mainStack[s->top];
}
int getMax(MaxStack *s) {
if (s->top == -1) {
printf("Stack is empty\n");
return -1;
}
return s->maxStack[s->top];
}