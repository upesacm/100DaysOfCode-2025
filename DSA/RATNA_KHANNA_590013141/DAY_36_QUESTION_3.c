#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
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
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack (bottom to top): ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, val;

    printf("Enter number of elements in stack: ");
    scanf("%d", &n);

    printf("Enter %d elements (top will be last):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    printf("Original ");
    printStack();

    printf("Enter element to insert at bottom: ");
    scanf("%d", &val);
    insertAtBottom(val);

    printf("After inserting %d at bottom: ", val);
    printStack();

    return 0;
}
