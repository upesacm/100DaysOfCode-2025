// 2. Evaluate Postfix Expression
// A problem that introduces stack-based expression evaluation and teaches how to process Reverse Polish Notation using systematic operand and operator handling techniques.

// Given a postfix expression (Reverse Polish Notation), evaluate the mathematical result using a stack data structure. This operation is fundamental in compiler design and expression parsing where postfix notation eliminates the need for parentheses and operator precedence rules. The technique is essential in calculator implementations and mathematical expression evaluators where you need to process operators systematically after encountering their operands. Understanding postfix evaluation is crucial for stack-based virtual machines and expression compilation in programming language interpreters.

// This introduces postfix evaluation algorithms and expression processing techniques that are crucial for compiler development and mathematical computation systems.

// Your task: Use a stack to systematically process operands and operators in postfix notation for accurate mathematical expression evaluation.

// Examples
// Input:

// "231*+9-"
// Output:

// -4
// Input:

// "52+"
// Output:

// 7
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 1000
struct Stack {
int top;
int items[MAX];
};
void initStack(struct Stack* stack) {
stack->top = -1;
}
void push(struct Stack* stack, int value) {
if (stack->top >= MAX - 1) {
printf("Stack Overflow\n");
return;
}
stack->items[++stack->top] = value;
}
int pop(struct Stack* stack) {
if (stack->top == -1) {
printf("Stack Underflow\n");
return 0;
}
return stack->items[stack->top--];
}
int evaluatePostfix(const char* expr) {
struct Stack stack;
initStack(&stack);
for (int i = 0; expr[i] != '\0'; i++) {
char ch = expr[i];
if (isdigit(ch)) {
push(&stack, ch - '0');
} else {
int val2 = pop(&stack);
int val1 = pop(&stack);
switch (ch) {
case '+': push(&stack, val1 + val2); break;
case '-': push(&stack, val1 - val2); break;
case '*': push(&stack, val1 * val2); break;
case '/': push(&stack, val1 / val2); break;
default:
printf("Invalid operator: %c\n", ch);
return 0;
}
}
}
return pop(&stack);
}