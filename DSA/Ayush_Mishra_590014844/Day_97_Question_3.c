#include <stdio.h>

#define MAX 100

int min(int a, int b) {
    return a < b ? a : b;
}

int matrixChainOrder(int dims[], int n) {
    int dp[MAX][MAX] = {0};

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = 1e9;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int n;
    int dims[MAX];
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    printf("Enter %d dimensions: ", n + 1);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &dims[i]);
    }
    int result = matrixChainOrder(dims, n + 1);
    printf("Minimum number of scalar multiplications: %d\n", result);
    return 0;
}
