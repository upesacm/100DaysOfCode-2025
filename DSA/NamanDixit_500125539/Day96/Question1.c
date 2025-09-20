#include.<studio.h>

// Max function
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 1. 0/1 Knapsack Problem
int knapsack(int weights[], int values[], int n, int W) {
    int dp[n+1][W+1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i-1] <= w)
                dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][W];
}

// 2. Subset Sum Problem
int subsetSum(int arr[], int n, int target) {
    int dp[n+1][target+1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int j = 1; j <= target; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int sum = 1; sum <= target; sum++) {
            if (arr[i-1] <= sum)
                dp[i][sum] = dp[i-1][sum] || dp[i-1][sum - arr[i-1]];
            else
                dp[i][sum] = dp[i-1][sum];
        }
    }

    return dp[n][target];
}

// 3. Partition Equal Subset Sum
int canPartition(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];

    if (total % 2 != 0)
        return 0;

    return subsetSum(arr, n, total / 2);
}

// Main Function to Test All Three
int main() {
    // -------- 0/1 Knapsack Example --------
    int weights[] = {1, 3, 4, 5};
    int values[] = {1, 4, 5, 7};
    int W = 7;
    int n1 = sizeof(weights)/sizeof(weights[0]);

    int knap_result = knapsack(weights, values, n1, W);
    printf("Knapsack Maximum Value: %d\n", knap_result);  // Output: 9

    // -------- Subset Sum Example --------
    int arr1[] = {3, 34, 4, 12, 5, 2};
    int target = 9;
    int n2 = sizeof(arr1)/sizeof(arr1[0]);

    int subset_result = subsetSum(arr1, n2, target);
    printf("Subset with sum %d exists? %s\n", target, subset_result ? "Yes" : "No");  // Output: Yes

    // -------- Partition Equal Subset Sum Example --------
    int arr2[] = {1, 5, 11, 5};
    int n3 = sizeof(arr2)/sizeof(arr2[0]);

    int partition_result = canPartition(arr2, n3);
    printf("Can array be partitioned into equal subsets? %s\n", partition_result ? "Yes" : "No");  // Output: Yes

    return 0;
}
