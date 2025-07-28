#include <stdio.h>
#include <string.h>

#define MAX 100

int isPalindromeQueue(char queue[], int size) {
    char stack[MAX];
    int top = -1;

    // Push all characters to stack
    for (int i = 0; i < size; i++) {
        stack[++top] = queue[i];
    }

    // Compare queue and stack
    for (int i = 0; i < size; i++) {
        if (queue[i] != stack[top--]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome
}

int main() {
    char q1[] = {'r', 'a', 'c', 'e', 'c', 'a', 'r'};
    char q2[] = {'a', 'b', 'c'};

    printf("%s\n", isPalindromeQueue(q1, 7) ? "Yes" : "No");  // Yes
    printf("%s\n", isPalindromeQueue(q2, 3) ? "Yes" : "No");  // No

    return 0;
}

