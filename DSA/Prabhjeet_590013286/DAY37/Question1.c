#include <stdio.h>

int main() {
    int stack[1000], temp[1000];
    int top = -1, tempTop = -1;
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter stack elements (top to bottom): ");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        top++;
        stack[top] = val;
    }

    // Sort using temp stack
    while (top != -1) {
        int cur = stack[top];
        top--;

        while (tempTop != -1 && temp[tempTop] > cur) {
            top++;
            stack[top] = temp[tempTop];
            tempTop--;
        }

        tempTop++;
        temp[tempTop] = cur;
    }

    // Transfer back to original
    while (tempTop != -1) {
        top++;
        stack[top] = temp[tempTop];
        tempTop--;
    }

    printf("Sorted Stack (top to bottom): ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    return 0;
}
