#include <stdio.h>

#define MAX 100

int stack[MAX], minStack[MAX];
int top = -1, minTop = -1;

void push(int x) {
    stack[++top] = x;
    if (minTop == -1 || x <= minStack[minTop])
        minStack[++minTop] = x;
}

int pop() {
    int popped = stack[top--];
    if (popped == minStack[minTop])
        minTop--;
    return popped;
}

int getMin() {
    return minStack[minTop];
}

int main() {
    push(5);
    push(3);
    push(7);

    printf("Min: %d\n", getMin());

    return 0;
}
