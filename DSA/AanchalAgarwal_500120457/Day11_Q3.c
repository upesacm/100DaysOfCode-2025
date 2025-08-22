#include <stdio.h>
#include <string.h>

// Expand around center and count palindromes
int expandFromCenter(char* s, int left, int right) {
    int count = 0;
    int n = strlen(s);
    while (left >= 0 && right < n && s[left] == s[right]) {
        count++;
        left--;
        right++;
    }
    return count;
}

// Function to count all palindromic substrings
int countPalindromicSubstrings(char* s) {
    int total = 0;
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        total += expandFromCenter(s, i, i);     // Odd-length palindromes
        total += expandFromCenter(s, i, i + 1); // Even-length palindromes
    }

    return total;
}

// Main to test
int main() {
    char input1[] = "abc";
    char input2[] = "aaa";
    char input3[] = "aba";

    printf("Input: \"%s\" → Output: %d\n", input1, countPalindromicSubstrings(input1)); // 3
    printf("Input: \"%s\" → Output: %d\n", input2, countPalindromicSubstrings(input2)); // 6
    printf("Input: \"%s\" → Output: %d\n", input3, countPalindromicSubstrings(input3)); // 4

    return 0;
}

