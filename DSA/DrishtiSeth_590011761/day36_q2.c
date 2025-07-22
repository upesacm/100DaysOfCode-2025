#include <stdio.h>
#define MAX 1000

int isMatchingPair(char left, char right) {
    if (left == '(' && right == ')') return 1;
    if (left == '{' && right == '}') return 1;
    if (left == '[' && right == ']') return 1;
    return 0;
}

int main() {
    char expr[MAX], stack[MAX];
    int top = -1, isBalanced = 1;
    scanf("%s", expr);
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1 || !isMatchingPair(stack[top--], ch)) {
                isBalanced = 0;
                break;
            }
        }
    }
    if (top != -1) isBalanced = 0;
    if (isBalanced)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}