#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

int longestSubstringKUnique(char *str, int k) {
    int n = strlen(str);
    if (n == 0 || k == 0) return 0;

    int count[MAX_CHAR] = {0};
    int uniqueCount = 0, maxLength = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        if (count[str[right]] == 0)
            uniqueCount++;
        count[str[right]]++;

        while (uniqueCount > k) {
            count[str[left]]--;
            if (count[str[left]] == 0)
                uniqueCount--;
            left++;
        }

        if (uniqueCount == k)
            if (right - left + 1 > maxLength)
                maxLength = right - left + 1;
    }

    return maxLength;
}

int main() {
    char str[] = "aabacbebebe";
    int k = 3;

    int result = longestSubstringKUnique(str, k);
    printf("%d\n", result);  

    return 0;
}
