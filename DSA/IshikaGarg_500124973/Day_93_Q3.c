#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int coinChange(int* coins, int coinsSize, int amount) {
    int dp[amount + 1];

    // Initialize dp with "infinity"
    for (int i = 0; i <= amount; i++) dp[i] = INT_MAX;
    dp[0] = 0; // Base case

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

int main() {
    int n, amount;
    printf("Enter number of coin types: ");
    scanf("%d", &n);

    int coins[n];
    printf("Enter coin denominations:\n");
    for (int i = 0; i < n; i++) scanf("%d", &coins[i]);

    printf("Enter target amount: ");
    scanf("%d", &amount);

    int result = coinChange(coins, n, amount);
    if (result == -1)
        printf("No solution possible\n");
    else
        printf("Minimum coins needed = %d\n", result);

    return 0;
}

