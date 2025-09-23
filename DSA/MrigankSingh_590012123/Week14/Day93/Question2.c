#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int maxSubArray(int* nums, int n) {
    if (n == 0) return 0;

    int current_sum = nums[0];
    int max_sum = nums[0];

    // Kadane's algorithm
    for (int i = 1; i < n; i++) {
        current_sum = max(nums[i], current_sum + nums[i]);
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    // Dynamically allocate array for numbers
    int *nums = (int *)malloc(n * sizeof(int));
    if (nums == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &nums[i]);
    }

    int result = maxSubArray(nums, n);
    printf("%d\n", result);

    free(nums); // Free allocated memory
    return 0;
}
