#include <stdio.h>
#include <stdlib.h>

void nextGreaterElement(int arr[], int n, int result[]) {
    // Allocate stack to hold indices
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;  // Initialize stack as empty

    // Iterate through the array
    for (int i = 0; i < n; i++) {
        // While stack is not empty and current element is greater than
        // element corresponding to index at the stack top
        while (top != -1 && arr[i] > arr[stack[top]]) {
            result[stack[top]] = arr[i];
            top--;  // Pop the index from the stack
        }
        // Push current index onto the stack
        stack[++top] = i;
    }

    // For remaining indices, no next greater element exists
    while (top != -1) {
        result[stack[top]] = -1;
        top--;
    }

    free(stack);
}

int main() {
    // Example 1
    int arr1[] = {4, 5, 2, 25};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int result1[n1];

    nextGreaterElement(arr1, n1, result1);

    printf("Input: [4, 5, 2, 25]\nOutput: [");
    for (int i = 0; i < n1; i++) {
        printf("%d", result1[i]);
        if (i < n1 - 1) {
            printf(", ");
        }
    }
    printf("]\n\n");

    // Example 2
    int arr2[] = {13, 7, 6, 12};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int result2[n2];

    nextGreaterElement(arr2, n2, result2);

    printf("Input: [13, 7, 6, 12]\nOutput: [");
    for (int i = 0; i < n2; i++) {
        printf("%d", result2[i]);
        if (i < n2 - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}

