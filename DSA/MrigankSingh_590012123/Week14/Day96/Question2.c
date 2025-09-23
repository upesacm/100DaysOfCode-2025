#include <stdio.h>
#include <stdlib.h>

int subsetSum(int* arr, int n, int target) {
    // Dynamically allocate 2D DP array
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    if (dp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((target + 1) * sizeof(int));
        if (dp[i] == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    // Initialize first column (sum = 0)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1; // Empty subset can achieve sum 0
    }

    // Initialize first row (no elements, sum > 0)
    for (int j = 1; j <= target; j++) {
        dp[0][j] = 0;
    }

    // Bottom-up DP
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int result = dp[n][target];

    // Free allocated memory
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    int n, target;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the target sum: ");
    scanf("%d", &target);

    if (n < 0 || target < 0) {
        printf("Please enter non-negative integers.\n");
        return 1;
    }

    // Dynamically allocate array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL && n > 0) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    if (n > 0) {
        printf("Enter the elements of the array:\n");
        for (int i = 0; i < n; i++) {
            printf("Element %d: ", i);
            scanf("%d", &arr[i]);
            if (arr[i] < 0) {
                printf("Please enter non-negative integers.\n");
                free(arr);
                return 1;
            }
        }
    }

    int result = subsetSum(arr, n, target);
    printf("%s\n", result ? "Yes" : "No");

    free(arr);
    return 0;
}
