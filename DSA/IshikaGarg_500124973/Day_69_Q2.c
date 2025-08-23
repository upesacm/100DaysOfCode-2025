#include <stdio.h>
#include <stdbool.h>

bool canPartition(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) total += arr[i];

    if (total % 2 != 0) return false;  // sum must be even
    int target = total / 2;

    bool dp[target + 1];
    for (int i = 0; i <= target; i++) dp[i] = false;
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = target; j >= arr[i]; j--) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }

    return dp[target];
}

int main() {
    int arr1[] = {1, 2, 3, 5};
    int n1 = 4;
    int arr2[] = {1, 5, 11, 5};
    int n2 = 4;

    printf("{1,2,3,5} -> %s\n", canPartition(arr1, n1) ? "true" : "false");
    printf("{1,5,11,5} -> %s\n", canPartition(arr2, n2) ? "true" : "false");

    return 0;
}

