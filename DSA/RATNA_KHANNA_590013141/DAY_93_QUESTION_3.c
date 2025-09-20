#include <stdio.h>
#include <limits.h>

int main() {
    int n, amount, i, j;
    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Number of coins must be positive.\n");
        return 0;
    }

    int coins[n];
    printf("Enter the coin denominations:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter the target amount: ");
    scanf("%d", &amount);

    if (amount < 0) {
        printf("Invalid input. Amount must be non-negative.\n");
        return 0;
    }

    int dp[amount + 1];
    for (i = 0; i <= amount; i++) {
        dp[i] = INT_MAX - 1;  
    }
    dp[0] = 0;

    for (i = 1; i <= amount; i++) {
        for (j = 0; j < n; j++) {
            if (coins[j] <= i) {
                if (dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }

    if (dp[amount] == INT_MAX - 1) {
        printf("No solution possible for the given amount.\n");
    } else {
        printf("Minimum coins needed: %d\n", dp[amount]);
    }

    return 0;
}
