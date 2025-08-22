#include <stdio.h>
#include <string.h>
#include <limits.h>

int minWindow(char *s, char *t, char *result) {
    int ns = strlen(s), nt = strlen(t), freqT[256] = {0}, freqS[256] = {0};
    for (int i = 0; i < nt; i++)
        freqT[t[i]]++;

    int left = 0, count = 0, minLen = INT_MAX, start = -1;
    for (int right = 0; right < ns; right++) {
        freqS[s[right]]++;
        if (freqT[s[right]] && freqS[s[right]] <= freqT[s[right]])
            count++;
        while (count == nt) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }
            freqS[s[left]]--;
            if (freqT[s[left]] && freqS[s[left]] < freqT[s[left]])
                count--;
            left++;
        }
    }
    if (start == -1)
        return 0;
    strncpy(result, s + start, minLen);
    result[minLen] = '\0';
    return minLen;
}

int main() {
    char s[1000], t[1000], res[1000];
    scanf("%s %s", s, t);
    if (minWindow(s, t, res))
        printf("%s\n", res);
    else
        printf("\n");
    return 0;
}
