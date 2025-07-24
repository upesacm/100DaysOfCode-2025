// 1. Next Greater Element
// A problem that demonstrates monotonic stack techniques and teaches efficient nearest greater element finding algorithms for array processing and optimization problems.

// For each element in the array, find the next greater element to the right using a stack-based approach. If there is no greater element, assign -1. This operation is fundamental in algorithmic optimization and array processing where you need to identify nearest greater values efficiently. The technique uses a monotonic stack to maintain elements in decreasing order, enabling O(n) time complexity instead of the naive O(n²) approach. This concept is essential in stock span problems, histogram analysis, and competitive programming where efficient nearest element queries are crucial for performance optimization.

// This teaches monotonic stack algorithms and nearest greater element techniques that are essential for array optimization and efficient element comparison operations.

// Your task: Implement a monotonic stack solution to find the next greater element for each array position in linear time complexity.

// Examples
// Input:

// [4, 5, 2, 25]
// Output:

// [5, 25, 25, -1]
// Input:

// [13, 7, 6, 12]
// Output:

// [-1, 12, 12, -1]
#include <stdio.h>
#define MAX 100
struct Stack {
int data[MAX];
int top;
};
void initStack(struct Stack *s) {
s->top = -1;
}
int isEmpty(struct Stack *s) {
return s->top == -1;
}
void push(struct Stack *s, int value) {
s->data[++s->top] = value;
}
int pop(struct Stack *s) {
return s->data[s->top--];
}
int peek(struct Stack *s) {
return s->data[s->top];
}
void nextGreaterElements(int arr[], int n, int result[]) {
struct Stack stack;
initStack(&stack);
for (int i = n - 1; i >= 0; i--) {
while (!isEmpty(&stack) && peek(&stack) <= arr[i]) {
pop(&stack);
}
result[i] = isEmpty(&stack) ? -1 : peek(&stack);
push(&stack, arr[i]);
}
}
void printArray(int arr[], int n) {
for (int i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}