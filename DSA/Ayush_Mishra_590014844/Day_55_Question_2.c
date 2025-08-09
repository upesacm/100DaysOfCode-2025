#include <stdio.h>
#include <string.h>

int longestUniqueSubstring(char* s) {
    int lastIndex[256];
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;
    int maxLen = 0, start = 0;
    for (int i = 0; s[i]; i++) {
        if (lastIndex[(int)s[i]] >= start)
            start = lastIndex[(int)s[i]] + 1;
        lastIndex[(int)s[i]] = i;
        if (i - start + 1 > maxLen)
            maxLen = i - start + 1;
    }
    return maxLen;
}

int main() {
    char s[1000];
    printf("Enter the string: ");
    scanf("%s", s);
    int result = longestUniqueSubstring(s);
    printf("Length of longest substring with all distinct characters: %d\n", result);
    return 0;
}
