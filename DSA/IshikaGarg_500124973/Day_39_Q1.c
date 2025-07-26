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

int isEmpty() {
    return top == -1;
}

void insertAtBottom(int x) {
    if (isEmpty()) {
        push(x);
    } else {
        int temp = pop();
        insertAtBottom(x);
        push(temp);
    }
}

void reverse() {
    if (!isEmpty()) {
        int temp = pop();
        reverse();
        insertAtBottom(temp);
    }
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

    printf("Original Stack: ");
    printStack();

    reverse();

    printf("Reversed Stack: ");
    printStack();

    return 0;
}
