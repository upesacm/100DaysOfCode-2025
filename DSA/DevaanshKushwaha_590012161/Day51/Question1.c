#include <stdio.h>
#include <string.h>

int longestSubstringKUnique(char *s, int k) {
    int count[256] = {0}, unique = 0, maxLen = 0, left = 0;
    for (int right = 0; s[right]; right++) {
        if (count[s[right]]++ == 0) unique++;
        while (unique > k) {
            if (--count[s[left]] == 0) unique--;
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
    char str[1001];
    int k;
    scanf("%s", str);
    scanf("%d", &k);
    printf("%d\n", longestSubstringKUnique(str, k));
    return 0;
}
