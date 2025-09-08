#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Longest Substring Without Repeating
int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;
    
    int maxLength = 0;
    int left = 0;
    bool charSet[256] = {false};
    
    for (int right = 0; right < n; right++) {
        while (charSet[(int)s[right]]) {
            charSet[(int)s[left]] = false;
            left++;
        }
        charSet[(int)s[right]] = true;
        
        int currentLength = right - left + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    
    return maxLength;
}

int main() {
    // Example 1
    char str1[] = "abcabcbb";
    printf("Length of longest substring without repeating characters: %d\n", lengthOfLongestSubstring(str1));

    // Example 2
    char str2[] = "bbbbb";
    printf("Length of longest substring without repeating characters: %d\n", lengthOfLongestSubstring(str2));

    return 0;
}
