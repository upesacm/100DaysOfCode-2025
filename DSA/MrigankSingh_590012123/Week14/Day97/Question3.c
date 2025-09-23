#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int matrixChainMultiplication(int* dims, int n) {
    // n is number of matrices + 1 (dimensions)
    int m = n - 1; // Number of matrices
    if (m <= 1) return 0; // Single matrix requires no multiplication

    // Dynamically allocate 2D DP array
    int **dp = (int **)malloc(n * sizeof(int *));
    if (dp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        dp[i] = (int *)malloc(n * sizeof(int));
        if (dp[i] == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    // Initialize diagonal (single matrices)
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    // Fill DP table
    for (int len = 2; len < n; len++) {
        for (int i = 1; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + dims[i-1] * dims[k] * dims[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    int result = dp[1][n-1];

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    int n;
    printf("Enter the number of matrix dimensions: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Please enter at least 2 dimensions for matrix chain.\n");
        return 1;
    }

    // Dynamically allocate array for dimensions
    int *dims = (int *)malloc(n * sizeof(int));
    if (dims == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the dimensions (e.g., for A(10x20) B(20x30), enter 10 20 30):\n");
    for (int i = 0; i < n; i++) {
        printf("Dimension %d: ", i);
        scanf("%d", &dims[i]);
        if (dims[i] <= 0) {
            printf("Please enter positive integers for dimensions.\n");
            free(dims);
            return 1;
        }
    }

    int result = matrixChainMultiplication(dims, n);
    printf("%d\n", result);

    free(dims);
    return 0;
}
