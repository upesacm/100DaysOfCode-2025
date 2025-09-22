#include <stdio.h>
#include <string.h>
#include <limits.h>

int minCuts(char *s) {
    int n = strlen(s);
    int cuts[n];
    int pal[n][n];

    for (int i = 0; i < n; i++) {
        cuts[i] = i;
        for (int j = 0; j < n; j++) pal[i][j] = 0;
    }

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && (len <= 2 || pal[i+1][j-1])) {
                pal[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (pal[0][i]) {
            cuts[i] = 0;
        } else {
            for (int j = 0; j < i; j++) {
                if (pal[j+1][i] && cuts[j] + 1 < cuts[i]) {
                    cuts[i] = cuts[j] + 1;
                }
            }
        }
    }

    return cuts[n-1];
}

int main() {
    char s[1000];
    scanf("%s", s);
    printf("%d\n", minCuts(s));
    return 0;
}
