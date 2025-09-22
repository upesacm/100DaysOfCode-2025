#include <stdio.h>
#include <limits.h>
int min(int a, int b) 
{
    return (a < b) ? a : b;
}
int main() 
{
    int N, amount;
    printf("Enter number of coin denominations: ");
    scanf("%d", &N);
    int coins[N];
    printf("Enter coin denominations:\n");
    for (int i = 0; i < N; i++) 
    {
        scanf("%d", &coins[i]);
    }
    printf("Enter target amount: ");
    scanf("%d", &amount);
    int dp[amount + 1];
    dp[0] = 0;  
    for (int i = 1; i <= amount; i++) 
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < N; j++) 
        {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) 
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    if (dp[amount] == INT_MAX)
        printf("No solution possible for amount %d.\n", amount);
    else
        printf("Minimum number of coins needed = %d\n", dp[amount]);
    return 0;
}
