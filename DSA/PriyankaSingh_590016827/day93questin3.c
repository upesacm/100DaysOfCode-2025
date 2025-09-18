#include <stdio.h>
#include <limits.h>

int min(int a, int b) { return (a < b) ? a : b; }

int coinChange(int* coins, int coinsSize, int amount) {
    int dp[10001];  // assuming amount <= 10000
    for (int i = 0; i <= amount; i++) dp[i] = INT_MAX;
    dp[0] = 0;

    for (int a = 1; a <= amount; a++) {
        for (int j = 0; j < coinsSize; j++) {
            if (a - coins[j] >= 0 && dp[a - coins[j]] != INT_MAX) {
                dp[a] = min(dp[a], dp[a - coins[j]] + 1);
            }
        }
    }

    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

int main() {
    int coins1[] = {1,2,5};
    printf("%d\n", coinChange(coins1, 3, 11)); // Output: 3

    int coins2[] = {2};
    printf("%d\n", coinChange(coins2, 1, 3)); // Output: -1

    return 0;
}
