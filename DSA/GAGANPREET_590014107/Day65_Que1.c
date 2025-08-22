#include <stdio.h>

int minCoins(int coins[], int numCoins, int amount) {
    int count = 0;
    for (int i = numCoins - 1; i >= 0; i--) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }
    return count;
}

int main() {
    int coins1[] = {1, 2, 5, 10};
    int amount1 = 23;
    int result1 = minCoins(coins1, 4, amount1);
    printf("%d\n", result1);

    int coins2[] = {1, 5, 6, 9};
    int amount2 = 11;
    int result2 = minCoins(coins2, 4, amount2);
    printf("%d\n", result2);

    return 0;
}
