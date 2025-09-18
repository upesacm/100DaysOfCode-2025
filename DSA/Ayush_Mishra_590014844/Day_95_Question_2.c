#include <stdio.h>
#include <stdlib.h>

int uniquePathsWithObstacles(int **grid, int m, int n) {
    int **dp = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        dp[i] = (int *)calloc(n, sizeof(int));
    }

    if (grid[0][0] == 0) dp[0][0] = 1;

    for (int i = 1; i < m; i++) {
        if (grid[i][0] == 0) dp[i][0] = dp[i - 1][0];
    }

    for (int j = 1; j < n; j++) {
        if (grid[0][j] == 0) dp[0][j] = dp[0][j - 1];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    int result = dp[m - 1][n - 1];
    for (int i = 0; i < m; i++) free(dp[i]);
    free(dp);
    return result;
}

int main() {
    int m, n;
    printf("Enter grid dimensions (rows m and columns n): ");
    scanf("%d %d", &m, &n);

    int **grid = (int **)malloc(m * sizeof(int *));
    printf("Enter grid values (0 for free, 1 for obstacle):\n");
    for (int i = 0; i < m; i++) {
        grid[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Total unique paths avoiding obstacles: %d\n", uniquePathsWithObstacles(grid, m, n));
    for (int i = 0; i < m; i++) free(grid[i]);
    free(grid);
    return 0;
}
