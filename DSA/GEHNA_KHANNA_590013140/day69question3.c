#include <stdio.h>
#include <string.h>

int length_of_longest_substring(char* s) {
    int index[256];
    for (int i = 0; i < 256; i++) index[i] = -1;
    int max_len = 0, start = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (index[(unsigned char)s[i]] >= start) start = index[(unsigned char)s[i]] + 1;
        index[(unsigned char)s[i]] = i;
        if (i - start + 1 > max_len) max_len = i - start + 1;
    }
    return max_len;
}

int main() {
    char s[1000];
    scanf("%s", s);
    printf("%d\n", length_of_longest_substring(s));
    return 0;
}
