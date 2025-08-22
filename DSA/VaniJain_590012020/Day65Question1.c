#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) 
{
    return (*(int *)b - *(int *)a);
}
void coinChange(int coins[], int n, int amount) 
{
    qsort(coins, n, sizeof(int), compare);
    int count = 0;
    printf("\nCoins used: ");
    for (int i = 0; i < n; i++) 
    {
        while (amount >= coins[i]) 
        {
            amount -= coins[i];
            printf("%d ", coins[i]);
            count++;
        }
    }
    if (amount != 0) 
    {
        printf("\nCannot make exact change with given coins.\n");
    } 
    else 
    {
        printf("\nMinimum number of coins required: %d\n", count);
    }
}
int main() 
{
    int n, amount;
    printf("Enter number of coin denominations: ");
    scanf("%d", &n);
    int coins[n];
    printf("Enter the coin denominations: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &coins[i]);
    }
    printf("Enter the amount: ");
    scanf("%d", &amount);
    coinChange(coins, n, amount);
    return 0;
}
