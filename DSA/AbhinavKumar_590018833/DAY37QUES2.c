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
#include <ctype.h>  // For isdigit()

void evaluatePostfix(char* expression) {
    int stack[100], top = -1;

    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];

        if (c == ' ') 
            continue;

        if (isdigit(c)) {  
            stack[++top] = c - '0'; 
        } else {
            int b = stack[top--];
            int a = stack[top--];

            switch (c) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
                default:
                    printf("Invalid operator: %c\n", c);
                    return;
            }
        }
    }
    printf("Result = %d\n", stack[top]);
}
int main() {
    char expression[] = "231*+9-";
    evaluatePostfix(expression); 

    char expression2[] = "52+";
    evaluatePostfix(expression2); 

    return 0;
}