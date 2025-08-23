#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool canFormPalindrome(char *str) {
    int freq[256] = {0};  // frequency table for ASCII chars
    for (int i = 0; str[i]; i++) {
        freq[(unsigned char)str[i]]++;
    }

    int oddCount = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] % 2 != 0)
            oddCount++;
    }

    return oddCount <= 1;  // palindrome condition
}

int main() {
    char str1[] = "civic";
    char str2[] = "aabbcc";
    char str3[] = "abc";

    printf("%s -> %s\n", str1, canFormPalindrome(str1) ? "Yes" : "No");
    printf("%s -> %s\n", str2, canFormPalindrome(str2) ? "Yes" : "No");
    printf("%s -> %s\n", str3, canFormPalindrome(str3) ? "Yes" : "No");

    return 0;
}
