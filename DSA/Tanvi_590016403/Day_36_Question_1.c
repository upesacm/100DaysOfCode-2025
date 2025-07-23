 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// ---------------------- Stack for Characters ----------------------
char stackChar[MAX];
int topChar = -1;

void pushChar(char c) {
    stackChar[++topChar] = c;
}

char popChar() {
    return stackChar[topChar--];
}

int isEmptyChar() {
    return topChar == -1;
}

// Function 1: Reverse a string using stack
void reverseString(char str[]) {
    topChar = -1; // Reset stack
    for (int i = 0; str[i]; i++) {
        pushChar(str[i]);
    }

    for (int i = 0; str[i]; i++) {
        str[i] = popChar();
    }

    printf("Reversed String: %s\n", str);
}

// ---------------------- Stack for Parentheses ----------------------
char isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// Function 2: Check for balanced parentheses
void checkBalancedParentheses(char exp[]) {
    topChar = -1; // Reset stack
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            pushChar(exp[i]);
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (isEmptyChar() || !isMatchingPair(popChar(), exp[i])) {
                printf("Not Balanced\n");
                return;
            }
        }
    }

    printf(isEmptyChar() ? "Balanced\n" : "Not Balanced\n");
}

// ---------------------- Stack for Integers ----------------------
int stackInt[MAX];
int topInt = -1;

void pushInt(int x) {
    stackInt[++topInt] = x;
}

int popInt() {
    return stackInt[topInt--];
}

int isEmptyInt() {
    return topInt == -1;
}

// Function 3: Insert at bottom of stack using recursion
void insertAtBottom(int x) {
    if (isEmptyInt()) {
        pushInt(x);
    } else {
        int temp = popInt();
        insertAtBottom(x);
        pushInt(temp);
    }
}

// Function to print stack
void printStack() {
    printf("Stack from bottom to top: ");
    for (int i = 0; i <= topInt; i++) {
        printf("%d ", stackInt[i]);
    }
    printf("\n");
}

// ---------------------- Main ----------------------
int main() {
    // 1. Reverse a String
    char str1[] = "hello";
    reverseString(str1);

    // 2. Check Balanced Parentheses
    char expr1[] = "([])";
    checkBalancedParentheses(expr1);

    char expr2[] = "([";
    checkBalancedParentheses(expr2);

    // 3. Insert at Bottom of Stack
    topInt = -1; // Reset stack
    pushInt(1);
    pushInt(2);
    pushInt(3);

    int x = 0;
    insertAtBottom(x);
    printStack();

    return 0;
}
