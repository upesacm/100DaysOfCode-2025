#include <stdio.h>
#define MAX 100

int main() {
    int stack[MAX], minStack[MAX];
    int top = -1, minTop = -1, ch, x;

    while(1) {
        printf("\n1. Push\n2. Pop\n3. Get Min\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        if(ch == 1) {
            printf("Enter element to push: ");
            scanf("%d", &x);
            stack[++top] = x;
            if(minTop == -1 || x <= minStack[minTop]) {
                minStack[++minTop] = x;
            }
        } else if(ch == 2) {
            if(top == -1) {
                printf("Stack is empty\n");
            } else {
                if(stack[top] == minStack[minTop]) {
                    minTop--;
                }
                top--;
            }
        } else if(ch == 3) {
            if(minTop == -1) {
                printf("Stack is empty\n");
            } else {
                printf("Minimum element: %d\n", minStack[minTop]);
            }
        } else if(ch == 4) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
