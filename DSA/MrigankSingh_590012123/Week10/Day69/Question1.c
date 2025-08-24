#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char* canFormPalindrome(char* str) {
    int n = strlen(str);
    int freq[26] = {0};
    
    for (int i = 0; i < n; i++) {
        if (isalpha(str[i])) {
            freq[tolower(str[i]) - 'a']++;
        }
    }
    
    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
        }
    }
    
    return (oddCount <= 1) ? "Yes" : "No";
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Can form palindrome: %s\n", canFormPalindrome(str));
    return 0;
}
