#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int mainStack[MAX], minStack[MAX];
int topMain = -1, topMin = -1;

void push(int x) {
    mainStack[++topMain] = x;

    
    if (topMin == -1 || x <= minStack[topMin]) {
        minStack[++topMin] = x;
    }
}

void pop() {
    if (topMain == -1) {
        printf("Stack is empty\n");
        return;
    }

    int popped = mainStack[topMain--];

    if (popped == minStack[topMin]) {
        topMin--;  // Pop from min stack too
    }
}

int top() {
    if (topMain == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return mainStack[topMain];
}

int getMin() {
    if (topMin == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return minStack[topMin];
}

int main() {
    int choice, val;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Top\n4. Get Min\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Top element: %d\n", top());
                break;
            case 4:
                printf("Minimum element: %d\n", getMin());
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
