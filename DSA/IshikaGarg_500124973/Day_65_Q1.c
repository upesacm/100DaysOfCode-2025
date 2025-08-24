#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort (descending order)
int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int minCoins(int coins[], int n, int amount) {
    // Sort coins in descending order for greedy selection
    qsort(coins, n, sizeof(int), compare);

    int count = 0;
    printf("Coins used: ");
    for (int i = 0; i < n; i++) {
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
    int coins1[] = {1, 2, 5, 10}, amount1 = 23;
    int n1 = sizeof(coins1) / sizeof(coins1[0]);
    printf("Minimum coins for %d: %d\n\n", amount1, minCoins(coins1, n1, amount1));

    int coins2[] = {1, 5, 6, 9}, amount2 = 11;
    int n2 = sizeof(coins2) / sizeof(coins2[0]);
    printf("Minimum coins for %d: %d\n", amount2, minCoins(coins2, n2, amount2));

    return 0;
}

