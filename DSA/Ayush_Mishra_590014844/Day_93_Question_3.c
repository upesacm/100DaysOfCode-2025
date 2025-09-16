#include <stdio.h>
#define INF 1000000

int minCoins(int* coins, int numCoins, int amount) {
    int dp[amount + 1];
    for (int i = 0; i <= amount; i++) dp[i] = INF;
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < numCoins; j++) {
            if (coins[j] <= i) {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INF && sub_res + 1 < dp[i]) {
                    dp[i] = sub_res + 1;
                }
            }
        }
    }
    return dp[amount] == INF ? -1 : dp[amount];
}

int main() {
    int numCoins, amount;
    printf("Enter number of coin denominations: ");
    scanf("%d", &numCoins);

    int coins[numCoins];
    printf("Enter coin denominations:\n");
    for (int i = 0; i < numCoins; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter target amount: ");
    scanf("%d", &amount);

    int result = minCoins(coins, numCoins, amount);
    if (result == -1)
        printf("No solution possible\n");
    else
        printf("Minimum coins required: %d\n", result);
    return 0;
}
