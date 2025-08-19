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
    int coins1[] = {1, 2, 5, 10};
    printf("Minimum coins: %d\n", minCoins(coins1, 4, 23)); // 5 (10+10+2+1)

    int coins2[] = {1, 5, 6, 9};
    printf("Minimum coins: %d\n", minCoins(coins2, 4, 11)); // 2 (5+6)
    return 0;
}
