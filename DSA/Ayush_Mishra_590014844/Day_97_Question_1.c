#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 999

int minCut(char *s) {
    int n = strlen(s);
    bool isPal[MAX][MAX] = {false};
    int cuts[MAX];

    for (int i = 0; i < n; i++) {
        isPal[i][i] = true;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (len == 2) {
                    isPal[i][j] = true;
                } else {
                    isPal[i][j] = isPal[i + 1][j - 1];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (isPal[0][i]) {
            cuts[i] = 0;
        } else {
            cuts[i] = i;
            for (int j = 1; j <= i; j++) {
                if (isPal[j][i] && cuts[j - 1] + 1 < cuts[i]) {
                    cuts[i] = cuts[j - 1] + 1;
                }
            }
        }
    }

    return cuts[n - 1];
}

int main() {
    char s[MAX];
    printf("Enter the string: ");
    scanf("%s", s);
    int result = minCut(s);
    printf("Minimum cuts needed: %d\n", result);
    return 0;
}
