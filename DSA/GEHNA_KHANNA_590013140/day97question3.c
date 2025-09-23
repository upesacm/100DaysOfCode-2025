#include <stdio.h>
#include <limits.h>

int min(int a, int b) { return a < b ? a : b; }

int mcm(int arr[], int n) {
    int dp[n][n];
    for (int i = 1; i < n; i++) dp[i][i] = 0;
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n-1];
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%d\n", mcm(arr, n));
    return 0;
}
