#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int x) {
    if (top1 + 1 < top2) {
        arr[++top1] = x;
    } else {
        printf("Overflow: No space in Stack1\n");
    }
}

int pop1() {
    if (top1 >= 0) {
        return arr[top1--];
    } else {
        printf("Underflow: Stack1 is empty\n");
        return -1;
    }
}

void push2(int x) {
    if (top1 + 1 < top2) {
        arr[--top2] = x;
    } else {
        printf("Overflow: No space in Stack2\n");
    }
}

int pop2() {
    if (top2 < MAX) {
        return arr[top2++];
    } else {
        printf("Underflow: Stack2 is empty\n");
        return -1;
    }
}

void display1() {
    printf("Stack1: [");
    for (int i = 0; i <= top1; i++) {
        printf("%d", arr[i]);
        if (i < top1) printf(", ");
    }
    printf("]\n");
}

void display2() {
    printf("Stack2: [");
    for (int i = MAX - 1; i >= top2; i--) {
        printf("%d", arr[i]);
        if (i > top2) printf(", ");
    }
    printf("]\n");
}

int main() {
    int choice, stackNum, value;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stacks\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: 
            printf("Enter stack number (1 or 2): ");
            scanf("%d", &stackNum);
            printf("Enter value to push: ");
            scanf("%d", &value);
            if (stackNum == 1)
                push1(value);
            else if (stackNum == 2)
                push2(value);
            else
                printf("Invalid stack number\n");
            break;

        case 2: 
            printf("Enter stack number (1 or 2): ");
            scanf("%d", &stackNum);
            if (stackNum == 1)
                printf("Popped from Stack1: %d\n", pop1());
            else if (stackNum == 2)
                printf("Popped from Stack2: %d\n", pop2());
            else
                printf("Invalid stack number\n");
            break;

        case 3: 
            display1();
            display2();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
