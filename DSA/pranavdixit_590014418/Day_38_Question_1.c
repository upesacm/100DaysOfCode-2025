#include <stdio.h>

#define MAX 100

void nextGreater(int arr[], int n, int result[]) {
    int stack[MAX];
    int top = -1;

    for (int i = n - 1; i >= 0; i--) {
        while (top != -1 && stack[top] <= arr[i])
            top--;

        if (top == -1)
            result[i] = -1;
        else
            result[i] = stack[top];

        stack[++top] = arr[i];
    }
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result[MAX];

    nextGreater(arr, n, result);

    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);

    printf("\n");
    return 0;
}
