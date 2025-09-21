#include <stdio.h>
int min(int a, int b) 
{
    return (a < b) ? a : b;
}
int main() 
{
    int m, n;
    printf("Enter number of rows (m): ");
    scanf("%d", &m);
    printf("Enter number of columns (n): ");
    scanf("%d", &n);
    if (m <= 0 || n <= 0) 
    {
        printf("Invalid grid size.\n");
        return 0;
    }
    int grid[m][n];
    printf("Enter grid values (positive integers):\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &grid[i][j]);
    int dp[m][n];
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j]; 
            else if (i == 0)
                dp[i][j] = grid[i][j] + dp[i][j-1]; 
            else if (j == 0)
                dp[i][j] = grid[i][j] + dp[i-1][j]; 
            else
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    printf("Minimum path sum from top-left to bottom-right = %d\n", dp[m-1][n-1]);
    return 0;
}
