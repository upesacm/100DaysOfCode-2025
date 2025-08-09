#include <stdio.h>
#include <string.h>

int longestSubstringWithAllDistinctCharacters(char* s) {
    int n = strlen(s);
    int maxLength = 0;
    int start = 0;
    int charIndex[256] = {0};

    for (int end = 0; end < n; end++) {
        if (charIndex[s[end]] > start) {
            start = charIndex[s[end]];
        }
        charIndex[s[end]] = end + 1;
        maxLength = (maxLength > (end - start + 1)) ? maxLength : (end - start + 1);
    }

    return maxLength;
}

int main() {
    char* str1 = "abcabcbb";
    printf("%d\n", longestSubstringWithAllDistinctCharacters(str1));

    char* str2 = "bbbbb";
    printf("%d\n", longestSubstringWithAllDistinctCharacters(str2));

    return 0;
}
