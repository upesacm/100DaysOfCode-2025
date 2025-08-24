#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;
    
    int seen[128];
    for (int i = 0; i < 128; i++) {
        seen[i] = -1;
    }
    
    int maxLen = 0;
    int start = 0;
    
    for (int end = 0; end < n; end++) {
        if (seen[s[end]] >= start) {
            start = seen[s[end]] + 1;
        }
        seen[s[end]] = end;
        int currentLen = end - start + 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }
    
    return maxLen;
}

int main() {
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);
    printf("Longest substring without repeating: %d\n", lengthOfLongestSubstring(s));
    return 0;
}
