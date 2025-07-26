#include <stdio.h>

#define MAX 100

int stack[MAX], maxStack[MAX];
int top = -1, maxTop = -1;

void push(int x) {
    stack[++top] = x;
    if (maxTop == -1 || x >= maxStack[maxTop])
        maxStack[++maxTop] = x;
}

int pop() {
    int x = stack[top--];
    if (x == maxStack[maxTop])
        maxTop--;
    return x;
}

int getMax() {
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
