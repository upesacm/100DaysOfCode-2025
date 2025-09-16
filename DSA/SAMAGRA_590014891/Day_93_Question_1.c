#include <stdio.h>

int houseRobber(int houses[], int n) {
    if (n == 0) return 0;
    if (n == 1) return houses[0];

    int dp[n];
    dp[0] = houses[0];
    dp[1] = (houses[0] > houses[1]) ? houses[0] : houses[1];

    for (int i = 2; i < n; i++) {
        int rob = houses[i] + dp[i-2];
        int skip = dp[i-1];
        dp[i] = (rob > skip) ? rob : skip;
    }
    return dp[n-1];
}

int main() {
    int houses1[] = {1, 2, 3, 1};
    int houses2[] = {2, 7, 9, 3, 1};

    printf("Max loot (case 1): %d\n", houseRobber(houses1, 4));
    printf("Max loot (case 2): %d\n", houseRobber(houses2, 5));

    return 0;
}
