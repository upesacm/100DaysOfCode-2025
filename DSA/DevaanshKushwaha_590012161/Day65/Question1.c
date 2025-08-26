#include <stdio.h>
#include <stdlib.h>

// Comparator for descending order
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

void minCoins(int coins[], int n, int amount) {
    qsort(coins, n, sizeof(int), compare);

    int count = 0;
    printf("Coins used: ");
    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            printf("%d ", coins[i]);
            count++;
        }
    }
    printf("\nMinimum coins required: %d\n", count);
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

    minCoins(coins, n, amount);
    return 0;
}
