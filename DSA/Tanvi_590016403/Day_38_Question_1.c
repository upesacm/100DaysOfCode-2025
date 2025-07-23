#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// ========== 1. NEXT GREATER ELEMENT ==========
void nextGreaterElement(int arr[], int n) {
    int stack[n], top = -1;
    int result[n];

    for (int i = n - 1; i >= 0; i--) {
        while (top != -1 && stack[top] <= arr[i]) top--;
        result[i] = (top == -1) ? -1 : stack[top];
        stack[++top] = arr[i];
    }

    printf("Next Greater Elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

// ========== 2. MIN STACK ==========
#define MAX 100
int minStack[MAX], mainStack[MAX], minTop = -1, mainTop = -1;

void push(int x) {
    mainStack[++mainTop] = x;
    if (minTop == -1 || x <= minStack[minTop]) {
        minStack[++minTop] = x;
    }
}

void pop() {
    if (mainTop == -1) return;
    int popped = mainStack[mainTop--];
    if (popped == minStack[minTop]) {
        minTop--;
    }
}

int getMin() {
    if (minTop == -1) return INT_MAX;
    return minStack[minTop];
}

// ========== 3. REDUNDANT BRACKETS ==========
int isRedundant(char* expr) {
    char stack[100];
    int top = -1;

    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == ')') {
            int operatorFound = 0;
            while (top != -1 && stack[top] != '(') {
                char topChar = stack[top--];
                if (topChar == '+' || topChar == '-' || topChar == '*' || topChar == '/')
                    operatorFound = 1;
            }
            top--; // Pop the opening '('
            if (!operatorFound) return 1; // Redundant brackets found
        } else {
            stack[++top] = expr[i];
        }
    }
    return 0;
}

// ========== MAIN FUNCTION ==========
int main() {
    // 1. Next Greater Element Test
    int arr1[] = {4, 5, 2, 25};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    nextGreaterElement(arr1, n1);

    // 2. Min Stack Test
    push(5);
    push(3);
    push(7);
    printf("Minimum element: %d\n", getMin());
    push(2);
    pop();
    printf("Minimum element after pop: %d\n", getMin());

    // 3. Redundant Brackets Test
    char expr1[] = "((a+b))";
    char expr2[] = "(a+b)";
    printf("Expression: %s → %s\n", expr1, isRedundant(expr1) ? "Yes" : "No");
    printf("Expression: %s → %s\n", expr2, isRedundant(expr2) ? "Yes" : "No");

    return 0;
}
