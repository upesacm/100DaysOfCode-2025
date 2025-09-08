#include <stdio.h>

// Split Array into Equal Sum
int canPartition(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    if (sum % 2 != 0) {
        return 0;
    }

    int target = sum / 2;
    int dp[target + 1];
    for (int i = 0; i <= target; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = target; j >= arr[i]; j--) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }

    return dp[target];
}

int main() {
    // Example 1
    int arr1[] = {1, 2, 3, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    if (canPartition(arr1, n1)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    // Example 2
    int arr2[] = {1, 5, 11, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    if (canPartition(arr2, n2)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
