#include <stdio.h>

void nextGreater(int arr[], int n) {
    int stack[n];
    int top = -1;
    int result[n];

    for (int i = n - 1; i >= 0; i--) {
        // Pop smaller elements
        while (top != -1 && stack[top] <= arr[i])
            top--;

        if (top == -1)
            result[i] = -1;
        else
            result[i] = stack[top];

        // Push current element
        stack[++top] = arr[i];
    }

    // Print result
    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);
    printf("\n");
}

// Example
int main() {
    int arr1[] = {4, 5, 2, 25};
    int arr2[] = {13, 7, 6, 12};
    printf("Output 1: ");
    nextGreater(arr1, 4);  // Output: 5 25 25 -1
    printf("Output 2: ");
    nextGreater(arr2, 4);  // Output: -1 12 12 -1
    return 0;
}

