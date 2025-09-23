#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int lengthOfLIS(int* nums, int n) {
    if (n == 0) return 0;

    // Dynamically allocate array for DP
    int *dp = (int *)malloc(n * sizeof(int));
    if (dp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Initialize DP array
    for (int i = 0; i < n; i++) {
        dp[i] = 1; // Each element is an LIS of length 1
    }

    // Bottom-up DP
    int max_length = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_length = max(max_length, dp[i]);
    }

    free(dp); // Free allocated memory
    return max_length;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    // Dynamically allocate array for numbers
    int *nums = (int *)malloc(n * sizeof(int));
    if (nums == NULL && n > 0) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    if (n > 0) {
        printf("Enter the elements of the array:\n");
        for (int i = 0; i < n; i++) {
            printf("Element %d: ", i);
            scanf("%d", &nums[i]);
        }
    }

    int result = lengthOfLIS(nums, n);
    printf("%d\n", result);

    free(nums); // Free allocated memory
    return 0;
}
