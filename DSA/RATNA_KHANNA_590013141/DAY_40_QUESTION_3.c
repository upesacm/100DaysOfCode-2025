#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int mainStack[MAX], maxStack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    top++;
    mainStack[top] = x;
    if (top == 0)
        maxStack[top] = x;
    else
        maxStack[top] = (x > maxStack[top - 1]) ? x : maxStack[top - 1];
    printf("Pushed %d\n", x);
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return;
    }
    printf("Popped %d\n", mainStack[top]);
    top--;
}

void getMax() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Maximum element: %d\n", maxStack[top]);
}

int main() {
    int choice, value;
    printf("1: Push\n2: Pop\n3: getMax\n4: Exit\n");

    while (1) {
        printf("\nEnter choice: ");
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
                getMax();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
