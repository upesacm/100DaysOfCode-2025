
#include <stdio.h>

#define MAX 100

int stack[MAX], minStack[MAX];
int top = -1, minTop = -1;

void push(int x) {
    stack[++top] = x;
    if (minTop == -1 || x <= minStack[minTop])
        minStack[++minTop] = x;
}

void pop() {
    if (top == -1) return;
    if (stack[top] == minStack[minTop])
        minTop--;
    top--;
}

int getMin() {
    if (minTop == -1) return -1;
    return minStack[minTop];
}

int main() {
    push(5);
    push(3);
    push(7);
    printf("Min: %d\n", getMin());

    push(8);
    push(2);
    push(6);
    pop();
    printf("Min: %d\n", getMin());

    return 0;
}
