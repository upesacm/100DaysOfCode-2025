#include <stdio.h>
#include <string.h>

int longestKUniqueSubstring(char *s, int k) {
    int count[256] = {0};
    int unique = 0, maxLen = 0, left = 0;

    for (int right = 0; s[right]; right++) {
        if (count[s[right]] == 0) unique++;
        count[s[right]]++;

        while (unique > k) {
            count[s[left]]--;
            if (count[s[left]] == 0) unique--;
            left++;
        }

        if (unique == k) {
            int currLen = right - left + 1;
            if (currLen > maxLen)
                maxLen = currLen;
        }
    }
    return maxLen;
}

int main() {
    char str1[] = "aabacbebebe";
    printf("%d\n", longestKUniqueSubstring(str1, 3)); // Output: 7

    char str2[] = "aaaa";
    printf("%d\n", longestKUniqueSubstring(str2, 2)); // Output: 0

    return 0;
}

