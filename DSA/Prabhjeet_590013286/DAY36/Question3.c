#include <stdio.h>

int main() {
    int stack[1000], temp[1000];
    int top = -1, tempTop = -1;
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter stack elements (top to bottom): ");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        top++;
        stack[top] = val;
    }

    printf("Enter value to insert at bottom: ");
    scanf("%d", &x);

    // Pop all into temp
    while (top != -1) {
        tempTop++;
        temp[tempTop] = stack[top];
        top--;
    }

    // Push new element to bottom
    top++;
    stack[top] = x;

    // Restore rest from temp
    while (tempTop != -1) {
        top++;
        stack[top] = temp[tempTop];
        tempTop--;
    }

    printf("Updated Stack (top to bottom): ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    return 0;
}
