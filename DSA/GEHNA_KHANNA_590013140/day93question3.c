#include <stdio.h>
#include <limits.h>

int minCoins(int* coins, int n, int amount) {
    int dp[amount+1];
    for (int i = 0; i <= amount; i++) dp[i] = INT_MAX;
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                if (dp[i - coins[j]] + 1 < dp[i]) dp[i] = dp[i - coins[j]] + 1;
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int n, amount;
    scanf("%d", &n);
    int coins[n];
    for (int i = 0; i < n; i++) scanf("%d", &coins[i]);
    scanf("%d", &amount);
    printf("%d\n", minCoins(coins, n, amount));
    return 0;
}
