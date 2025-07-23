#include <stdio.h>
#include <limits.h>

#define MAX 1000

int stack[MAX], minStack[MAX];
int top1 = -1, top2 = -1;

void push(int x) {
    stack[++top1] = x;
    if (top2 == -1 || x <= minStack[top2])
        minStack[++top2] = x;
}

void pop() {
    if (top1 == -1) return;

    if (stack[top1] == minStack[top2])
        top2--;

    top1--;
}

int top() {
    if (top1 == -1) return -1;
    return stack[top1];
}

int getMin() {
    if (top2 == -1) return INT_MAX;
    return minStack[top2];
}


int main() {
    push(5); push(3); push(7);
    printf("Min: %d\n", getMin()); 

    top1 = top2 = -1; 

    push(8); push(2); push(6);
    pop();
    printf("Min: %d\n", getMin()); 

    return 0;
}

