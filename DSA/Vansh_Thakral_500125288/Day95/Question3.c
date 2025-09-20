#include <stdio.h>
#include <limits.h>

int minPathSum(int grid[3][3], int m, int n) {
    int dp[m][n];
    dp[0][0] = grid[0][0];

    // First row
    for (int j = 1; j < n; j++)
        dp[0][j] = grid[0][j] + dp[0][j-1];

    // First column
    for (int i = 1; i < m; i++)
        dp[i][0] = grid[i][0] + dp[i-1][0];

    // Fill remaining cells
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++) {
            int minPrev = dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
            dp[i][j] = grid[i][j] + minPrev;
        }

    return dp[m-1][n-1];
}

int main() {
    int grid1[3][3] = {{1,3,1},{1,5,1},{4,2,1}};
    int grid2[2][3] = {{1,2,3},{4,5,6}};
    printf("%d\n", minPathSum(grid1, 3, 3)); // Output: 7
    printf("%d\n", minPathSum(grid2, 2, 3)); // Output: 12
    return 0;
}
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
