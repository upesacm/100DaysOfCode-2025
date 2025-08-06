#include <stdio.h>
#include <string.h>

int main() {
    char str[100001];
    int k, freq[256] = {0}, i = 0, j = 0, maxLen = 0, unique = 0;
    printf("enter string\n");
    scanf("%s", str);
    printf("enter value of k\n");
    scanf("%d", &k);
    int n = strlen(str);
    while (j < n) {
        if (freq[str[j]] == 0)
            unique++;
        freq[str[j]]++;
        while (unique > k) {
            freq[str[i]]--;
            if (freq[str[i]] == 0)
                unique--;
            i++;
        }
        if (unique == k && (j - i + 1) > maxLen)
            maxLen = j - i + 1;
        j++;
    }
    printf("%d\n", maxLen);
    return 0;
}
