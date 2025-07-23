#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CharStack {
    int top;
    unsigned capacity;
    char* array;
} CharStack;

CharStack* createCharStack(unsigned capacity) {
    CharStack* stack = (CharStack*) malloc(sizeof(CharStack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}

int isCharStackFull(CharStack* stack) {
    return stack->top == stack->capacity - 1;
}

int isCharStackEmpty(CharStack* stack) {
    return stack->top == -1;
}

void pushChar(CharStack* stack, char item) {
    if (isCharStackFull(stack))
        return;
    stack->array[++stack->top] = item;
}

char popChar(CharStack* stack) {
    if (isCharStackEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

char peekChar(CharStack* stack) {
    if (isCharStackEmpty(stack))
        return '\0';
    return stack->array[stack->top];
}

int isMatchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')')
        return 1;
    else if (char1 == '{' && char2 == '}')
        return 1;
    else if (char1 == '[' && char2 == ']')
        return 1;
    else
        return 0;
}

int areParenthesesBalanced(char* exp) {
    int i = 0;
    CharStack* stack = createCharStack(strlen(exp));

    while (exp[i] != '\0') {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            pushChar(stack, exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isCharStackEmpty(stack)) {
                free(stack->array);
                free(stack);
                return 0;
            } else if (!isMatchingPair(popChar(stack), exp[i])) {
                free(stack->array);
                free(stack);
                return 0;
            }
        }
        i++;
    }

    int result = isCharStackEmpty(stack);
    free(stack->array);
    free(stack);
    return result;
}

int main() {
    char exp1[] = "([])";
    if (areParenthesesBalanced(exp1))
        printf("Input: %s\nOutput: Balanced\n", exp1);
    else
        printf("Input: %s\nOutput: Not Balanced\n", exp1);

    char exp2[] = "([)";
    if (areParenthesesBalanced(exp2))
        printf("Input: %s\nOutput: Balanced\n", exp2);
    else
        printf("Input: %s\nOutput: Not Balanced\n", exp2);

    char exp3[] = "{[()]}";
    if (areParenthesesBalanced(exp3))
        printf("Input: %s\nOutput: Balanced\n", exp3);
    else
        printf("Input: %s\nOutput: Not Balanced\n", exp3);

    char exp4[] = "}{";
    if (areParenthesesBalanced(exp4))
        printf("Input: %s\nOutput: Balanced\n", exp4);
    else
        printf("Input: %s\nOutput: Not Balanced\n", exp4);

    return 0;
}