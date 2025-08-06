#include <stdio.h>
#include <string.h>
#include <limits.h>

char* minWindowSubstring(char* s, char* t) {
    int sLen = strlen(s), tLen = strlen(t);
    int tFreq[256] = {0}, winFreq[256] = {0};

    for (int i = 0; i < tLen; i++)
        tFreq[t[i]]++;

    int left = 0, right = 0, start = 0;
    int minLen = INT_MAX, formed = 0, required = 0;

    for (int i = 0; i < 256; i++)
        if (tFreq[i]) required++;

    while (right < sLen) {
        char c = s[right];
        winFreq[c]++;
        if (tFreq[c] && winFreq[c] == tFreq[c])
            formed++;

        while (formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            winFreq[s[left]]--;
            if (tFreq[s[left]] && winFreq[s[left]] < tFreq[s[left]])
                formed--;
            left++;
        }
        right++;
    }

    static char result[1000];
    if (minLen == INT_MAX) return "";
    strncpy(result, s + start, minLen);
    result[minLen] = '\0';
    return result;
}

int main() {
    printf("%s\n", minWindowSubstring("ADOBECODEBANC", "ABC")); // Output: BANC
    printf("%s\n", minWindowSubstring("a", "a"));               // Output: a
    return 0;
}

