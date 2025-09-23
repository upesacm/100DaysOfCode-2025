#include <stdio.h>
#include <stdlib.h>

long long uniquePaths(int m, int n) {
    // Dynamically allocate 2D DP array
    long long **dp = (long long **)malloc(m * sizeof(long long *));
    if (dp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < m; i++) {
        dp[i] = (long long *)malloc(n * sizeof(long long));
        if (dp[i] == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    // Initialize first row and column
    for (int i = 0; i < m; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;

    // Bottom-up DP
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    long long result = dp[m-1][n-1];

    // Free allocated memory
    for (int i = 0; i < m; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    int m, n;
    printf("Enter the number of rows (m): ");
    scanf("%d", &m);
    printf("Enter the number of columns (n): ");
    scanf("%d", &n);

    if (m <= 0 || n <= 0) {
        printf("Please enter positive integers for dimensions.\n");
        return 1;
    }

    long long result = uniquePaths(m, n);
    printf("%lld\n", result);

    return 0;
}
