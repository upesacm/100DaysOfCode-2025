#include <stdio.h>
#include <string.h>

char* can_form_palindrome(char* s) {
    int freq[256] = {0};
    for (int i = 0; s[i] != '\0'; i++) freq[(unsigned char)s[i]]++;
    int odd_count = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] % 2 != 0) odd_count++;
        if (odd_count > 1) return "No";
    }
    return "Yes";
}

int main() {
    printf("%s\n", can_form_palindrome("civic"));
    printf("%s\n", can_form_palindrome("aabbcc"));
    printf("%s\n", can_form_palindrome("abc"));
    return 0;
}
