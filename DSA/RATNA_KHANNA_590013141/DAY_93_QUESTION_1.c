#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of houses: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Number of houses must be positive.\n");
        return 0;
    }

    int houses[n];
    printf("Enter the values of houses:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &houses[i]);
    }

    if (n == 1) {
        printf("Maximum loot possible is: %d\n", houses[0]);
        return 0;
    }

    int dp[n];
    dp[0] = houses[0];
    dp[1] = houses[0] > houses[1] ? houses[0] : houses[1];

    for (i = 2; i < n; i++) {
        int rob = houses[i] + dp[i - 2];
        int skip = dp[i - 1];
        dp[i] = rob > skip ? rob : skip;
    }

    printf("Maximum loot possible is: %d\n", dp[n - 1]);
    return 0;
}
