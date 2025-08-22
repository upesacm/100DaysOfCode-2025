#include <stdio.h>
#include <string.h>

int longestKUniqueSubstring(char *s, int k) {
    int n = strlen(s);
    int freq[256] = {0};
    int unique = 0, left = 0, maxLen = 0;

    for (int right = 0; right < n; right++) {
        if (freq[s[right]] == 0) unique++;
        freq[s[right]]++;

        while (unique > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) unique--;
            left++;
        }

        if (unique == k) {
            int len = right - left + 1;
            if (len > maxLen) maxLen = len;
        }
    }

    return maxLen;
}

int main() {
    char str1[] = "aabacbebebe";
    int k1 = 3;
    printf("%d\n", longestKUniqueSubstring(str1, k1)); 

    char str2[] = "aaaa";
    int k2 = 2;
    printf("%d\n", longestKUniqueSubstring(str2, k2)); 

    return 0;
}

