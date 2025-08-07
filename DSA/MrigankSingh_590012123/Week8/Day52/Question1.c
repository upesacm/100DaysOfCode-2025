#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool sum_pair(int arr[], int n, int x) {
    if (n < 2) {
        return false;
    }

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == x) {
            return true;
        } else if (currentSum < x) {
            left++;
        } else {
            right--;
        }
    }

    return false;
}

int main() {
    int n, x;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array is empty. No pairs possible.\n");
        return 0;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum (x): ");
    scanf("%d", &x);

    qsort(arr, n, sizeof(int), compare);

    bool result = sum_pair(arr, n, x);

    printf("Output: %s\n", result ? "true" : "false");

    free(arr);
    return 0;
}
