#include <stdio.h>

#define ROW 3
#define COL 3

int min(int a, int b) {
    return (a < b) ? a : b;
}

int minPathSum(int grid[ROW][COL], int m, int n) {
    int dp[m][n];

    dp[0][0] = grid[0][0];

    // First row
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    // First column
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    // Fill rest
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[m-1][n-1];
}

int main() {
    int grid1[ROW][COL] = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    printf("Minimum Path Sum: %d\n", minPathSum(grid1, ROW, COL));

    int grid2[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    printf("Minimum Path Sum: %d\n", minPathSum(grid2, 2, 3));

    return 0;
}

