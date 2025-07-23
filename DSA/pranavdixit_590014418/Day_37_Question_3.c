#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

void deleteMiddle(int current, int target) {
    if (top == -1)
        return;

    int x = pop();

    if (current != target)
        deleteMiddle(current + 1, target);

    if (current != target)
        push(x);
}

void printStack() {
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    int mid = (top + 1) / 2;
    deleteMiddle(0, mid);

    printStack();
    return 0;
}
