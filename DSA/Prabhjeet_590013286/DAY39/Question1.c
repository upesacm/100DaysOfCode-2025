#include <stdio.h>

#define MAX 100
int stack[MAX];
int top = -1;

void push(int x) {
    if (top < MAX - 1)
        stack[++top] = x;
}

int pop() {
    return (top >= 0) ? stack[top--] : -1;
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


void reverse() {
    if (top == -1) return;
    int temp = pop();
    reverse();
    insertAtBottom(temp);
}

void display() {
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    push(1); push(2); push(3);
    printf("Original stack: ");
    display();

    reverse();

    printf("Reversed stack: ");
    display();
    return 0;
}
