#include <stdio.h>
#define MAX 1000

int stack[MAX], maxStack[MAX];
int top = -1, maxTop = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }

    stack[++top] = x;

   
    if (maxTop == -1 || x >= maxStack[maxTop])
        maxStack[++maxTop] = x;
    else
        maxStack[++maxTop] = maxStack[maxTop]; 
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return;
    }

    top--;
    maxTop--;
}

int getMax() {
    if (maxTop == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return maxStack[maxTop];
}

void displayStack() {
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Get Max\n4. Display Stack\n5. Exit\nEnter choice: ");
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
                printf("Current Max: %d\n", getMax());
                break;
            case 4:
                displayStack();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
