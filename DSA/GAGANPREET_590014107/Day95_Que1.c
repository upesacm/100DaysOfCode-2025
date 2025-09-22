#include <stdio.h>


int uniquePaths(int m, int n) {
    int dp[m][n];

    
    for (int i = 0; i < m; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;

    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; 
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

    int result = uniquePaths(m, n);

    printf("\nTotal unique paths in a %dx%d grid: %d\n", m, n, result);

    return 0;
}
