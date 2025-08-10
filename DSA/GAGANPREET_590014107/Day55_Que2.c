#include <stdio.h>
#include <string.h>

#define CHAR_RANGE 256  

void longestUniqueSubstring(char* str) {
    int n = strlen(str);
    int lastIndex[CHAR_RANGE];
    for (int i = 0; i < CHAR_RANGE; i++) {
        lastIndex[i] = -1;
    }

    int maxLen = 0;
    int start = 0;
    int maxStart = 0;

    for (int i = 0; i < n; i++) {
        char ch = str[i];

        
        if (lastIndex[(int)ch] >= start) {
            start = lastIndex[(int)ch] + 1;
        }

        lastIndex[(int)ch] = i;

        int windowLen = i - start + 1;
        if (windowLen > maxLen) {
            maxLen = windowLen;
            maxStart = start;
        }
    }

    printf("Length of longest unique substring: %d\n", maxLen);
    printf("Longest unique substring: ");
    for (int i = maxStart; i < maxStart + maxLen; i++) {
        putchar(str[i]);
    }
    printf("\n");
}

int main() {
    
    char str1[] = "abcabcbb";
    printf("Input: \"%s\"\n", str1);
    longestUniqueSubstring(str1);  

    
    char str2[] = "bbbbb";
    printf("\nInput: \"%s\"\n", str2);
    longestUniqueSubstring(str2);

    
    char str3[] = "pwwkew";
    printf("\nInput: \"%s\"\n", str3);
    longestUniqueSubstring(str3);  

    return 0;
}
