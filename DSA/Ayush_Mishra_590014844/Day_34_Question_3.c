#include <stdio.h>

int main() {
    unsigned int n;
    printf("Enter an integer to check if its binary representation is a palindrome: ");
    scanf("%u", &n);

    int left = sizeof(n) * 8 - 1;
    int right = 0;
    int is_palindrome = 1;

    while (left > right) {
        int left_bit = (n >> left) & 1;
        int right_bit = (n >> right) & 1;
        if (left_bit != right_bit) {
            is_palindrome = 0;
            break;
        }
        left--;
        right++;
    }

    if (is_palindrome)
        printf("Yes, the binary representation is a palindrome.\n");
    else
        printf("No, the binary representation is not a palindrome.\n");

    return 0;
}
