#include <stdio.h>
#include <string.h>

int min(int a, int b) { return (a < b) ? a : b; }
int min3(int a, int b, int c) { return min(min(a, b), c); }

// Function to compute Edit Distance
int editDistance(char* word1, char* word2) {
    int m = strlen(word1), n = strlen(word2);
    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++) dp[i][0] = i; // deletions
    for (int j = 0; j <= n; j++) dp[0][j] = j; // insertions

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min3(dp[i-1][j],   // delete
                                    dp[i][j-1],   // insert
                                    dp[i-1][j-1]);// replace
        }
    }
    return dp[m][n];
}

int main() {
    char word1[] = "horse";
    char word2[] = "ros";
    printf("Edit Distance = %d\n", editDistance(word1, word2)); // Output: 3

    char word3[] = "intention";
    char word4[] = "execution";
    printf("Edit Distance = %d\n", editDistance(word3, word4)); // Output: 5
    return 0;
}

