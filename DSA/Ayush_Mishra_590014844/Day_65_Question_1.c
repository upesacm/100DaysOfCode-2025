#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int n, amount;
    printf("Enter number of coin denominations: ");
    scanf("%d", &n);

    int coins[n];
    printf("Enter coin denominations: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter amount to make: ");
    scanf("%d", &amount);

    qsort(coins, n, sizeof(int), compare);

    int count = 0;
    for (int i = 0; i < n && amount > 0; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }

    if (amount == 0)
        printf("Minimum coins required: %d\n", count);
    else
        printf("Cannot make the exact amount with given denominations.\n");

    return 0;
}
