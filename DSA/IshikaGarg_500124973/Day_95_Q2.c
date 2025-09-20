#include <stdio.h>

#define M 3
#define N 3

int uniquePathsWithObstacles(int grid[M][N], int m, int n) {
    int dp[m][n];

    if (grid[0][0] == 1) return 0; // starting cell blocked
    dp[0][0] = 1;

    // Fill first column
    for (int i = 1; i < m; i++) {
        dp[i][0] = (grid[i][0] == 0 && dp[i-1][0] == 1) ? 1 : 0;
    }

    // Fill first row
    for (int j = 1; j < n; j++) {
        dp[0][j] = (grid[0][j] == 0 && dp[0][j-1] == 1) ? 1 : 0;
    }

    // Fill the rest
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == 1) {
                dp[i][j] = 0; // obstacle
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    return dp[m-1][n-1];
}

int main() {
    int grid1[M][N] = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    printf("Unique paths with obstacles: %d\n", uniquePathsWithObstacles(grid1, M, N));

    int grid2[2][2] = {
        {0,1},
        {0,0}
    };
    printf("Unique paths with obstacles: %d\n", uniquePathsWithObstacles(grid2, 2, 2));

    return 0;
}

