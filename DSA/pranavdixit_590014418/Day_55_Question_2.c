#include <stdio.h>
#include <string.h>

int longestUniqueSubstring(char* s) {
    int lastIndex[256];
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;

    int maxLen = 0, start = 0;
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        if (lastIndex[(unsigned char)s[i]] >= start)
            start = lastIndex[(unsigned char)s[i]] + 1;

        lastIndex[(unsigned char)s[i]] = i;
        if (i - start + 1 > maxLen)
            maxLen = i - start + 1;
    }

    return maxLen;
}

int main() {
    char s[] = "abcabcbb";
    printf("Longest unique substring length: %d\n", longestUniqueSubstring(s)); // Output: 3
    return 0;
}
