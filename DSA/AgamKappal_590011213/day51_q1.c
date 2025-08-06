#include <stdio.h>
#include <string.h>

int longestKUniqueChars(char* str, int k) {
    int n = strlen(str);
    if (n == 0 || k == 0) return 0;

    int count[256] = {0};
    int unique = 0, maxLen = 0, start = 0;

    for (int end = 0; end < n; end++) {
        if (count[str[end]] == 0)
            unique++;
        count[str[end]]++;

        while (unique > k) {
            count[str[start]]--;
            if (count[str[start]] == 0)
                unique--;
            start++;
        }

        if (unique == k) {
            int len = end - start + 1;
            if (len > maxLen)
                maxLen = len;
        }
    }

    return maxLen;
}

int main() {
    char str1[] = "aabacbebebe";
    int k1 = 3;
    printf("Output: %d\n", longestKUniqueChars(str1, k1)); // Output: 7

    char str2[] = "aaaa";
    int k2 = 2;
    printf("Output: %d\n", longestKUniqueChars(str2, k2)); // Output: 0

    return 0;
}
