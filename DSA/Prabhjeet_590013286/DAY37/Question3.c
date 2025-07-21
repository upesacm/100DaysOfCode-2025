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

    int mid = n / 2;

    // Transfer all except middle to temp
    for (int i = 0; i < n; i++) {
        int x = stack[top];
        top--;
        if (i != mid) {
            tempTop++;
            temp[tempTop] = x;
        }
    }

    // Restore back to original
    while (tempTop != -1) {
        top++;
        stack[top] = temp[tempTop];
        tempTop--;
    }

    printf("Stack after deleting middle (top to bottom): ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    return 0;
}
