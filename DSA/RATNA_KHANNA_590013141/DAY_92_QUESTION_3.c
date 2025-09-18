#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of steps: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Number of steps must be positive.\n");
        return 0;
    }

    int cost[n];
    printf("Enter the cost array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &cost[i]);
    }

    if (n == 1) {
        printf("Minimum cost to reach the top is: %d\n", cost[0]);
        return 0;
    }

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 0;

    for (i = 2; i <= n; i++) {
        int takeOne = dp[i - 1] + cost[i - 1];
        int takeTwo = dp[i - 2] + cost[i - 2];
        dp[i] = takeOne < takeTwo ? takeOne : takeTwo;
    }

    printf("Minimum cost to reach the top is: %d\n", dp[n]);
    return 0;
}
