#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int knapsack(int* weights, int* values, int n, int W) {
    // Dynamically allocate 2D DP array
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    if (dp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((W + 1) * sizeof(int));
        if (dp[i] == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    // Initialize first row (no items)
    for (int w = 0; w <= W; w++) {
        dp[0][w] = 0;
    }

    // Bottom-up DP
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - weights[i-1]] + values[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    int result = dp[n][W];

    // Free allocated memory
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the knapsack capacity (W): ");
    scanf("%d", &W);

    if (n < 0 || W < 0) {
        printf("Please enter non-negative integers.\n");
        return 1;
    }

    // Dynamically allocate arrays for weights and values
    int *weights = (int *)malloc(n * sizeof(int));
    int *values = (int *)malloc(n * sizeof(int));
    if (weights == NULL || values == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    if (n > 0) {
        printf("Enter the weights of the items:\n");
        for (int i = 0; i < n; i++) {
            printf("Weight for item %d: ", i);
            scanf("%d", &weights[i]);
            if (weights[i] < 0) {
                printf("Please enter non-negative weights.\n");
                free(weights);
                free(values);
                return 1;
            }
        }
        printf("Enter the values of the items:\n");
        for (int i = 0; i < n; i++) {
            printf("Value for item %d: ", i);
            scanf("%d", &values[i]);
            if (values[i] < 0) {
                printf("Please enter non-negative values.\n");
                free(weights);
                free(values);
                return 1;
            }
        }
    }

    int result = knapsack(weights, n, W);
    printf("%d\n", result);

    free(weights);
    free(values);
    return 0;
}
