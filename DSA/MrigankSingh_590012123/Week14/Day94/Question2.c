#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int lengthOfLCS(char* str1, char* str2, int m, int n) {
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
    for (int i = 0; i <= m; i++) dp[i][0] = 0;
    for (int j = 0; j <= n; j++) dp[0][j] = 0;

    // Bottom-up DP
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
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
    char str1[1000], str2[1000];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    int m = strlen(str1);
    int n = strlen(str2);

    int result = lengthOfLCS(str1, str2, m, n);
    printf("%d\n", result);

    return 0;
}
