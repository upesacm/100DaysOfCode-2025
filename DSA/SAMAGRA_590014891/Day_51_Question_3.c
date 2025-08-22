#include <stdio.h>
#include <string.h>
#include <limits.h>
#define CHAR 256

char* minWindowSubstring(char* s, char* t) {
    static char result[1000];
    int lenS = strlen(s), lenT = strlen(t);
    if (lenS < lenT) return "";

    int hash_t[CHAR] = {0}, hash_s[CHAR] = {0};
    for (int i = 0; i < lenT; i++)
        hash_t[(int)t[i]]++;

    int start = 0, start_index = -1, min_len = INT_MAX, count = 0;

    for (int end = 0; end < lenS; end++) {
        hash_s[(int)s[end]]++;

        if (hash_t[(int)s[end]] != 0 &&
            hash_s[(int)s[end]] <= hash_t[(int)s[end]])
            count++;

        if (count == lenT) {
            while (hash_s[(int)s[start]] > hash_t[(int)s[start]] ||
                   hash_t[(int)s[start]] == 0) {
                if (hash_s[(int)s[start]] > hash_t[(int)s[start]])
                    hash_s[(int)s[start]]--;
                start++;
            }

            int window_len = end - start + 1;
            if (min_len > window_len) {
                min_len = window_len;
                start_index = start;
            }
        }
    }

    if (start_index == -1) return "";

    strncpy(result, s + start_index, min_len);
    result[min_len] = '\0';
    return result;
}

int main() {
    char s[] = "ADOBECODEBANC";
    char t[] = "ABC";
    printf("%s\n", minWindowSubstring(s, t));
    return 0;
}
