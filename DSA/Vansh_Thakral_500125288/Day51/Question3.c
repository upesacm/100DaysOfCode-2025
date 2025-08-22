#include <stdio.h>
#include <string.h>
#include <limits.h>

char* minWindow(char* s, char* t) {
    static char result[1000]; 
    int need[256] = {0}, have[256] = {0};
    int required = 0, formed = 0;
    int sLen = strlen(s), tLen = strlen(t);

    for (int i = 0; i < tLen; i++) {
        if (need[t[i]] == 0) required++;
        need[t[i]]++;
    }

    int left = 0, minLen = INT_MAX, start = 0;
    for (int right = 0; right < sLen; right++) {
        char c = s[right];
        have[c]++;
        if (have[c] == need[c]) formed++;

        while (formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }
            char lc = s[left++];
            have[lc]--;
            if (have[lc] < need[lc] && need[lc] > 0) formed--;
        }
    }

    if (minLen == INT_MAX) return "";
    strncpy(result, s + start, minLen);
    result[minLen] = '\0';
    return result;
}

int main() {
    char s1[] = "ADOBECODEBANC", t1[] = "ABC";
    printf("%s\n", minWindow(s1, t1)); 

    char s2[] = "a", t2[] = "a";
    printf("%s\n", minWindow(s2, t2)); 

    return 0;
}

