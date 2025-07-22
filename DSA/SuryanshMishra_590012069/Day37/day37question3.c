// 3. Delete Middle Element of Stack
// A problem that teaches precision stack manipulation and demonstrates recursive techniques for accessing and modifying specific stack positions using positional algorithms.

// Given a stack, delete its middle element using only stack operations and recursion without converting to other data structures. This operation requires understanding positional calculations in stacks and implementing recursive traversal to reach specific elements while preserving the order of remaining elements. The technique is important in data structure maintenance where you need to remove specific elements from constrained access structures. This concept teaches recursive stack traversal and selective element removal techniques that are essential for advanced stack-based algorithms and data manipulation operations.

// This teaches recursive stack traversal and positional element manipulation techniques that are essential for advanced data structure operations and selective element processing.

// Your task: Implement recursive stack operations to locate and remove the middle element while maintaining the original order of all other elements.

// Examples
// Input:

// [1, 2, 3, 4, 5]
// Output:

// [1, 2, 4, 5]
// Input:

// [10, 20, 30]
// Output:

// [10, 30]
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Stack {
int arr[MAX];
int top;
};
void initStack(struct Stack* stack) {
stack->top = -1;
}
void push(struct Stack* stack, int value) {
if (stack->top == MAX - 1) {
printf("Stack Overflow\n");
return;
}
stack->arr[++stack->top] = value;
}
int pop(struct Stack* stack) {
if (stack->top == -1) {
printf("Stack Underflow\n");
return -1;
}
return stack->arr[stack->top--];
}
void printStack(struct Stack* stack) {
for (int i = 0; i <= stack->top; i++) {
printf("%d ", stack->arr[i]);
}
printf("\n");
}
void deleteMiddle(struct Stack* stack, int current, int middle) {
if (stack->top == -1 || current > stack->top)
return;
int temp = pop(stack);
deleteMiddle(stack, current + 1, middle);
if (current != middle) {
push(stack, temp);
}
}
void deleteMiddleElement(struct Stack* stack) {
int count = stack->top + 1;
int middle = count / 2;
deleteMiddle(stack, 0, middle);
}