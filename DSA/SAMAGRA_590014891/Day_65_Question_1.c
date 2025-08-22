#include <stdio.h>

int minCoins(int coins[], int n, int amount) {
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }
    return count;
}

int main() {
    int n, amount;
    printf("Enter number of coin denominations: ");
    scanf("%d", &n);
    int coins[n];
    printf("Enter coin denominations: ");
    for (int i = 0; i < n; i++) scanf("%d", &coins[i]);
    printf("Enter amount: ");
    scanf("%d", &amount);
    printf("Minimum coins needed: %d\n", minCoins(coins, n, amount));
    return 0;
}
