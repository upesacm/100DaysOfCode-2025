#include <stdio.h>
#include <string.h>

int canFormPalindrome(char *str) {
    int freq[256] = {0};
    for (int i = 0; str[i]; i++) freq[(unsigned char)str[i]]++;
    int oddCount = 0;
    for (int i = 0; i < 256; i++) if (freq[i] % 2 != 0) oddCount++;
    return oddCount <= 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%99s", str);
    printf("%s\n", canFormPalindrome(str) ? "Yes" : "No");
    return 0;
}
