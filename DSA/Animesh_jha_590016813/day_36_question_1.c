#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

void reverseString(char str[]) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    for (i = 0; str[i] != '\0'; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);  

    reverseString(str);

    printf("Reversed string: %s\n", str);
    return 0;
}
