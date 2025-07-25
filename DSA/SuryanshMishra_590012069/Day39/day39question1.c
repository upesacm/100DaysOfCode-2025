// 1. Reverse a Stack using Recursion
// A problem that demonstrates advanced recursive techniques and teaches in-place data structure manipulation without auxiliary storage through systematic recursive operations.

// Reverse the elements of a stack without using any extra space (use recursion only). This operation challenges traditional reversal approaches by eliminating auxiliary data structures and relying purely on recursive call stack for temporary storage. The technique is fundamental in space-constrained algorithms and in-place manipulation where you need to transform data structures without additional memory allocation. Understanding this concept is crucial for memory-efficient programming and recursive problem solving where the call stack itself becomes the working storage. This approach teaches advanced recursion patterns that are essential for implementing complex transformations with minimal space overhead.

// This teaches in-place recursive algorithms and call stack utilization techniques that are essential for memory-efficient data structure manipulation and space-optimized recursive operations.

// Your task: Implement recursive stack reversal using only the implicit call stack as temporary storage while maintaining O(1) auxiliary space complexity.

// Examples
// Input:

// [1, 2, 3]
// Output:

// [3, 2, 1]
// Input:

// [5, 6]
// Output:

// [6, 5]
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int x) {
if (top >= MAX - 1) return;
stack[++top] = x;
}
int pop() {
if (top == -1) return -1;
return stack[top--];
}
void insertAtBottom(int x) {
if (top == -1) {
push(x);
return;
}
int temp = pop();
insertAtBottom(x);
push(temp);
}
void reverseStack() {
if (top == -1) return;
int temp = pop();
reverseStack();
insertAtBottom(temp);
}
void displayStack() {
for (int i = top; i >= 0; i--) {
printf("%d ", stack[i]);
}
printf("\n");
}
