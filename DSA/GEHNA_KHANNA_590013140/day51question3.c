#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_CHAR 256

char* minWindow(char* s, char* t) {
    int sLen = strlen(s), tLen = strlen(t);
    int hash_t[MAX_CHAR] = {0}, hash_s[MAX_CHAR] = {0};
    for (int i = 0; i < tLen; i++)
        hash_t[(int)t[i]]++;

    int start = 0, startIndex = -1, minLen = INT_MAX, count = 0;
    for (int end = 0; end < sLen; end++) {
        hash_s[(int)s[end]]++;
        if (hash_t[(int)s[end]] != 0 && hash_s[(int)s[end]] <= hash_t[(int)s[end]])
            count++;

        while (count == tLen) {
            if (end - start + 1 < minLen) {
                minLen = end - start + 1;
                startIndex = start;
            }
            hash_s[(int)s[start]]--;
            if (hash_t[(int)s[start]] != 0 && hash_s[(int)s[start]] < hash_t[(int)s[start]])
                count--;
            start++;
        }
    }

    if (startIndex == -1)
        return "";

    char* result = (char*)malloc(sizeof(char) * (minLen + 1));
    strncpy(result, s + startIndex, minLen);
    result[minLen] = '\0';
    return result;
}

int main() {
    char s[1001], t[1001];
    scanf("%s", s);
    scanf("%s", t);
    char* res = minWindow(s, t);
    printf("%s\n", res);
    free(res);
    return 0;
}
