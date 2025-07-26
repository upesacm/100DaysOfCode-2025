#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Helper to remove leading zeros
void removeLeadingZeros(char* str) {
    int i = 0;
    while (str[i] == '0') i++;

    if (i > 0) {
        int j = 0;
        while (str[i]) str[j++] = str[i++];
        str[j] = '\0';
    }

    if (strlen(str) == 0) {
        strcpy(str, "0");
    }
}

char* removeKdigits(char* num, int k) {
    int len = strlen(num);
    if (k >= len) return strdup("0");

    char *stack = (char *)malloc(len + 1);
    int top = -1;

    for (int i = 0; i < len; i++) {
        char curr = num[i];
        // Pop while k > 0 and current digit is less than top of stack
        while (top >= 0 && k > 0 && stack[top] > curr) {
            top--;
            k--;
        }
        stack[++top] = curr;
    }

    // If k > 0, remove from end
    top -= k;

    stack[top + 1] = '\0';  // Null-terminate

    // Remove leading zeros
    removeLeadingZeros(stack);
    return stack;
}

int main() {
    char input1[] = "1432219";
    int k1 = 3;
    char* result1 = removeKdigits(input1, k1);
    printf("Output 1: %s\n", result1);  // Expected: "1219"
    free(result1);

    char input2[] = "10200";
    int k2 = 1;
    char* result2 = removeKdigits(input2, k2);
    printf("Output 2: %s\n", result2);  // Expected: "200"
    free(result2);

    return 0;
}

