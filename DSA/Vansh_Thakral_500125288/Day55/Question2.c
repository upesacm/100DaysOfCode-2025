#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int lastIndex[256];
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;

    int left = 0, maxLen = 0;
    for (int right = 0; s[right] != '\0'; right++) {
        if (lastIndex[(unsigned char)s[right]] >= left)
            left = lastIndex[(unsigned char)s[right]] + 1;

        lastIndex[(unsigned char)s[right]] = right;

        if (right - left + 1 > maxLen)
            maxLen = right - left + 1;
    }
    return maxLen;
}

int main() {
    char s[] = "abcabcbb";
    printf("%d\n", lengthOfLongestSubstring(s)); 
    return 0;
}

