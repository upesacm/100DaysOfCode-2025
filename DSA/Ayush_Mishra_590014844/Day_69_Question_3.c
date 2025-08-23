#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int lastIndex[256], i, start = 0, maxLen = 0;
    for (i = 0; i < 256; i++)
        lastIndex[i] = -1;
    for (i = 0; s[i]; i++) {
        if (lastIndex[(int)s[i]] >= start)
            start = lastIndex[(int)s[i]] + 1;
        lastIndex[(int)s[i]] = i;
        if (i - start + 1 > maxLen)
            maxLen = i - start + 1;
    }
    return maxLen;
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    scanf("%s", str);
    int result = lengthOfLongestSubstring(str);
    printf("%d\n", result);
    return 0;
}
