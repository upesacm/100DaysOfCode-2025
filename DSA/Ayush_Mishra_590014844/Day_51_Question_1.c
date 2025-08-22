#include <stdio.h>
#include <string.h>

int longestSubstring(char *str, int k) {
    int freq[256] = {0}, uniqueCount = 0, maxLen = 0;
    int left = 0, right = 0, n = strlen(str);

    while (right < n) {
        if (freq[str[right]] == 0)
            uniqueCount++;
        freq[str[right]]++;
        while (uniqueCount > k) {
            freq[str[left]]--;
            if (freq[str[left]] == 0)
                uniqueCount--;
            left++;
        }
        if (uniqueCount == k && (right - left + 1) > maxLen)
            maxLen = right - left + 1;
        right++;
    }
    return maxLen;
}

int main() {
    char str[1000];
    int k;
    scanf("%s", str);
    scanf("%d", &k);
    printf("%d\n", longestSubstring(str, k));
    return 0;
}
