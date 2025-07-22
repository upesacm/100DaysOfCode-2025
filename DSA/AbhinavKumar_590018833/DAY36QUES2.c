#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *arr;
    int top;
} Stack;

Stack* createStack2(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (char*)malloc(capacity * sizeof(char));
    stack->top = -1;
    return stack;
}

void push2(Stack* stack, char c) {
    stack->arr[++stack->top] = c;
}

char pop2(Stack* stack) {
    return stack->arr[stack->top--];
}

char peek2(Stack* stack) {
    return stack->arr[stack->top];
}

int isEmpty2(Stack* stack) {
    return stack->top == -1;
}

int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

int isBalanced(char *exp) {
    int len = strlen(exp);
    Stack *stack = createStack2(len);
    for (int i = 0; i < len; i++) {
        char c = exp[i];
        if (c == '(' || c == '{' || c == '[') {
            push2(stack, c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty2(stack) || !isMatchingPair(pop2(stack), c)) {
                free(stack->arr);
                free(stack);
                return 0;
            }
        }
    }
    int balanced = isEmpty2(stack);
    free(stack->arr);
    free(stack);
    return balanced;
}

int main() {
    char exp[] = "([])";
    if (isBalanced(exp)) printf("Balanced\n");
    else printf("Not Balanced\n");
    return 0;
}
