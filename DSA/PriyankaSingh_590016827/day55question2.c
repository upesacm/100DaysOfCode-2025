#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    printf("Enter string: ");
    scanf("%s", str);
    int n = strlen(str);

    int lastIndex[256];
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;

    int maxLen = 0, start = 0;
    for (int end = 0; end < n; end++) {
        if (lastIndex[(unsigned char)str[end]] >= start)
            start = lastIndex[(unsigned char)str[end]] + 1;
        lastIndex[(unsigned char)str[end]] = end;
        if (end - start + 1 > maxLen) maxLen = end - start + 1;
    }

    printf("Length of longest substring without repeating characters: %d\n", maxLen);
    return 0;
}
