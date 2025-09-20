#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int minCutsPalindromePartition(char *s) {
    int n = strlen(s);
    bool isPal[n][n];
    int cuts[n];

    // Step 1: Precompute palindrome table
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            isPal[i][j] = false;

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (len <= 2) isPal[i][j] = true;
                else isPal[i][j] = isPal[i + 1][j - 1];
            }
        }
    }

    // Step 2: DP for minimum cuts
    for (int i = 0; i < n; i++) {
        if (isPal[0][i]) {
            cuts[i] = 0; // no cut needed
        } else {
            cuts[i] = INT_MAX;
            for (int j = 0; j < i; j++) {
                if (isPal[j + 1][i] && cuts[j] + 1 < cuts[i])
                    cuts[i] = cuts[j] + 1;
            }
        }
    }
    return cuts[n - 1];
}

int main() {
    char s1[] = "aab";
    printf("Minimum cuts for \"%s\": %d\n", s1, minCutsPalindromePartition(s1)); // 1

    char s2[] = "a";
    printf("Minimum cuts for \"%s\": %d\n", s2, minCutsPalindromePartition(s2)); // 0
    return 0;
}

