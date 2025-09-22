#include <stdio.h>
#include <string.h>

// Utility function to get minimum of three numbers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to compute Edit Distance using DP
int minDistance(char *word1, char *word2) {
    int m = strlen(word1);
    int n = strlen(word2);

    int dp[m + 1][n + 1];

    // Initialize base cases
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j],    // delete
                                   dp[i][j - 1],    // insert
                                   dp[i - 1][j - 1] // replace
                );
        }
    }

    return dp[m][n];
}

int main() {
    char w1[] = "horse";
    char w2[] = "ros";
    printf("Edit Distance: %d\n", minDistance(w1, w2)); // Output: 3

    char w3[] = "intention";
    char w4[] = "execution";
    printf("Edit Distance: %d\n", minDistance(w3, w4)); // Output: 5

    return 0;
}
