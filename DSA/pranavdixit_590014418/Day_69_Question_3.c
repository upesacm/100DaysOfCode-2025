#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int lastIndex[256];
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;

    int start = 0, maxLen = 0;
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
    char s1[] = "abcabcbb";
    printf("Longest unique substring length: %d\n", lengthOfLongestSubstring(s1)); // 3

    char s2[] = "bbbbb";
    printf("Longest unique substring length: %d\n", lengthOfLongestSubstring(s2)); // 1
    return 0;
}
