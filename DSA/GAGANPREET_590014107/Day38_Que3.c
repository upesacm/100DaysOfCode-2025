#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isRedundant(char* expression) {
    int n = strlen(expression);
    char* stack = (char*)malloc(n * sizeof(char));
    int top = -1;
    for (int i = 0; i < n; i++) {
        if (expression[i] == '(') {
            stack[++top] = expression[i];
        } else if (expression[i] == ')') {
            if (top == -1) {
                free(stack);
                return 1;
            }
            int hasOperator = 0;
            while (top != -1 && stack[top] != '(') {
                if (stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/') {
                    hasOperator = 1;
                }
                top--;
            }
            top--;
            if (!hasOperator) {
                free(stack);
                return 1;
            }
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            stack[++top] = expression[i];
        }
    }
    free(stack);
    return 0;
}
int main() {
    char* input1 = "((a+b))";
    char* input2 = "(a+b)";
    printf("%s\n", isRedundant(input1) ? "Yes" : "No");
    printf("%s\n", isRedundant(input2) ? "Yes" : "No");
    return 0;
}
