// 1. Sort a Stack using Another Stack
// A problem that demonstrates advanced stack manipulation techniques and teaches efficient sorting algorithms using only stack-based operations without auxiliary data structures.

// Given a stack of integers, sort it in ascending order using only another stack as auxiliary storage (no arrays, lists, or other data structures allowed). This operation challenges traditional sorting approaches and requires understanding stack-based sorting algorithms that work within the constraints of LIFO operations. The technique is crucial in memory-constrained environments where you need to sort data efficiently using minimal additional space. This approach teaches how to leverage temporary stack storage for organizing data while maintaining the fundamental properties of stack operations throughout the sorting process.

// This teaches constrained sorting algorithms and stack-based data organization techniques that are essential for memory-efficient sorting and space-optimized algorithmic solutions.

// Your task: Implement a sorting algorithm using only stack operations and one additional stack as temporary storage for efficient data organization.

// Examples
// Input:

// [3, 1, 4, 2]
// Output:

// [1, 2, 3, 4]
// Input:

// [6, 5, 8]
// Output:

// [5, 6, 8]
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
struct Stack {
int top;
int items[MAX];
};
void initStack(struct Stack* stack) {
stack->top = -1;
}
int isEmpty(struct Stack* stack) {
return stack->top == -1;
}
int isFull(struct Stack* stack) {
return stack->top == MAX - 1;
}
void push(struct Stack* stack, int value) {
if (isFull(stack)) {
printf("Stack Overflow\n");
return;
}
stack->items[++stack->top] = value;
}
int pop(struct Stack* stack) {
if (isEmpty(stack)) {
printf("Stack Underflow\n");
return -1;
}
return stack->items[stack->top--];
}
int peek(struct Stack* stack) {
if (isEmpty(stack)) return -1;
return stack->items[stack->top];
}
void sortStack(struct Stack* input) {
struct Stack tempStack;
initStack(&tempStack);
while (!isEmpty(input)) {
int tmp = pop(input);
while (!isEmpty(&tempStack) && peek(&tempStack) > tmp) {
push(input, pop(&tempStack));
}
push(&tempStack, tmp);
}
while (!isEmpty(&tempStack)) {
push(input, pop(&tempStack));
}
}
void printStack(struct Stack* stack) {
printf("[");
for (int i = 0; i <= stack->top; i++) {
printf("%d", stack->items[i]);
if (i != stack->top) printf(", ");
}
printf("]\n");
}