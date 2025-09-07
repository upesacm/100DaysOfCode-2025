#include <stdio.h>
#include <string.h>

// Rearrange Array to Form Palindrome
int canFormPalindrome(char* str) {
    int freq[256] = {0};
    int len = strlen(str);
    int oddCount = 0;

    for (int i = 0; i < len; i++) {
        freq[(int)str[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
        }
    }

    return (oddCount <= 1);
}

int main() {
    // Example 1
    char str1[] = "civic";
    if (canFormPalindrome(str1)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    // Example 2
    char str2[] = "aabbcc";
    if (canFormPalindrome(str2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    // Example 3
    char str3[] = "abc";
    if (canFormPalindrome(str3)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
