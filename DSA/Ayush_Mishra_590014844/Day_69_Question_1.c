#include <stdio.h>
#include <string.h>

int canFormPalindrome(char *str) {
    int freq[256] = {0}, i, oddCount = 0;
    for (i = 0; str[i]; i++)
        freq[(int)str[i]]++;
    for (i = 0; i < 256; i++)
        if (freq[i] % 2 != 0)
            oddCount++;
    return oddCount <= 1;
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    scanf("%s", str);
    if (canFormPalindrome(str))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
