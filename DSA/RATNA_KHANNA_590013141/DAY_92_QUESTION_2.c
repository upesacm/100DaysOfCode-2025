#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of steps: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input. Steps must be non-negative.\n");
        return 0;
    }

    long long dp[n + 1];
    dp[0] = 1;
    if (n >= 1) dp[1] = 1;

    for (i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    printf("The total number of ways to climb %d steps is: %lld\n", n, dp[n]);
    return 0;
}
