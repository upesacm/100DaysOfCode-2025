#include <stdio.h>
#include <stdbool.h>

bool isBinaryPalindrome(unsigned int n) {
    int left = sizeof(n) * 8 - 1;  
    int right = 0;

    while (left > right) {
        if (((n >> left) & 1) != ((n >> right) & 1))
            return false;
        left--;
        right++;
    }
    return true;
}

int main() {
    int n1 = 9;   
    int n2 = 10; 

    printf("Is %d binary palindrome? %s\n", n1, isBinaryPalindrome(n1) ? "Yes" : "No");
    printf("Is %d binary palindrome? %s\n", n2, isBinaryPalindrome(n2) ? "Yes" : "No");
    return 0;
}
