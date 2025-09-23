#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int coinChange(int* coins, int n, int amount) {
    // Dynamically allocate array for DP
    int *dp = (int *)malloc((amount + 1) * sizeof(int));
    if (dp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Initialize DP array
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
    }

    // Bottom-up DP
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    int result = (dp[amount] == INT_MAX) ? -1 : dp[amount];
    free(dp); // Free allocated memory
    return result;
}

int main() {
    int n, amount;
    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer for denominations.\n");
        return 1;
    }

    // Dynamically allocate array for coin denominations
    int *coins = (int *)malloc(n * sizeof(int));
    if (coins == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the coin denominations:\n");
    for (int i = 0; i < n; i++) {
        printf("Denomination %d: ", i);
        scanf("%d", &coins[i]);
    }

    printf("Enter the target amount: ");
    scanf("%d", &amount);

    if (amount < 0) {
        printf("Please enter a non-negative amount.\n");
        free(coins);
        return 1;
    }

    int result = coinChange(coins, n, amount);
    printf("%d\n", result);

    free(coins); // Free allocated memory
    return 0;
}
