#include <stdio.h>
#define MAX 100

int arr[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int x) {
    if (top1 < top2 - 1) {
        arr[++top1] = x;
    } else {
        printf("Stack Overflow in Stack1\n");
    }
}

void push2(int x) {
    if (top1 < top2 - 1) {
        arr[--top2] = x;
    } else {
        printf("Stack Overflow in Stack2\n");
    }
}

void pop1() {
    if (top1 >= 0) {
        printf("Popped from Stack1: %d\n", arr[top1--]);
    } else {
        printf("Stack Underflow in Stack1\n");
    }
}

void pop2() {
    if (top2 < MAX) {
        printf("Popped from Stack2: %d\n", arr[top2++]);
    } else {
        printf("Stack Underflow in Stack2\n");
    }
}

void display1() {
    printf("Stack1: ");
    for (int i = 0; i <= top1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void display2() {
    printf("Stack2: ");
    for (int i = MAX - 1; i >= top2; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, stackNum, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) break;

        switch (choice) {
            case 1:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNum);
                printf("Enter value to push: ");
                scanf("%d", &value);
                if (stackNum == 1) push1(value);
                else if (stackNum == 2) push2(value);
                else printf("Invalid stack number\n");
                break;

            case 2:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNum);
                if (stackNum == 1) pop1();
                else if (stackNum == 2) pop2();
                else printf("Invalid stack number\n");
                break;

            case 3:
                display1();
                display2();
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
