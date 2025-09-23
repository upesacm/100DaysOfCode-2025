#include <stdio.h>
#include <stdlib.h>

long long fibonacci(int n) {
    if (n < 0) return 0;
    
    // Dynamically allocate array for DP
    long long *dp = (long long *)malloc((n + 1) * sizeof(long long));
    if (dp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    // Base cases
    dp[0] = 0;
    if (n >= 1) dp[1] = 1;
    
    // Bottom-up DP
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    long long result = dp[n];
    free(dp); // Free allocated memory
    return result;
}

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }
    
    long long result = fibonacci(n);
    printf("%lld\n", result);
    
    return 0;
}
