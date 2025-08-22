#include <stdio.h>
#include <string.h>
#include <limits.h>

char* minWindow(char* s, char* t) {
    static char ans[1000];
    int need[256] = {0}, have[256] = {0};
    int required = 0, formed = 0;
    for (int i = 0; t[i]; i++) {
        if (need[t[i]] == 0) required++;
        need[t[i]]++;
    }
    int left = 0, minLen = INT_MAX, start = 0;
    for (int right = 0; s[right]; right++) {
        have[s[right]]++;
        if (have[s[right]] == need[s[right]]) formed++;
        while (formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }
            have[s[left]]--;
            if (have[s[left]] < need[s[left]]) formed--;
            left++;
        }
    }
    if (minLen == INT_MAX) return "";
    strncpy(ans, s + start, minLen);
    ans[minLen] = '\0';
    return ans;
}

int main() {
    char s[] = "ADOBECODEBANC";
    char t[] = "ABC";
    printf("%s", minWindow(s, t));
    return 0;
}
