#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 1000

int minCut(char *s) {
    int n = strlen(s);
    bool pal[n][n];
    int cuts[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) pal[i][j] = false;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j] && (j - i <= 2 || pal[i + 1][j - 1])) {
                pal[i][j] = true;
            }
        }
    }

    
    for (int i = 0; i < n; i++) {
        if (pal[0][i]) {
            cuts[i] = 0; 
        } else {
            cuts[i] = INT_MAX;
            for (int j = 0; j < i; j++) {
                if (pal[j + 1][i] && cuts[j] + 1 < cuts[i]) {
                    cuts[i] = cuts[j] + 1;
                }
            }
        }
    }

    return cuts[n - 1];
}

int main() {
    char s1[] = "aab";
    printf("Min cuts for \"%s\": %d\n", s1, minCut(s1)); 

    char s2[] = "a";
    printf("Min cuts for \"%s\": %d\n", s2, minCut(s2)); 

    return 0;
}
