#include <stdio.h>
#include <string.h>

int longestUniqueSubstring(char *str) {
    int lastIndex[256];
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;

    int max_len = 0, start = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (lastIndex[(unsigned char)str[i]] >= start) {
            start = lastIndex[(unsigned char)str[i]] + 1;
        }
        lastIndex[(unsigned char)str[i]] = i;
        if (i - start + 1 > max_len)
            max_len = i - start + 1;
    }

    return max_len;
}

int main() {
    char str[] = "abcabcbb";
    printf("Longest Unique Substring Length = %d\n", longestUniqueSubstring(str));
    return 0;
}

