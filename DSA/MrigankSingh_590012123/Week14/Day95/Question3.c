#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int minPathSum(int** grid, int m, int n) {
    // Dynamically allocate 2D DP array
    int **dp = (int **)malloc(m * sizeof(int *));
    if (dp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < m; i++) {
        dp[i] = (int *)malloc(n * sizeof(int));
        if (dp[i] == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    // Initialize first cell
    dp[0][0] = grid[0][0];

    // Initialize first row
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    // Initialize first column
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    // Bottom-up DP
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    int result = dp[m-1][n-1];

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

    // Dynamically allocate 2D grid
    int **grid = (int **)malloc(m * sizeof(int *));
    if (grid == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < m; i++) {
        grid[i] = (int *)malloc(n * sizeof(int));
        if (grid[i] == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    printf("Enter the grid values (positive integers):\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Grid[%d][%d]: ", i, j);
            scanf("%d", &grid[i][j]);
            if (grid[i][j] <= 0) {
                printf("Please enter positive integers for grid values.\n");
                for (int k = 0; k <= i; k++) {
                    free(grid[k]);
                }
                free(grid);
                return 1;
            }
        }
    }

    int result = minPathSum(grid, m, n);
    printf("%d\n", result);

    // Free allocated memory
    for (int i = 0; i < m; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
