#include <stdio.h>
#define MAX 100

int arr[MAX], top1 = -1, top2 = MAX;

void push1(int val) {
    if (top1 < top2 - 1)
        arr[++top1] = val;
    else
        printf("Stack Overflow\n");
}

void push2(int val) {
    if (top1 < top2 - 1)
        arr[--top2] = val;
    else
        printf("Stack Overflow\n");
}

int pop1() {
    if (top1 >= 0)
        return arr[top1--];
    return -1;
}

int pop2() {
    if (top2 < MAX)
        return arr[top2++];
    return -1;
}

void displayStacks() {
    printf("Stack1: ");
    for (int i = 0; i <= top1; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Stack2: ");
    for (int i = MAX - 1; i >= top2; i--)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1. Push Stack1\n2. Push Stack2\n3. Pop Stack1\n4. Pop Stack2\n5. Display\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push in Stack1: ");
                scanf("%d", &val);
                push1(val);
                break;
            case 2:
                printf("Enter value to push in Stack2: ");
                scanf("%d", &val);
                push2(val);
                break;
            case 3:
                val = pop1();
                if (val != -1)
                    printf("Popped from Stack1: %d\n", val);
                else
                    printf("Stack1 Underflow\n");
                break;
            case 4:
                val = pop2();
                if (val != -1)
                    printf("Popped from Stack2: %d\n", val);
                else
                    printf("Stack2 Underflow\n");
                break;
            case 5:
                displayStacks();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
