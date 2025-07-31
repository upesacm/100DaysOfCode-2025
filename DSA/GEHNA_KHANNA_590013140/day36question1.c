#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char ch) {
    if (top < MAX_SIZE - 1) stack[++top] = ch;
    else exit(1);
}

char pop() {
    if (top >= 0) return stack[top--];
    else exit(1);
}

void reverse_string(char *s) {
    int n = strlen(s);
    for (int i = 0; i < n; i++) push(s[i]);
    for (int i = 0; i < n; i++) s[i] = pop();
}

int main() {
    char s[MAX_SIZE];
    if (!fgets(s, MAX_SIZE, stdin)) return 0;
    s[strcspn(s, "\n")] = '\0';
    reverse_string(s);
    printf("%s\n", s);
    return 0;
}
