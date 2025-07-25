#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top < MAX - 1)
        stack[++top] = x;
}

int pop() {
    if (top >= 0)
        return stack[top--];
    return -1; // error case
}

int isEmpty() {
    return top == -1;
}

void insertAtBottom(int x) {
    if (isEmpty()) {
        push(x);
        return;
    }

    int temp = pop();
    insertAtBottom(x);
    push(temp);
}

void reverseStack() {
    if (isEmpty())
        return;

    int temp = pop();
    reverseStack();
    insertAtBottom(temp);
}

int main() {
    int n, val;

    printf("Enter number of elements in stack: ");
    scanf("%d", &n);

    printf("Enter %d elements :\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    reverseStack();

    printf("Reversed stack :\n");
    while (!isEmpty()) {
        printf("%d ", pop());
    }

    return 0;
}
