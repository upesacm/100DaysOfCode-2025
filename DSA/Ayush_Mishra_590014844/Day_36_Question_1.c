#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int main() {
    char str[MAX], reversed[MAX];
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);
    for (int i = 0; i < len; i++)
        push(str[i]);

    for (int i = 0; i < len; i++)
        reversed[i] = pop();
    reversed[len] = '\0';

    printf("Reversed string: %s\n", reversed);
    return 0;
}
