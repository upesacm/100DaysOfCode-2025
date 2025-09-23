#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int minCuts(char* s, int n) {
    // Dynamically allocate 2D palindrome table
    int **isPalindrome = (int **)malloc(n * sizeof(int *));
    if (isPalindrome == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        isPalindrome[i] = (int *)malloc(n * sizeof(int));
        if (isPalindrome[i] == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    // Initialize palindrome table
    for (int i = 0; i < n; i++) {
        isPalindrome[i][i] = 1; // Single characters are palindromes
        for (int j = 0; j < n; j++) {
            if (i != j) isPalindrome[i][j] = 0;
        }
    }

    // Fill palindrome table
    for (int len = 2; len <= n; len++) {
        for (int start = 0; start <= n - len; start++) {
            int end = start + len - 1;
            if (len == 2) {
                isPalindrome[start][end] = (s[start] == s[end]);
            } else {
                isPalindrome[start][end] = (s[start] == s[end]) && isPalindrome[start + 1][end - 1];
            }
        }
    }

    // Dynamically allocate cuts array
    int *cuts = (int *)malloc((n + 1) * sizeof(int));
    if (cuts == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Initialize cuts array
    cuts[0] = 0; // Empty string needs 0 cuts
    for (int i = 1; i <= n; i++) {
        cuts[i] = i; // Worst case: cut after each character
        if (isPalindrome[0][i-1]) {
            cuts[i] = 0; // Whole substring is palindrome
        } else {
            for (int j = 1; j <= i; j++) {
                if (isPalindrome[j-1][i-1]) {
                    cuts[i] = min(cuts[i], cuts[j-1] + 1);
                }
            }
        }
    }

    int result = cuts[n];

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(isPalindrome[i]);
    }
    free(isPalindrome);
    free(cuts);

    return result;
}

int main() {
    char s[1000];
    printf("Enter the string: ");
    scanf("%s", s);

    int n = strlen(s);
    if (n == 0) {
        printf("0\n");
        return 0;
    }

    int result = minCuts(s, n);
    printf("%d\n", result);

    return 0;
}
