#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return 0;
    return stack[top--];
}

int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int isBalanced(char* expr) {
    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[')
            push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            char topChar = pop();
            if (!isMatching(topChar, ch))
                return 0;
        }
    }
    return top == -1;
}

int main() {
    char expr[] = "([])";

    if (isBalanced(expr))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
