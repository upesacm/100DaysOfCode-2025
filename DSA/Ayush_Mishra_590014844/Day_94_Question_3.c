#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int main() {
    char s1[1001], s2[1001];
    scanf("%s %s", s1, s2);
    int m = strlen(s1), n = strlen(s2);
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
        }

    printf("%d\n", dp[m][n]);
    return 0;
}
