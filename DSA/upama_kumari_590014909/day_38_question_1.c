#include <stdio.h>

void nextGreaterElement(int arr[], int n, int result[]) {
    int stack[n];
    int top = -1;

    for (int i = n - 1; i >= 0; i--) {
        while (top >= 0 && stack[top] <= arr[i]) {
            top--;
        }

        result[i] = (top == -1) ? -1 : stack[top];

        stack[++top] = arr[i];
    }
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result[n];

    nextGreaterElement(arr, n, result);

    printf("Next Greater Elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
