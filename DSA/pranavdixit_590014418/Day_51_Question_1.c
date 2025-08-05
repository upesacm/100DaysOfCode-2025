#include <stdio.h>
#include <string.h>

int longestKUnique(char *s, int k) {
    int freq[256] = {0};
    int unique = 0, left = 0, maxLen = 0;
    for (int right = 0; s[right]; right++) {
        if (freq[s[right]] == 0) unique++;
        freq[s[right]]++;
        while (unique > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) unique--;
            left++;
        }
        if (unique == k && right - left + 1 > maxLen) maxLen = right - left + 1;
    }
    return maxLen;
}

int main() {
    char s[] = "aabacbebebe";
    int k = 3;
    printf("%d", longestKUnique(s, k));
    return 0;
}
