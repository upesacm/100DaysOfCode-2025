#include <stdio.h>
#include <string.h>
#include <limits.h>

char* minWindow(char* s, char* t) {
    static char result[1001];
    int need[128] = {0}, have[128] = {0};
    int required = 0, formed = 0, left = 0, minLen = INT_MAX, start = 0;
    for (int i = 0; t[i]; i++) if (need[t[i]]++ == 0) required++;
    for (int right = 0; s[right]; right++) {
        char c = s[right];
        if (++have[c] == need[c]) formed++;
        while (formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }
            if (--have[s[left]] < need[s[left]]) formed--;
            left++;
        }
    }
    if (minLen == INT_MAX) return "";
    strncpy(result, s + start, minLen);
    result[minLen] = '\0';
    return result;
}

int main() {
    char s[1001], t[1001];
    scanf("%s", s);
    scanf("%s", t);
    printf("%s\n", minWindow(s, t));
    return 0;
}
