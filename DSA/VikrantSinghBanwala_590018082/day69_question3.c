#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

int lengthOfLongestSubstring(char* s) {
    int charIndex[MAX_CHAR] = {-1};
    int maxLength = 0;
    int start = 0; 

    for (int i = 0; s[i] != '\0'; i++) {
        if (charIndex[s[i]] >= start) {
            start = charIndex[s[i]] + 1; 
        }
        charIndex[s[i]] = i; 
        maxLength = (i - start + 1 > maxLength) ? (i - start + 1) : maxLength;
    }

    return maxLength;
}

int main() {
    char str1[] = "abcabcbb";
    printf("%d\n", lengthOfLongestSubstring(str1));

    char str2[] = "bbbbb";
    printf("%d\n", lengthOfLongestSubstring(str2));

    return 0;
}
