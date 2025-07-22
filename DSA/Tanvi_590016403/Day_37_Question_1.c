#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

// ------------------- Stack for Integers -------------------
int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

void printStack() {
    printf("Stack from bottom to top: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// ------------------- 1. Sort Stack Using Another Stack -------------------
void sortStack() {
    int tempStack[MAX];
    int tempTop = -1;

    while (!isEmpty()) {
        int temp = pop();
        while (tempTop != -1 && tempStack[tempTop] > temp) {
            push(tempStack[tempTop--]);
        }
        tempStack[++tempTop] = temp;
    }

    while (tempTop != -1) {
        push(tempStack[tempTop--]);
    }

    printf("Sorted Stack:\n");
    printStack();
}

// ------------------- 2. Evaluate Postfix Expression -------------------
int evaluatePostfix(char* expr) {
    int evalTop = -1;
    int evalStack[MAX];

    for (int i = 0; expr[i]; i++) {
        char ch = expr[i];
        if (isdigit(ch)) {
            evalStack[++evalTop] = ch - '0';
        } else {
            int b = evalStack[evalTop--];
            int a = evalStack[evalTop--];
            switch (ch) {
                case '+': evalStack[++evalTop] = a + b; break;
                case '-': evalStack[++evalTop] = a - b; break;
                case '*': evalStack[++evalTop] = a * b; break;
                case '/': evalStack[++evalTop] = a / b; break;
            }
        }
    }

    return evalStack[evalTop];
}

// ------------------- 3. Delete Middle Element Using Recursion -------------------
void deleteMiddleUtil(int curr, int size) {
    if (curr == size / 2) {
        pop();  // Remove middle
        return;
    }

    int temp = pop();
    deleteMiddleUtil(curr + 1, size);
    push(temp);
}

void deleteMiddle() {
    int size = top + 1;
    deleteMiddleUtil(0, size);
    printf("Stack after deleting middle element:\n");
    printStack();
}

// ------------------- Main Function -------------------
int main() {
    // Problem 1: Sort Stack
    top = -1;
    push(3); push(1); push(4); push(2);
    sortStack();

    // Problem 2: Postfix Evaluation
    char expr1[] = "231*+9-";
    printf("\nPostfix Evaluation of \"%s\" = %d\n", expr1, evaluatePostfix(expr1));

    char expr2[] = "52+";
    printf("Postfix Evaluation of \"%s\" = %d\n", expr2, evaluatePostfix(expr2));

    // Problem 3: Delete Middle Element
    top = -1;
    push(1); push(2); push(3); push(4); push(5);
    deleteMiddle();

    top = -1;
    push(10); push(20); push(30);
    deleteMiddle();

    return 0;
}
