#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    int top;
    unsigned capacity;
    char* array;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

char pop(Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

void reverseString(char* str) {
    int n = strlen(str);
    Stack* stack = createStack(n);

    for (int i = 0; i < n; i++) {
        push(stack, str[i]);
    }

    for (int i = 0; i < n; i++) {
        str[i] = pop(stack);
    }

    free(stack->array);
    free(stack);
}

int main() {
    char str1[] = "hello";
    printf("Original string: %s\n", str1);
    reverseString(str1);
    printf("Reversed string: %s\n", str1);

    char str2[] = "abcde";
    printf("Original string: %s\n", str2);
    reverseString(str2);
    printf("Reversed string: %s\n", str2);

    return 0;
}