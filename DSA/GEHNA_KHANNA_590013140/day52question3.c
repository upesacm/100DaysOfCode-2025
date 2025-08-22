#include <stdio.h>
#include <string.h>

int main() {
    char s[10001], t[1001];
    int need[256] = {0}, window[256] = {0}, required = 0, formed = 0;
    int left = 0, right = 0, minLen = 10001, minStart = 0;
    printf("enter value of s\n");
    scanf("%s", s);
    printf("enter value of t \n");
    scanf("%s", t);
    int lenS = strlen(s), lenT = strlen(t);
    for (int i = 0; i < lenT; i++) {
        if (need[t[i]] == 0)
            required++;
        need[t[i]]++;
    }
    while (right < lenS) {
        char c = s[right];
        window[c]++;
        if (need[c] > 0 && window[c] == need[c])
            formed++;
        while (formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }
            window[s[left]]--;
            if (need[s[left]] > 0 && window[s[left]] < need[s[left]])
                formed--;
            left++;
        }
        right++;
    }
    if (minLen == 10001)
        printf("\"\")\n");
    else {
        for (int i = minStart; i < minStart + minLen; i++)
            printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}
