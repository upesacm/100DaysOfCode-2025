#include <stdio.h>
#include <limits.h>

int coinChange(int* coins, int coinsSize, int amount) {
    int dp[amount + 1];

    
    for (int i = 0; i <= amount; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;  

    
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                int candidate = dp[i - coins[j]] + 1;
                if (candidate < dp[i]) {
                    dp[i] = candidate;
                }
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int coins1[] = {1, 2, 5};
    int amount1 = 11;
    int result1 = coinChange(coins1, sizeof(coins1)/sizeof(coins1[0]), amount1);
    printf("Minimum coins (Example 1): %d\n", result1);  

    int coins2[] = {2};
    int amount2 = 3;
    int result2 = coinChange(coins2, sizeof(coins2)/sizeof(coins2[0]), amount2);
    printf("Minimum coins (Example 2): %d\n", result2);  

    return 0;
}