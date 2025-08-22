#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

// Function to find the longest palindromic substring
void longestPalindrome(char* str) {
    int n = strlen(str);
    if (n == 0) {
        printf("Empty string\n");
        return;
    }

    bool dp[MAX][MAX] = {false};
    int start = 0, maxLen = 1;

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++)
        dp[i][i] = true;

    // Check substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (str[i] == str[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    // Check substrings of length >= 3
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            if (str[i] == str[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                if (len > maxLen) {
                    start = i;
                    maxLen = len;
                }
            }
        }
    }

    printf("Longest Palindromic Substring: ");
    for (int i = start; i < start + maxLen; i++) {
        putchar(str[i]);
    }
    printf("\n");
}

// Main to test
int main() {
    char input1[] = "babad";
    char input2[] = "cbbd";
    char input3[] = "racecar";

    longestPalindrome(input1);  // Output: bab or aba
    longestPalindrome(input2);  // Output: bb
    longestPalindrome(input3);  // Output: racecar

    return 0;
}

