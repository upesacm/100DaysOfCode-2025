#include <stdio.h>
#include <string.h>

int longestUniqueSubstring(char *s) {
    int n = strlen(s), start = 0, maxLen = 0, lastIndex[256];
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;
    for (int end = 0; end < n; end++) {
        if (lastIndex[(unsigned char)s[end]] >= start)
            start = lastIndex[(unsigned char)s[end]] + 1;
        lastIndex[(unsigned char)s[end]] = end;
        if (end - start + 1 > maxLen)
            maxLen = end - start + 1;
    }
    return maxLen;
}

int main() {
    char s[1000];
    scanf("%s", s);
    printf("%d\n", longestUniqueSubstring(s));
    return 0;
}
