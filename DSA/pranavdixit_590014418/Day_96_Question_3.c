#include <stdio.h>

int canPartition(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) total += arr[i];
    if (total % 2 != 0) return 0;

    int target = total / 2;
    int dp[n+1][target+1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int j = 1; j <= target; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][target];
}

int main() {
    int arr[] = {1,5,11,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    if (canPartition(arr, n)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
