#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;
    scanf("%d", &n);
    int weights[n], values[n];
    for (int i = 0; i < n; i++) scanf("%d", &weights[i]);
    for (int i = 0; i < n; i++) scanf("%d", &values[i]);
    scanf("%d", &W);

    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("%d\n", dp[n][W]);
    return 0;
}
