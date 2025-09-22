#include <stdio.h>
#include <limits.h>
int matrixChainOrder(int p[], int n) 
{
    int dp[n][n];  
    for (int i = 1; i < n; i++) 
    {
        dp[i][i] = 0;
    }
    for (int l = 2; l < n; l++) 
    {
        for (int i = 1; i < n - l + 1; i++) 
        {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) 
            {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) 
                {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[1][n - 1]; 
}
int main() 
{
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    int p[n + 1];
    printf("Enter dimensions array (size %d):\n", n + 1);
    for (int i = 0; i <= n; i++) 
    {
        scanf("%d", &p[i]);
    }
    int result = matrixChainOrder(p, n + 1);
    printf("Minimum number of scalar multiplications = %d\n", result);
    return 0;
}
