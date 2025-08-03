#include <stdio.h>
#include <limits.h>

#define MAX 1000

int stack[MAX], minStack[MAX];
int top = -1, minTop = -1;

void push(int x) {
    stack[++top] = x;
    if (minTop == -1 || x <= minStack[minTop])
        minStack[++minTop] = x;
}

void pop() {
    if (top == -1) return;
    int removed = stack[top--];
    if (removed == minStack[minTop])
        minTop--;
}

int getMin() {
    if (minTop == -1) return INT_MAX;
    return minStack[minTop];
}

int main() {
    push(5);
    push(3);
    push(7);
    printf("Min: %d\n", getMin());  // Output: 3

    push(8);
    push(2);
    push(6);
    pop();
    printf("Min: %d\n", getMin());  // Output: 2
    return 0;
}
