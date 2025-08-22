#include <stdio.h>
#include <string.h>

#define MAX 256

int longestKUniqueSubstring(char *str, int k) {
    int n = strlen(str);
    int count[MAX] = {0};
    int i = 0, j = 0, max_len = 0, unique = 0;

    while (j < n) {
        if (count[str[j]] == 0)
            unique++;
        count[str[j]]++;

        while (unique > k) {
            count[str[i]]--;
            if (count[str[i]] == 0)
                unique--;
            i++;
        }

        if (unique == k)
            max_len = (j - i + 1 > max_len) ? j - i + 1 : max_len;

        j++;
    }

    return max_len;
}

int main() {
    char str[1000];
    int k;

    printf("Enter the string: ");
    scanf("%s", str);
    printf("Enter value of k: ");
    scanf("%d", &k);

    int result = longestKUniqueSubstring(str, k);
    printf("Longest substring with %d unique characters: %d\n", k, result);
    return 0;
}
