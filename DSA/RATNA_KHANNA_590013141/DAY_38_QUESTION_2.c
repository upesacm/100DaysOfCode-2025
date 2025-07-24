#include <stdio.h>
#include <limits.h>
#define MAX 100
int mainStack[MAX];
int minStack[MAX];
int topMain = -1;
int topMin = -1;
void push(int x) {
    if (topMain == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    mainStack[++topMain] = x;
    if (topMin == -1 || x <= minStack[topMin]) {
        minStack[++topMin] = x;
    } else {
        minStack[++topMin] = minStack[topMin - 1];
    }
    printf("Pushed %d\n", x);
}
void pop() {
    if (topMain == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("Popped %d\n", mainStack[topMain]);
    topMain--;
    topMin--;
}
void top() {
    if (topMain == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", mainStack[topMain]);
    }
}
void getMin() {
    if (topMin == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Minimum element: %d\n", minStack[topMin]);
    }
}

int main() {
    int choice, value;
    printf("Min Stack Implementation (Push, Pop, Top, GetMin)\n");
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Get Min\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
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
            top();
            break;
        case 4:
            getMin();
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
