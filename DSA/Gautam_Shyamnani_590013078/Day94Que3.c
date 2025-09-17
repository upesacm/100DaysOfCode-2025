#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int editDistance(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);
    int dp[m + 1][n + 1];

    // Initialize base cases
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;  // Delete all characters from word1

    for (int j = 0; j <= n; j++)
        dp[0][j] = j;  // Insert all characters into word1

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];  // No operation needed
            else
                dp[i][j] = 1 + min(
                    dp[i - 1][j],     // Delete
                    dp[i][j - 1],     // Insert
                    dp[i - 1][j - 1]  // Replace
                );
        }
    }

    return dp[m][n];  // Final cell contains minimum edit distance
}

int main() {
    char word1[] = "horse";
    char word2[] = "ros";
    printf("Edit Distance: %d\n", editDistance(word1, word2));  // Output: 3

    char word3[] = "intention";
    char word4[] = "execution";
    printf("Edit Distance: %d\n", editDistance(word3, word4));  // Output: 5

    return 0;
}
