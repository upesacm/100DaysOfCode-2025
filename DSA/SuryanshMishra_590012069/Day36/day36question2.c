// 2. Check for Balanced Parentheses
// A problem that demonstrates stack-based parsing techniques and teaches how to validate nested structures using systematic bracket matching algorithms.

// Given a string containing parentheses (), {}, and [], check whether the input string has balanced parentheses using a stack data structure. This operation is fundamental in compiler design and expression parsing where you need to validate syntax correctness and ensure proper nesting of brackets. The challenge involves understanding how stacks can track opening brackets and match them with corresponding closing brackets, making it essential for syntax validation and parser implementation. This technique is widely used in code editors and mathematical expression evaluators.

// This introduces bracket matching algorithms and syntax validation techniques that are crucial for parser development and expression evaluation systems.

// Your task: Use a stack to track opening brackets and validate proper pairing with closing brackets for complete balance verification.

// Examples
// Input:

// "([])"
// Output:

// Balanced
// Input:

// "(["
// Output:

// Not Balanced
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
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, char ch) {
    if (stack->top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = ch;
}
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->items[stack->top--];
}
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}
int isBalanced(char* expr) {
    struct Stack stack;
    initStack(&stack);
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char top = pop(&stack);
            if (!isMatchingPair(top, ch)) {
                return 0;
            }
        }
    }
    return isEmpty(&stack);
}