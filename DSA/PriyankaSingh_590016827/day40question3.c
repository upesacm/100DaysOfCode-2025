
#include <stdio.h>

#define MAX 100

int stack[MAX], maxStack[MAX];
int top = -1, maxTop = -1;

void push(int x) {
    stack[++top] = x;
    if (maxTop == -1 || x >= maxStack[maxTop])
        maxStack[++maxTop] = x;
}

void pop() {
    if (top == -1) return;
    if (stack[top] == maxStack[maxTop])
        maxTop--;
    top--;
}

int getMax() {
    if (maxTop == -1) return -1;
    return maxStack[maxTop];
}

int main() {
    push(3);
    push(5);
    push(2);
    printf("Max: %d\n", getMax());

    pop();
    printf("Max after pop: %d\n", getMax());

    return 0;
}
