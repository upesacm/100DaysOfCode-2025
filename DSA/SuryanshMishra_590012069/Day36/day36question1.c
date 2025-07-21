// 1. Reverse a String using Stack
// A problem that introduces fundamental stack operations and demonstrates the Last-In-First-Out (LIFO) principle through string manipulation techniques.

// You are given a string and need to use a stack data structure to reverse the characters and return the reversed result. This operation showcases the core LIFO behavior of stacks where elements are removed in the opposite order of their insertion. The challenge is fundamental in data structure education and teaches how stacks can be used for order reversal operations in various applications like undo functionality and expression evaluation. Understanding this concept is crucial for implementing backtracking algorithms and parsing operations.

// This teaches stack fundamentals and LIFO principles that are essential for algorithm design and efficient order manipulation operations.

// Your task: Utilize a stack's LIFO property to reverse string characters by pushing all characters and then popping them sequentially.

// Examples
// Input:

// "hello"
// Output:

// "olleh"
// Input:

// "abcde"
// Output:

// "edcba"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
struct Stack {
    int top;
    char items[MAX];
};
void initStack(struct Stack* stack) {
    stack->top = -1;
}
void push(struct Stack* stack, char ch) {
    if (stack->top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = ch;
}
char pop(struct Stack* stack) {
    if (stack->top < 0) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}
void reverseString(char* str) {
    struct Stack stack;
    initStack(&stack);
    for (int i = 0; str[i] != '\0'; i++) {
        push(&stack, str[i]);
    }
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = pop(&stack);
    }
}