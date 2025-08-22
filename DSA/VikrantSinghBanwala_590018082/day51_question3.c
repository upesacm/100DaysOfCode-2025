#include <stdio.h>
#include <string.h>
#include <limits.h>

#define CHAR_COUNT 256  


char* minWindow(char* s, char* t) {
    int lenS = strlen(s);
    int lenT = strlen(t);

    if (lenS == 0 || lenT == 0 || lenT > lenS) {
        return "";
    }

    int required[CHAR_COUNT] = {0};
    int window[CHAR_COUNT] = {0};

    
    for (int i = 0; i < lenT; i++) {
        required[(int)t[i]]++;
    }

    int start = 0, minStart = 0, minLen = INT_MAX;
    int count = 0;

    for (int end = 0; end < lenS; end++) {
        char ch = s[end];
        window[(int)ch]++;

    
        if (required[(int)ch] != 0 && window[(int)ch] <= required[(int)ch]) {
            count++;
        }


        while (count == lenT) {
            
            if (end - start + 1 < minLen) {
                minLen = end - start + 1;
                minStart = start;
            }

            
            char leftChar = s[start];
            window[(int)leftChar]--;
            if (required[(int)leftChar] != 0 && window[(int)leftChar] < required[(int)leftChar]) {
                count--;
            }
            start++;
        }
    }

    
    if (minLen == INT_MAX) {
        return "";
    }

    
    static char result[CHAR_COUNT];
    strncpy(result, s + minStart, minLen);
    result[minLen] = '\0';
    return result;
}

int main() {
    
    char s1[] = "ADOBECODEBANC";
    char t1[] = "ABC";
    printf("Minimum window: \"%s\"\n", minWindow(s1, t1));  

    char s2[] = "a";
    char t2[] = "a";
    printf("Minimum window: \"%s\"\n", minWindow(s2, t2)); 

    return 0;
}
