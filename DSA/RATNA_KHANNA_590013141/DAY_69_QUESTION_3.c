#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int lastIndex[256];
    int i;
    for(i = 0; i < 256; i++) lastIndex[i] = -1;
    int maxLen = 0, start = 0, n = strlen(s);
    for(i = 0; i < n; i++) {
        if(lastIndex[(int)s[i]] >= start) {
            start = lastIndex[(int)s[i]] + 1;
        }
        lastIndex[(int)s[i]] = i;
        if(i - start + 1 > maxLen) maxLen = i - start + 1;
    }
    return maxLen;
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("%d\n", lengthOfLongestSubstring(str));
    return 0;
}
