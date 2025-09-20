#include <stdio.h>
#include <limits.h>

int coinChange(int coins[], int m, int amount) {
    int dp[amount+1];
    for (int i = 0; i <= amount; i++) dp[i] = INT_MAX;
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < m; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                if (dp[i - coins[j]] + 1 < dp[i])
                    dp[i] = dp[i - coins[j]] + 1;
            }
        }
    }
    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

int main() {
    int coins1[] = {1,2,5};
    int coins2[] = {2};

    printf("Min coins (case 1): %d\n", coinChange(coins1, 3, 11));
    printf("Min coins (case 2): %d\n", coinChange(coins2, 1, 3));

    return 0;
}
