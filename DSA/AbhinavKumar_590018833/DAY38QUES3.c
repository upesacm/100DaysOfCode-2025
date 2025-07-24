// 3. Redundant Brackets
// A problem that teaches expression analysis techniques and demonstrates stack-based parsing
// for identifying unnecessary parentheses in mathematical expressions through systematic
// bracket evaluation.
// Given a valid mathematical expression in the form of a string, find whether it contains
// any redundant brackets using a stack-based approach. This operation is fundamental
// in expression optimization and compiler design where you need to identify unnecessary
// parentheses that don't affect operator precedence or evaluation order. The technique
// involves systematic bracket tracking and operator counting to determine if brackets
// enclose meaningful sub-expressions. This concept is essential in code
// optimization, expression simplification, and parser development where removing
// redundant elements improves performance and readability.
// This teaches expression parsing algorithms and bracket redundancy detection
// techniques that are essential for compiler optimization and mathematical expression
// analysis systems.
// Your task: Use stack-based parsing to identify redundant bracket pairs by tracking operators
// and operands within parentheses for optimization detection.
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
void checkRedundantBrackets(const char *expression) {
    int len = strlen(expression);
    char *stack = (char *)malloc(len * sizeof(char));
    int top = -1;
    int operatorCount = 0;

    for (int i = 0; i < len; i++) {
        if (expression[i] == '(') {
            stack[++top] = expression[i];
            operatorCount = 0;
        }
        else if (expression[i] == ')') {
            if (top == -1 || operatorCount == 0) {
                printf("Yes\n"); 
                free(stack);    
                return;
            }
            top--;    
            if (top >= 0 && stack[top] == '(') {
                printf("Yes\n"); 
                free(stack);    
                return;
            }
            operatorCount = 0;
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i]    
            == '*' || expression[i] == '/') {
            operatorCount++;
        }
        else {
            if (top >= 0 && stack[top] == '(') {
                operatorCount++;
            }
        }
    }
    printf("No\n");    
    free(stack);
}
int main() {
    const char *expr1 = "((a+b))";
    checkRedundantBrackets(expr1);

    const char *expr2 = "(a+b)";
    checkRedundantBrackets(expr2);

    return 0;
}