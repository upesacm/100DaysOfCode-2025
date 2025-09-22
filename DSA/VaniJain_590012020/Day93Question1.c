#include <stdio.h>
int max(int a, int b) 
{
    return (a > b) ? a : b;
}
int main() 
{
    int N;
    printf("Enter number of houses: ");
    scanf("%d", &N);
    if (N == 0) 
    {
        printf("Maximum loot = 0\n");
        return 0;
    }
    int houses[N];
    printf("Enter house values:\n");
    for (int i = 0; i < N; i++) 
    {
        scanf("%d", &houses[i]);
    }
    if (N == 1) 
    {
        printf("Maximum loot = %d\n", houses[0]);
        return 0;
    }
    int dp[N];
    dp[0] = houses[0];
    dp[1] = max(houses[0], houses[1]);
    for (int i = 2; i < N; i++) 
    {
        dp[i] = max(dp[i-1], houses[i] + dp[i-2]);
    }
    printf("Maximum loot = %d\n", dp[N-1]);
    return 0;
}
