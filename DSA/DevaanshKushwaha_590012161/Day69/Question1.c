#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define CHARSET 256  // ASCII size

bool canFormPalindrome(char *str) {
    int freq[CHARSET] = {0};
    int n = strlen(str);

    // Count character frequencies
    for (int i = 0; i < n; i++) {
        freq[(unsigned char)str[i]]++;
    }

    int oddCount = 0;
    for (int i = 0; i < CHARSET; i++) {
        if (freq[i] % 2 != 0) oddCount++;
    }

    // At most one odd frequency allowed
    if (oddCount > 1) return false;
    return true;
}

int main() {
    char str1[] = "civic";
    printf("Input: %s → Output: %s\n", str1, canFormPalindrome(str1) ? "Yes" : "No");

    char str2[] = "aabbcc";
    printf("Input: %s → Output: %s\n", str2, canFormPalindrome(str2) ? "Yes" : "No");

    char str3[] = "abc";
    printf("Input: %s → Output: %s\n", str3, canFormPalindrome(str3) ? "Yes" : "No");

    return 0;
}
