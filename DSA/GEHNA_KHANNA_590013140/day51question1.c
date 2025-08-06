#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

int countDistinct(int *freq) {
    int count = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0)
            count++;
    }
    return count;
}

int longestSubstringWithKUniqueChars(char *str, int k) {
    int n = strlen(str);
    if (n == 0 || k == 0)
        return 0;

    int freq[MAX_CHAR] = {0};
    int maxLen = 0, start = 0;

    for (int end = 0; end < n; end++) {
        freq[(int)str[end]]++;

        while (countDistinct(freq) > k) {
            freq[(int)str[start]]--;
            start++;
        }

        if (countDistinct(freq) == k) {
            int windowLen = end - start + 1;
            if (windowLen > maxLen)
                maxLen = windowLen;
        }
    }

    return maxLen;
}

int main() {
    char str[1000];
    int k;
    scanf("%s", str);
    scanf("%d", &k);
    printf("%d\n", longestSubstringWithKUniqueChars(str, k));
    return 0;
}
