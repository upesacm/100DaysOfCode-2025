#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

char* min_Substring(char* s, char* t) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    
    if (tLen == 0 || sLen < tLen) {
        char* result = (char*)malloc(1);
        result[0] = '\0';
        return result;
    }
    
    int tFreq[256] = {0};
    int windowFreq[256] = {0};
    int required = 0;
    int formed = 0;
    
    for (int i = 0; i < tLen; i++) {
        if (tFreq[t[i]] == 0) {
            required++;
        }
        tFreq[t[i]]++;
    }
    
    int minLen = INT_MAX;
    int minStart = 0;
    int start = 0;
    int end = 0;
    
    while (end < sLen) {
        char c = s[end];
        windowFreq[c]++;
        
        if (tFreq[c] > 0 && windowFreq[c] == tFreq[c]) {
            formed++;
        }
        
        while (formed == required && start <= end) {
            int currentLen = end - start + 1;
            if (currentLen < minLen) {
                minLen = currentLen;
                minStart = start;
            }
            
            char startChar = s[start];
            windowFreq[startChar]--;
            if (tFreq[startChar] > 0 && windowFreq[startChar] < tFreq[startChar]) {
                formed--;
            }
            start++;
        }
        
        end++;
    }
    
    if (minLen == INT_MAX) {
        char* result = (char*)malloc(1);
        result[0] = '\0';
        return result;
    }
    
    char* result = (char*)malloc(minLen + 1);
    strncpy(result, s + minStart, minLen);
    result[minLen] = '\0';
    
    return result;
}

int main() {
    char s[1000], t[1000];
    
    printf("Enter string s: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    
    printf("Enter string t: ");
    fgets(t, sizeof(t), stdin);
    t[strcspn(t, "\n")] = '\0';
    
    char* result = min_Substring(s, t);
    
    if (strlen(result) {
        printf("Minimum window substring: \"%s\"\n", result);
    } else {
        printf("No valid window found.\n");
    }
    
    free(result);
    return 0;
}
