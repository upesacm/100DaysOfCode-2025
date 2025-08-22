#include<stdio.h>
#include<string.h>
int longestSubstringWithKUniqueChars(char *str, int k) {
    int n = strlen(str);
    if (n == 0 || k == 0) return 0;
    int charCount[256] = {0};
    int uniqueCount = 0;
    int left = 0, maxLength = 0;
    for (int right = 0; right < n; right++) {
        if (charCount[str[right]] == 0) {
            uniqueCount++;
        }
        charCount[str[right]]++;
        while (uniqueCount > k) {
            charCount[str[left]]--;
            if (charCount[str[left]] == 0) {
                uniqueCount--;
            }
            left++;
        }
        if (uniqueCount == k) {
            maxLength = (right - left + 1 > maxLength) ? (right - left + 1) : maxLength;
        }
    }
    return maxLength;
}
int main() {
    char str1[] = "aabacbebebe";
    int k1 = 3;
    printf("%d\n", longestSubstringWithKUniqueChars(str1, k1));
    char str2[] = "aaaa";
    int k2 = 2;
    printf("%d\n", longestSubstringWithKUniqueChars(str2, k2));
    return 0;
}
