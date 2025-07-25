#include <stdio.h>
#define MAX 100

int arr[MAX];
int top1 = -1, top2 = MAX;

void push1(int x) {
    if (top1 + 1 < top2)
        arr[++top1] = x;
}

void push2(int x) {
    if (top1 + 1 < top2)
        arr[--top2] = x;
}

int pop1() {
    return (top1 >= 0) ? arr[top1--] : -1;
}

int pop2() {
    return (top2 < MAX) ? arr[top2++] : -1;
}

void displayStacks() {
    printf("Stack1: ");
    for (int i = 0; i <= top1; i++) printf("%d ", arr[i]);
    printf("\nStack2: ");
    for (int i = MAX - 1; i >= top2; i--) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1. Push Stack1\n2. Push Stack2\n3. Pop Stack1\n4. Pop Stack2\n5. Display\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value for Stack1: ");
                scanf("%d", &val);
                push1(val);
                break;
            case 2:
                printf("Enter value for Stack2: ");
                scanf("%d", &val);
                push2(val);
                break;
            case 3:
                val = pop1();
                if (val == -1) printf("Stack1 Empty\n");
                else printf("Popped from Stack1: %d\n", val);
                break;
            case 4:
                val = pop2();
                if (val == -1) printf("Stack2 Empty\n");
                else printf("Popped from Stack2: %d\n", val);
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
