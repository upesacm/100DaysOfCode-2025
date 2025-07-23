// 3. Redundant Brackets
// A problem that teaches expression analysis techniques and demonstrates stack-based parsing for identifying unnecessary parentheses in mathematical expressions through systematic bracket evaluation.

// Given a valid mathematical expression in the form of a string, find whether it contains any redundant brackets using a stack-based approach. This operation is fundamental in expression optimization and compiler design where you need to identify unnecessary parentheses that don't affect operator precedence or evaluation order. The technique involves systematic bracket tracking and operator counting to determine if brackets enclose meaningful sub-expressions. This concept is essential in code optimization, expression simplification, and parser development where removing redundant elements improves performance and readability.

// This teaches expression parsing algorithms and bracket redundancy detection techniques that are essential for compiler optimization and mathematical expression analysis systems.

// Your task: Use stack-based parsing to identify redundant bracket pairs by tracking operators and operands within parentheses for optimization detection.

// Examples
// Input:

// "((a+b))"
// Output:

// Yes
// Input:

// "(a+b)"
// Output:

// No
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char ch) {
if (top >= MAX - 1) return;
stack[++top] = ch;
}
char pop() {
if (top == -1) return '\0';
return stack[top--];
}
char peek() {
if (top == -1) return '\0';
return stack[top];
}
int isOperator(char ch) {
return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
int hasRedundantBrackets(const char *expr) {
top = -1;
for (int i = 0; expr[i] != '\0'; i++) {
char ch = expr[i];
if (ch == '(' || isOperator(ch)) {
push(ch);
} else if (ch == ')') {
int operatorFound = 0;
while (top != -1 && peek() != '(') {
char popped = pop();
if (isOperator(popped)) {
operatorFound = 1;
}
}
if (top == -1) return 1; // Unbalanced
pop(); // Remove opening '('
if (!operatorFound) {
return 1; // Redundant bracket found
}
}
}
return 0; // No redundancy
}