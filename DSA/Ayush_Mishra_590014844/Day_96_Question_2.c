#include <stdio.h>

int main() {
    int n, target;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &target);

    int dp[n + 1][target + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= target; j++)
            dp[i][j] = 0;

    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    if (dp[n][target])
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
