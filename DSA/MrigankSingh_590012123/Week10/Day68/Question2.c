#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* rearrangeString(char* str) {
    int n = strlen(str);
    if (n == 0) return "";
    
    int freq[26] = {0};
    for (int i = 0; i < n; i++) {
        freq[str[i] - 'a']++;
    }
    
    // Find max frequency and total characters
    int max_freq = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
        }
    }
    
    // Check if rearrangement is possible
    if (max_freq > (n + 1) / 2) {
        char* result = malloc(1);
        result[0] = '\0';
        return result;
    }
    
    char* result = malloc(n + 1);
    result[n] = '\0';
    
    // Fill even then odd positions
    int even = 0, odd = 1;
    
    for (int i = 0; i < 26; i++) {
        while (freq[i] > 0 && even < n) {
            result[even] = 'a' + i;
            freq[i]--;
            even += 2;
        }
        
        while (freq[i] > 0 && odd < n) {
            result[odd] = 'a' + i;
            freq[i]--;
            odd += 2;
        }
    }
    
    return result;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    
    char* result = rearrangeString(str);
    if (strlen(result) == 0) {
        printf("Cannot rearrange (no valid arrangement)\n");
    } else {
        printf("Rearranged string: %s\n", result);
    }
    
    free(result);
    return 0;
}
