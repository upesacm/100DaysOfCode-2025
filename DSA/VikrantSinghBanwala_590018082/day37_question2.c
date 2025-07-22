#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}
int isEmpty(Stack* stack) {
    return stack->top == -1;
}
void push(Stack* stack, int value) {
    if (stack->top < MAX - 1) {
        stack->arr[++stack->top] = value;
    }
}
int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return 0;
}
int evaluatePostfix(const char* expression) {
    Stack* stack = createStack();
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(stack, expression[i] - '0');
        } else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            switch (expression[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
        }
    }
    int result = pop(stack);
    free(stack);
    return result;
}
int main() {
    const char* expression1 = "231*+9-";
    const char* expression2 = "52+";
    printf("Result of expression '%s': %d\n", expression1, evaluatePostfix(expression1));
    printf("Result of expression '%s': %d\n", expression2, evaluatePostfix(expression2));
    return 0;
}
