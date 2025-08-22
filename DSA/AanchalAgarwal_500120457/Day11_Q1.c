#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    char cleaned[1000];
    int index = 0;

    // Step 1: Filter only alphanumeric characters and convert to lowercase
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            cleaned[index++] = tolower(str[i]);
        }
    }
    cleaned[index] = '\0';

    // Step 2: Check palindrome on cleaned string
    int left = 0;
    int right = index - 1;
    while (left < right) {
        if (cleaned[left] != cleaned[right]) {
            return 0;  // false
        }
        left++;
        right--;
    }

    return 1;  // true
}

// Main function to test the palindrome checker
int main() {
    char input1[] = "A man, a plan, a canal: Panama";
    char input2[] = "race a car";
    char input3[] = "Was it a car or a cat I saw?";

    printf("\"%s\" → %s\n", input1, isPalindrome(input1) ? "true" : "false");
    printf("\"%s\" → %s\n", input2, isPalindrome(input2) ? "true" : "false");
    printf("\"%s\" → %s\n", input3, isPalindrome(input3) ? "true" : "false");

    return 0;
}

