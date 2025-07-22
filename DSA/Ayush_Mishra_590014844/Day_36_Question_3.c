#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void insert_at_bottom(int x) {
    if (top == -1) {
        stack[++top] = x;
        return;
    }
    int temp = stack[top--];
    insert_at_bottom(x);
    stack[++top] = temp;
}

int main() {
    int n, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter stack elements (top to bottom): ");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        stack[++top] = val;
    }
    printf("Enter element to insert at bottom: ");
    scanf("%d", &x);

    insert_at_bottom(x);

    printf("Stack after insertion (bottom to top): ");
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
    return 0;
}
