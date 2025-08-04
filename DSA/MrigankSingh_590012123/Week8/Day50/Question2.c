#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Frequencies_Equal(int freq1[], int freq2[], int size) {
    for (int i = 0; i < size; i++) {
        if (freq1[i] != freq2[i]) {
            return 0;
        }
    }
    return 1;
}

int count_Anagram(const char* text, const char* pattern) {
    int textLen = strlen(text);
    int patLen = strlen(pattern);
    
    if (patLen == 0 || textLen == 0 || patLen > textLen) {
        return 0;
    }
    
    int patFreq[256] = {0};
    int winFreq[256] = {0};
    int count = 0;
    
    for (int i = 0; i < patLen; i++) {
        patFreq[(unsigned char)pattern[i]]++;
        winFreq[(unsigned char)text[i]]++;
    }
    
    if (Frequencies_Equal(patFreq, winFreq, 256)) {
        count++;
    }
    
    for (int i = patLen; i < textLen; i++) {
        winFreq[(unsigned char)text[i - patLen]]--;
        winFreq[(unsigned char)text[i]]++;
        
        if (Frequencies_Equal(patFreq, winFreq, 256)) {
            count++;
        }
    }
    
    return count;
}

char* getInput(const char* prompt) {
    char buffer[100];
    char* input = NULL;
    
    printf("%s", prompt);
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return NULL;
    }
    
    buffer[strcspn(buffer, "\n")] = '\0';
    input = strdup(buffer);
    
    return input;
}

int main() {
    char* text = getInput("Enter the text: ");
    char* pattern = getInput("Enter the pattern: ");
    
    if (!text || !pattern) {
        printf("Error reading input\n");
        free(text);
        free(pattern);
        return 1;
    }
    
    int count = count_Anagram(text, pattern);
    printf("Number of anagram occurrences: %d\n", count);
    
    free(text);
    free(pattern);
    return 0;
}
