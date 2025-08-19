#include <stdio.h>
#include <stdlib.h>


int cmp(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int minCoins(int coins[], int n, int amount) {
    
    qsort(coins, n, sizeof(int), cmp);

    int count = 0;
    printf("Coins used: ");
    for (int i = 0; i < n && amount > 0; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
            printf("%d ", coins[i]);
        }
    }
    printf("\n");
    return count;
}

int main() {
    int coins[] = {1, 2, 5, 10};
    int amount = 23;
    int n = sizeof(coins) / sizeof(coins[0]);

    int result = minCoins(coins, n, amount);
    printf("Minimum coins: %d\n", result);
    return 0;
}

