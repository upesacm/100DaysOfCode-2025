#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *arr;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (char*)malloc(capacity * sizeof(char));
    return stack;
}

void push(Stack* stack, char c) {
    stack->arr[++stack->top] = c;
}

char pop(Stack* stack) {
    return stack->arr[stack->top--];
}

char* reverseString(char *str) {
    int n = strlen(str);
    Stack* stack = createStack(n);
    
    for (int i = 0; i < n; i++) push(stack, str[i]);
    for (int i = 0; i < n; i++) str[i] = pop(stack);
    
    free(stack->arr);
    free(stack);
    return str;
}

int main() {
    char str[] = "hello";
    printf("Reversed: %s\n", reverseString(str)); // olleh
    return 0;
}
