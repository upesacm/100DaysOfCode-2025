#include <stdio.h>
#include <stdbool.h>

bool isBinaryPalindrome(unsigned int n) {
    int left = sizeof(n) * 8 - 1;  /
    int right = 0;               

    while (left > right) {

        int bitLeft = (n >> left) & 1;
        int bitRight = (n >> right) & 1;


        if (bitLeft != bitRight)
            return false;

        left--;
        right++;
    }

    return true;
}

int main() {
    unsigned int n;
    printf("Enter a number to check binary palindrome: ");
    scanf("%u", &n);

    if (isBinaryPalindrome(n))
        printf("Output: Yes\n");
    else
        printf("Output: No\n");

    return 0;
}
