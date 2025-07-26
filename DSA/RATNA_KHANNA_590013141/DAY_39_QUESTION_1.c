#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;
void push(int x) {
    if (top < MAX - 1)
        stack[++top] = x;
    else
        printf("Stack Overflow\n");
}

int pop() {
    if (top >= 0)
        return stack[top--];
    else {
        printf("Stack Underflow\n");
        return -1;
    }
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

void printStack() {
    for (int i = 0; i <= top; i++)
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
    printStack();

    reverseStack();

    printf("Reversed Stack:\n");
    printStack();

    return 0;
}
