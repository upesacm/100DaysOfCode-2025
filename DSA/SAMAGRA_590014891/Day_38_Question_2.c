#include <stdio.h>
#define MAX 100

int stack[MAX], minStack[MAX];
int top = -1, minTop = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
    if (minTop == -1 || x <= minStack[minTop])
        minStack[++minTop] = x;
    printf("Pushed %d\n", x);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    int popped = stack[top--];
    if (popped == minStack[minTop])
        minTop--;
    printf("Popped %d\n", popped);
}

void getMin() {
    if (minTop == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Minimum element is: %d\n", minStack[minTop]);
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Get Min\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                getMin();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
