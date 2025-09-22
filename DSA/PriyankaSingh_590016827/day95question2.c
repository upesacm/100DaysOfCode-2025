#include <stdio.h>

// Function to compute unique paths with obstacles
int uniquePathsWithObstacles(int grid[100][100], int m, int n) {
    int dp[m][n];

    // If starting cell has obstacle → 0 ways
    if (grid[0][0] == 1) return 0;
    dp[0][0] = 1;

    // First column
    for (int i = 1; i < m; i++) {
        dp[i][0] = (grid[i][0] == 0 && dp[i - 1][0] == 1) ? 1 : 0;
    }

    // First row
    for (int j = 1; j < n; j++) {
        dp[0][j] = (grid[0][j] == 0 && dp[0][j - 1] == 1) ? 1 : 0;
    }

    // Fill DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == 1) {
                dp[i][j] = 0; // obstacle blocks path
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    int grid1[100][100] = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    printf("Unique Paths with Obstacles: %d\n", uniquePathsWithObstacles(grid1, 3, 3)); // Output: 2

    int grid2[100][100] = {
        {0,1},
        {0,0}
    };
    printf("Unique Paths with Obstacles: %d\n", uniquePathsWithObstacles(grid2, 2, 2)); // Output: 1

    return 0;
}
