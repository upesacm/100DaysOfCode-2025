#include <stdio.h>

// Function to compute unique paths using DP
int uniquePaths(int m, int n) {
    int dp[m][n];

    // Initialize first row and first column as 1
    for (int i = 0; i < m; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;

    // Fill DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    printf("Unique Paths (3x7): %d\n", uniquePaths(3, 7)); // Output: 28
    printf("Unique Paths (3x2): %d\n", uniquePaths(3, 2)); // Output: 3
    return 0;
}
