#include <stdio.h>
#include <string.h>
#include <limits.h>

int minCut(char* s) {
    int n = strlen(s);
    int isPal[n][n];
    int cuts[n];

    for (int i = 0; i < n; i++) {
        isPal[i][i] = 1;
        for (int j = i+1; j < n; j++) isPal[i][j] = 0;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n-len; i++) {
            int j = i+len-1;
            if (s[i] == s[j]) {
                if (len == 2) isPal[i][j] = 1;
                else isPal[i][j] = isPal[i+1][j-1];
            } else isPal[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (isPal[0][i]) cuts[i] = 0;
        else {
            cuts[i] = INT_MAX;
            for (int j = 0; j < i; j++) {
                if (isPal[j+1][i] && cuts[j]+1 < cuts[i]) {
                    cuts[i] = cuts[j]+1;
                }
            }
        }
    }
    return cuts[n-1];
}

int main() {
    char s[] = "aab";
    printf("%d\n", minCut(s));
    return 0;
}
