#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int unique_substring(const char* str, int k) {
    if (!str || k <= 0) return 0;
    
    int n = strlen(str);
    if (n == 0) return 0;
    
    int freq[256] = {0};
    int uniqueCount = 0;
    int maxLength = 0;
    int start = 0;
    
    for (int end = 0; end < n; end++) {
        if (freq[(unsigned char)str[end]] == 0) {
            uniqueCount++;
        }
        freq[(unsigned char)str[end]]++;
        
        while (uniqueCount > k) {
            freq[(unsigned char)str[start]]--;
            if (freq[(unsigned char)str[start]] == 0) {
                uniqueCount--;
            }
            start++;
        }
        
        if (uniqueCount == k) {
            int currentLength = end - start + 1;
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
        }
    }
    
    return maxLength;
}

char* get_String(const char* prompt) {
    char buffer[1024];
    printf("%s", prompt);
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return NULL;
    }
    
    buffer[strcspn(buffer, "\n")] = '\0';
    
    return strdup(buffer);
}

int get_Int(const char* prompt) {
    int value;
    printf("%s", prompt);
    if (scanf("%d", &value) != 1) {
        return -1;
    }
    while (getchar() != '\n');
    return value;
}

int main() {
    char* str = get_String("Enter the string: ");
    if (!str) {
        printf("Error reading string input\n");
        return 1;
    }
    
    int k = get_Int("Enter the number of unique characters (k): ");
    if (k < 0) {
        printf("Invalid value for k\n");
        free(str);
        return 1;
    }
    
    int result = unique_substring(str, k);
    printf("Length of longest substring with %d unique characters: %d\n", k, result);
    
    free(str);
    return 0;
}
