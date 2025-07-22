#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE], top = -1;

void push(int val) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = val;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return 0;
    }
    return stack[top--];
}

void deleteMiddleUtil(int curr, int size) {
    if (curr == size / 2) {
        pop();
        return;
    }
    int temp = pop();
    deleteMiddleUtil(curr + 1, size);
    push(temp);
}

void deleteMiddle() {
    int size = top + 1;
    if (size == 0) return;
    deleteMiddleUtil(0, size);
}

void printStack() {
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    printf("Original stack: ");
    printStack();

    deleteMiddle();

    printf("After deleting middle: ");
    printStack();
    
    top = -1;
    push(10);
    push(20);
    push(30);

    printf("Original stack: ");
    printStack();

    deleteMiddle();

    printf("After deleting middle: ");
    printStack();

    return 0;
}
