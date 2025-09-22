#include <stdio.h>

// 1. Unique Paths in Grid (without obstacles)
int uniquePaths(int m, int n) {
    int dp[m][n];

    // Initialize first row and first column
    for (int i = 0; i < m; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;

    // Fill DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

// 2. Unique Paths with Obstacles
int uniquePathsWithObstacles(int m, int n, int grid[m][n]) {
    int dp[m][n];

    // If starting or ending cell is blocked, return 0
    if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return 0;

    dp[0][0] = 1;

    // Fill first row
    for (int j = 1; j < n; j++)
        dp[0][j] = (grid[0][j] == 0 && dp[0][j-1] == 1) ? 1 : 0;

    // Fill first column
    for (int i = 1; i < m; i++)
        dp[i][0] = (grid[i][0] == 0 && dp[i-1][0] == 1) ? 1 : 0;

    // Fill rest of DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == 1)
                dp[i][j] = 0; // obstacle
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}

// 3. Minimum Path Sum
int min(int a, int b) {
    return (a < b) ? a : b;
}

int minPathSum(int m, int n, int grid[m][n]) {
    int dp[m][n];

    dp[0][0] = grid[0][0];

    // Fill first row
    for (int j = 1; j < n; j++)
        dp[0][j] = dp[0][j-1] + grid[0][j];

    // Fill first column
    for (int i = 1; i < m; i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];

    // Fill rest of DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[m-1][n-1];
}

// Main function to test all 3
int main() {
    // 1. Unique Paths Example
    int m1 = 3, n1 = 7;
    printf("Unique Paths in %dx%d grid: %d\n", m1, n1, uniquePaths(m1, n1));

    // 2. Unique Paths with Obstacles Example
    int grid2[3][3] = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    printf("Unique Paths with Obstacles: %d\n", uniquePathsWithObstacles(3, 3, grid2));

    // 3. Minimum Path Sum Example
    int grid3[3][3] = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    printf("Minimum Path Sum: %d\n", minPathSum(3, 3, grid3));

    return 0;
}
