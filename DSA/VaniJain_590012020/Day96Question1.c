#include <stdio.h>
int max(int a, int b) 
{
    return (a > b) ? a : b;
}
int knapSack(int W, int wt[], int val[], int n) 
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) 
    {
        for (int w = 0; w <= W; w++) 
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], 
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}
int main() 
{
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int val[n], wt[n];
    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val[i]);
    }
    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &wt[i]);
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);
    int result = knapSack(W, wt, val, n);
    printf("Maximum value achievable = %d\n", result);
    return 0;
}
