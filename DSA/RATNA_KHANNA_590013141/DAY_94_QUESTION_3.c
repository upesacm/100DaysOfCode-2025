#include <stdio.h>
#include <string.h>

// Minimum of three numbers
int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

// Function to compute Edit Distance (Levenshtein) using DP
int editDistance(char *word1, char *word2) {
    int n = strlen(word1);
    int m = strlen(word2);

    int dp[n + 1][m + 1];

    // Initialize base cases
    for (int i = 0; i <= n; i++) dp[i][0] = i;  // delete all
    for (int j = 0; j <= m; j++) dp[0][j] = j;  // insert all

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // characters match
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j],     // delete
                                   dp[i][j - 1],     // insert
                                   dp[i - 1][j - 1]  // replace
                                   );
            }
        }
    }

    // Print DP table
    printf("\nDP Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    return dp[n][m]; // minimum operations
}

int main() {
    char word1[100], word2[100];

    printf("Enter first word: ");
    scanf("%s", word1);

    printf("Enter second word: ");
    scanf("%s", word2);

    int result = editDistance(word1, word2);

    printf("\nMinimum Edit Distance: %d\n", result);

    return 0;
}
