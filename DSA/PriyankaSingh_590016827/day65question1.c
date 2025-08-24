#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // descending
}

void minCoins(int coins[], int n, int amount) {
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
    printf("\nMinimum coins: %d\n", count);
}

int main() {
    int n, amount;
    printf("Enter number of coin denominations: ");
    scanf("%d", &n);
    int coins[n];
    printf("Enter coin denominations:\n");
    for (int i = 0; i < n; i++) scanf("%d", &coins[i]);
    printf("Enter amount: ");
    scanf("%d", &amount);

    minCoins(coins, n, amount);
    return 0;
}
