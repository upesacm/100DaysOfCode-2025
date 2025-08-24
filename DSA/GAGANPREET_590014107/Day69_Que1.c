
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

int canFormPalindrome(char* str) {
    int freq[MAX_CHAR] = {0};
    int oddCount = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i]]++;
    }

    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
        }
    }

    return oddCount <= 1;
}

int main() {
    char str1[] = "civic";
    printf("%s\n", canFormPalindrome(str1) ? "Yes" : "No");

    char str2[] = "aabbcc";
    printf("%s\n", canFormPalindrome(str2) ? "Yes" : "No");

    char str3[] = "abc";
    printf("%s\n", canFormPalindrome(str3) ? "Yes" : "No");

    return 0;
}
