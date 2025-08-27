//Note to self: greedy doesn't work for all cases, but works for standard currency systems

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int minCoins(int coins[], int n, int amount) {
    qsort(coins, n, sizeof(int), compare);
    
    int count = 0;
    
    for (int i = 0; i < n && amount > 0; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }
    
    return amount == 0 ? count : -1;
}

int main() {
    int n, amount;
    printf("Enter number of coin denominations: ");
    scanf("%d", &n);
    
    int* coins = (int*)malloc(n * sizeof(int));
    printf("Enter coin denominations: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    
    printf("Enter target amount: ");
    scanf("%d", &amount);
    
    int result = minCoins(coins, n, amount);
    
    if (result == -1) {
        printf("Cannot make exact change with given denominations\n");
    } else {
        printf("Minimum coins needed: %d\n", result);
    }
    
    free(coins);
    return 0;
}
