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

void insertAtBottom(int x) {
    if (top == -1) {
        push(x);
        return;
    }
    int temp = pop();
    insertAtBottom(x);
    push(temp);
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

    insertAtBottom(0);

    printStack();
    return 0;
}
