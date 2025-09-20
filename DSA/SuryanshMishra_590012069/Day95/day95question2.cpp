#include <vector>
#include <cstddef>

using namespace std;

// Unique paths with obstacles (2D DP)
int uniquePathsWithObstacles(const vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = m ? obstacleGrid[0].size() : 0;
    if (m == 0 || n == 0) return 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = obstacleGrid[0][0] ? 0 : 1;
    for (int i = 1; i < m; ++i) dp[i][0] = obstacleGrid[i][0] ? 0 : dp[i-1][0];
    for (int j = 1; j < n; ++j) dp[0][j] = obstacleGrid[0][j] ? 0 : dp[0][j-1];
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j]) dp[i][j] = 0;
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}
