#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int lastIndex[256];  // store last seen index of characters
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;

    int maxLen = 0, left = 0;
    for (int right = 0; s[right]; right++) {
        if (lastIndex[(unsigned char)s[right]] >= left) {
            left = lastIndex[(unsigned char)s[right]] + 1;
        }
        lastIndex[(unsigned char)s[right]] = right;
        int currLen = right - left + 1;
        if (currLen > maxLen) maxLen = currLen;
    }
    return maxLen;
}

int main() {
    char s1[] = "abcabcbb";
    char s2[] = "bbbbb";

    printf("%s -> %d\n", s1, lengthOfLongestSubstring(s1));
    printf("%s -> %d\n", s2, lengthOfLongestSubstring(s2));

    return 0;
}

