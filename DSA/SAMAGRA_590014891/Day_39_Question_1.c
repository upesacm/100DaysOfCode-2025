#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int x) {
    if (top < MAX - 1)
        stack[++top] = x;
}

int pop() {
    if (top >= 0)
        return stack[top--];
    return -1;
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
    if (!isEmpty()) {
        int temp = pop();
        reverseStack();
        insertAtBottom(temp);
    }
}

void display() {
    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int n, val;
    printf("Enter number of elements in stack: ");
    scanf("%d", &n);
    printf("Enter %d elements (bottom to top):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    printf("Original Stack:\n");
    display();

    reverseStack();

    printf("Reversed Stack:\n");
    display();

    return 0;
}
