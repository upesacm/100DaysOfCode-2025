#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Longest_Substring(char* s) {
    int n = strlen(s);
    if (n == 0) {
        return 0;
    }
    
    int lastSeen[256]; 
    for (int i = 0; i < 256; i++) {
        lastSeen[i] = -1;
    }
    
    int maxLength = 0;
    int start = 0;
    
    for (int end = 0; end < n; end++) {
        if (lastSeen[s[end]] >= start) {
            start = lastSeen[s[end]] + 1;
        }
        
        int currentLength = end - start + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
        
        lastSeen[s[end]] = end;
    }
    
    return maxLength;
}

int main() {
    char s[1000];
    printf("Enter the string: ");
    if (fgets(s, sizeof(s), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
    
    int result = Longest_Substring(s);
    printf("Length of the longest substring without repeating characters: %d\n", result);
    
    return 0;
}
