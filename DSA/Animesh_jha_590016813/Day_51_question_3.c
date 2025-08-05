#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_CHAR 256

char* minWindow(char* s, char* t) {
    int lenS = strlen(s);
    int lenT = strlen(t);

    if (lenS == 0 || lenT == 0 || lenS < lenT)
        return "";

    int required[MAX_CHAR] = {0};
    int window[MAX_CHAR] = {0};

    for (int i = 0; i < lenT; i++)
        required[t[i]]++;

    int start = 0, minLen = INT_MAX, minStart = 0;
    int count = 0;

    for (int end = 0; end < lenS; end++) {
        char endChar = s[end];
        window[endChar]++;

        if (required[endChar] != 0 && window[endChar] <= required[endChar])
            count++;

        while (count == lenT) {
            if (end - start + 1 < minLen) {
                minLen = end - start + 1;
                minStart = start;
            }

            char startChar = s[start];
            window[startChar]--;
            if (required[startChar] != 0 && window[startChar] < required[startChar])
                count--;
            start++;
        }
    }

    if (minLen == INT_MAX)
        return "";

    static char result[1000];
    strncpy(result, s + minStart, minLen);
    result[minLen] = '\0';
    return result;
}

int main() {
    char s[] = "ADOBECODEBANC";
    char t[] = "ABC";

    char* result = minWindow(s, t);
    printf("%s\n", result);  
    return 0;
}
