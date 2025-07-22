
#include <stdio.h>

#define MAX 100

int main() {
    int stack[MAX], tempStack[MAX];
    int top = -1, tempTop = -1, n, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        while (tempTop != -1 && tempStack[tempTop] > val) {
            stack[++top] = tempStack[tempTop--];
        }
        tempStack[++tempTop] = val;
    }

    while (tempTop != -1) {
        stack[++top] = tempStack[tempTop--];
    }

    printf("Sorted stack (top to bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    return 0;
}
