#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int n = strlen(s);
    int index[256];
    for (int i = 0; i < 256; i++) index[i] = -1;
    int maxLen = 0, start = 0;
    for (int i = 0; i < n; i++) {
        if (index[(unsigned char)s[i]] >= start) start = index[(unsigned char)s[i]] + 1;
        index[(unsigned char)s[i]] = i;
        if (i - start + 1 > maxLen) maxLen = i - start + 1;
    }
    return maxLen;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%99s", str);
    printf("Length of longest substring without repeating characters: %d\n", lengthOfLongestSubstring(str));
    return 0;
}
