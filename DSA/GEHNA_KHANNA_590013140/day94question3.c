#include <stdio.h>
#include <string.h>

int min(int a, int b) { return a < b ? a : b; }

int minDistance(char* w1, char* w2) {
    int n = strlen(w1), m = strlen(w2);
    int dp[n+1][m+1];
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (w1[i-1] == w2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        }
    }
    return dp[n][m];
}

int main() {
    char w1[1001], w2[1001];
    scanf("%s %s", w1, w2);
    printf("%d\n", minDistance(w1, w2));
    return 0;
}
