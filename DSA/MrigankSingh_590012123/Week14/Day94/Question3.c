#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int editDistance(char* word1, char* word2, int m, int n) {
    // Dynamically allocate 2D DP array
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    if (dp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i <= m; i++) {
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
        if (dp[i] == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    // Initialize first row and column
    for (int i = 0; i <= m; i++) dp[i][0] = i; // Delete i characters
    for (int j = 0; j <= n; j++) dp[0][j] = j; // Insert j characters

    // Bottom-up DP
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1]; // No operation needed
            } else {
                dp[i][j] = min(dp[i-1][j-1] + 1, // Replace
                              dp[i-1][j] + 1,   // Delete
                              dp[i][j-1] + 1);  // Insert
            }
        }
    }

    int result = dp[m][n];

    // Free allocated memory
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    char word1[1000], word2[1000];
    printf("Enter the first word: ");
    scanf("%s", word1);
    printf("Enter the second word: ");
    scanf("%s", word2);

    int m = strlen(word1);
    int n = strlen(word2);

    int result = editDistance(word1, word2, m, n);
    printf("%d\n", result);

    return 0;
}
