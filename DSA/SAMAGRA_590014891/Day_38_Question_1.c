#include <stdio.h>

void nextGreaterElement(int arr[], int n) {
    int stack[n];
    int top = -1;
    int result[n];

    for (int i = n - 1; i >= 0; i--) {
        while (top != -1 && stack[top] <= arr[i])
            top--;

        result[i] = (top == -1) ? -1 : stack[top];
        stack[++top] = arr[i];
    }

    printf("Next Greater Elements:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    nextGreaterElement(arr, n);

    return 0;
}
