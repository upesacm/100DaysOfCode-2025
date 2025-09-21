#include <stdio.h>
int min(int a, int b) 
{
    return (a < b) ? a : b;
}
int main() 
{
    int N;
    printf("Enter number of steps: ");
    scanf("%d", &N);
    int cost[N];
    printf("Enter cost of each step:\n");
    for (int i = 0; i < N; i++) 
    {
        scanf("%d", &cost[i]);
    }
    if (N == 0) 
    {
        printf("Minimum cost to reach top = 0\n");
        return 0;
    }
    if (N == 1) 
    {
        printf("Minimum cost to reach top = %d\n", cost[0]);
        return 0;
    }
    int dp[N];
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < N; i++) 
    {
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }
    int minCost = min(dp[N-1], dp[N-2]);
    printf("Minimum cost to reach top = %d\n", minCost);
    return 0;
}
