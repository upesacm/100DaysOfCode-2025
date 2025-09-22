#include <stdio.h>

int uniquePathsWithObstacles(int grid[3][3], int m, int n) {
    int dp[m][n];

    if (grid[0][0] == 1) return 0;
    dp[0][0] = 1;

    // Fill first column
    for (int i = 1; i < m; i++)
        dp[i][0] = (grid[i][0] == 0 && dp[i-1][0] == 1) ? 1 : 0;

    // Fill first row
    for (int j = 1; j < n; j++)
        dp[0][j] = (grid[0][j] == 0 && dp[0][j-1] == 1) ? 1 : 0;

    // Fill remaining cells
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int main() {
    int grid1[3][3] = {{0,0,0},{0,1,0},{0,0,0}};
    int grid2[2][2] = {{0,1},{0,0}};
    printf("%d\n", uniquePathsWithObstacles(grid1, 3, 3)); // Output: 2
    printf("%d\n", uniquePathsWithObstacles(grid2, 2, 2)); // Output: 1
    return 0;
}

// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
