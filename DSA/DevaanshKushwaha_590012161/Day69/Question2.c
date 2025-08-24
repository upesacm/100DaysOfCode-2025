#include <stdio.h>
#include <stdbool.h>

bool canPartition(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

    if (sum % 2 != 0) return false;  // odd sum can't be split equally

    int target = sum / 2;
    bool dp[target + 1];
    for (int i = 0; i <= target; i++) dp[i] = false;
    dp[0] = true;

    // Subset sum DP
    for (int i = 0; i < n; i++) {
        for (int j = target; j >= arr[i]; j--) {
            if (dp[j - arr[i]]) dp[j] = true;
        }
    }

    return dp[target];
}

int main() {
    int arr1[] = {1, 2, 3, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Input: [1, 2, 3, 5] → Output: %s\n", canPartition(arr1, n1) ? "true" : "false");

    int arr2[] = {1, 5, 11, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Input: [1, 5, 11, 5] → Output: %s\n", canPartition(arr2, n2) ? "true" : "false");

    return 0;
}
