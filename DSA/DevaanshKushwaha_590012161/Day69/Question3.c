#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int n = strlen(s);
    int visited[256] = {0};
    int left = 0, maxLen = 0;

    for (int right = 0; right < n; right++) {
        visited[(unsigned char)s[right]]++;

        while (visited[(unsigned char)s[right]] > 1) {
            visited[(unsigned char)s[left]]--;
            left++;
        }

        int windowLen = right - left + 1;
        if (windowLen > maxLen) maxLen = windowLen;
    }

    return maxLen;
}

int main() {
    char s1[] = "abcabcbb";
    char s2[] = "bbbbb";

    printf("Input: \"abcabcbb\" → Output: %d\n", lengthOfLongestSubstring(s1));
    printf("Input: \"bbbbb\" → Output: %d\n", lengthOfLongestSubstring(s2));

    return 0;
}
