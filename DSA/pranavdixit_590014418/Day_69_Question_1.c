#include <stdio.h>
#include <string.h>

int canFormPalindrome(char *s) {
    int freq[256] = {0}, oddCount = 0;

    for (int i = 0; s[i]; i++)
        freq[(int)s[i]]++;

    for (int i = 0; i < 256; i++)
        if (freq[i] % 2 != 0) oddCount++;

    return oddCount <= 1;
}

int main() {
    char s1[] = "civic";
    printf("%s → %s\n", s1, canFormPalindrome(s1) ? "Yes" : "No"); // Yes

    char s2[] = "aabbcc";
    printf("%s → %s\n", s2, canFormPalindrome(s2) ? "Yes" : "No"); // Yes

    char s3[] = "abc";
    printf("%s → %s\n", s3, canFormPalindrome(s3) ? "Yes" : "No"); // No
    return 0;
}
