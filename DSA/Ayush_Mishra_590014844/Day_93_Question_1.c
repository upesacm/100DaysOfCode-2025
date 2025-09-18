#include <stdio.h>

int maxRobbery(int* houses, int n) {
    if (n == 0) return 0;
    if (n == 1) return houses[0];

    int dp[n];
    dp[0] = houses[0];
    dp[1] = houses[0] > houses[1] ? houses[0] : houses[1];

    for (int i = 2; i < n; i++) {
        int rob = houses[i] + dp[i - 2];
        int skip = dp[i - 1];
        dp[i] = rob > skip ? rob : skip;
    }
    return dp[n - 1];
}

int main() {
    int n;
    printf("Enter number of houses: ");
    scanf("%d", &n);

    int houses[n];
    printf("Enter house values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &houses[i]);
    }

    int result = maxRobbery(houses, n);
    printf("Maximum robbery amount: %d\n", result);
    return 0;
}
