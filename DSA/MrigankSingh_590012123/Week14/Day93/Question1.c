#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int houseRobber(int* nums, int n) {
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    // Dynamically allocate array for DP
    int *dp = (int *)malloc(n * sizeof(int));
    if (dp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Base cases
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    // Bottom-up DP
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }

    int result = dp[n-1];
    free(dp); // Free allocated memory
    return result;
}

int main() {
    int n;
    printf("Enter the number of houses: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    // Dynamically allocate array for house values
    int *nums = (int *)malloc(n * sizeof(int));
    if (nums == NULL && n > 0) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    if (n > 0) {
        printf("Enter the value for each house:\n");
        for (int i = 0; i < n; i++) {
            printf("Value for house %d: ", i);
            scanf("%d", &nums[i]);
        }
    }

    int result = houseRobber(nums, n);
    printf("%d\n", result);

    free(nums); // Free allocated memory
    return 0;
}
