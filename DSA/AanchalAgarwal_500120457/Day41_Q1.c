#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void removeAdjacentDuplicates(char *s) {
    int len;
    bool changed;

    do {
        len = strlen(s);
        char stack[len + 1];  // Temporary stack
        int top = -1;         // Stack pointer
        changed = false;

        for (int i = 0; i < len; i++) {
            if (top >= 0 && stack[top] == s[i]) {
                // Skip all adjacent duplicates
                changed = true;
                while (i < len && stack[top] == s[i]) {
                    i++;
                }
                top--; // Pop the duplicate from stack
                i--;   // Adjust index after skipping
            } else {
                stack[++top] = s[i]; // Push current character
            }
        }

        stack[top + 1] = '\0';     // Null-terminate new string
        strcpy(s, stack);          // Copy back to original string

    } while (changed);
}

int main() {
    char str1[] = "abbaca";
    char str2[] = "azxxzy";
    
    removeAdjacentDuplicates(str1);
    printf("Output 1: %s\n", str1);  // Expected: "ca"
    
    removeAdjacentDuplicates(str2);
    printf("Output 2: %s\n", str2);  // Expected: "ay"
    
    return 0;
}

