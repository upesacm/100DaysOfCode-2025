#include <stdio.h>
#include <string.h>
#define CHAR 256

int longestKUniqueChars(char *str, int k) {
    int n = strlen(str);
    if (n == 0 || k == 0) return 0;

    int freq[CHAR] = {0};
    int start = 0, end = 0, max_len = 0, unique = 0;

    while (end < n) {
        if (freq[(int)str[end]] == 0)
            unique++;
        freq[(int)str[end]]++;

        while (unique > k) {
            freq[(int)str[start]]--;
            if (freq[(int)str[start]] == 0)
                unique--;
            start++;
        }

        if (unique == k)
            if (end - start + 1 > max_len)
                max_len = end - start + 1;

        end++;
    }

    return max_len;
}

int main() {
    char str[] = "aabacbebebe";
    int k = 3;
    printf("%d\n", longestKUniqueChars(str, k));
    return 0;
}
