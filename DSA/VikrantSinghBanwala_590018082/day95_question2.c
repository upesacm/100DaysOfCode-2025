#include <stdio.h>

int uniquePathsWithObstacles(int m, int n, int grid[m][n]) {
    int dp[m][n];

    
    if (grid[0][0] == 1) return 0;

    
    dp[0][0] = 1;

    
    for (int j = 1; j < n; j++) {
        dp[0][j] = (grid[0][j] == 0 && dp[0][j - 1] == 1) ? 1 : 0;
    }


    for (int i = 1; i < m; i++) {
        dp[i][0] = (grid[i][0] == 0 && dp[i - 1][0] == 1) ? 1 : 0;
    }

    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == 1) {
                dp[i][j] = 0; 
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    
    printf("\nDP Grid (number of ways to reach each cell):\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", dp[i][j]);
        }
        printf("\n");
    }

    return dp[m - 1][n - 1];
}

int main() {
    int m, n;
    printf("Enter grid dimensions (rows m and columns n): ");
    scanf("%d %d", &m, &n);

    int grid[m][n];
    printf("Enter the grid (0 = free, 1 = obstacle):\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = uniquePathsWithObstacles(m, n, grid);

    printf("\nTotal unique paths avoiding obstacles: %d\n", result);

    return 0;
}