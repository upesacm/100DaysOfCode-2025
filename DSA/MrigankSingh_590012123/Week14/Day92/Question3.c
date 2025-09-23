#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int minCostClimbingStairs(int* cost, int n) {
    // Dynamically allocate array for DP
    int *dp = (int *)malloc((n + 1) * sizeof(int));
    if (dp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    // Base cases: can start from step 0 or 1 with no initial cost
    dp[0] = 0;
    dp[1] = 0;
    
    // Bottom-up DP
    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
    }
    
    int result = dp[n];
    free(dp); // Free allocated memory
    return result;
}

int main() {
    int n;
    printf("Enter the number of steps N: ");
    scanf("%d", &n);
    
    if (n < 2) {
        printf("Please enter a number greater than or equal to 2.\n");
        return 1;
    }
    
    // Dynamically allocate array for costs
    int *cost = (int *)malloc(n * sizeof(int));
    if (cost == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Enter the cost for each step:\n");
    for (int i = 0; i < n; i++) {
        printf("Cost for step %d: ", i);
        scanf("%d", &cost[i]);
    }
    
    int result = minCostClimbingStairs(cost, n);
    printf("%d\n", result);
    
    free(cost); // Free allocated memory
    return 0;
}
