#include <stdio.h>
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
            if (grid[i][j] == 1) 
            {
                dp[i][j] = 0; 
            } 
            else if (i == 0 && j == 0) 
            {
                dp[i][j] = 1; 
            } 
            else if (i == 0)   
            {
                dp[i][j] = dp[i][j-1];
            } 
            else if (j == 0) 
            {
                dp[i][j] = dp[i-1][j];
            }
            else 
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    printf("Number of unique paths avoiding obstacles = %d\n", dp[m-1][n-1]);
    return 0;
}
