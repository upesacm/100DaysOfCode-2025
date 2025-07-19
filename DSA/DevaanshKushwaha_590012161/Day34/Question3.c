#include <stdio.h>

int main() {
    unsigned int n;
    printf("Enter an integer: ");
    scanf("%u", &n);
    printf("Initial n = %u\n", n);
    int left = sizeof(n) * 8 - 1;
    int right = 0;
    int is_palindrome = 1;

    while (left > right) {
        int left_bit = (n >> left) & 1;
        int right_bit = (n >> right) & 1;
        printf("Comparing bit %d (left) = %d with bit %d (right) = %d\n", left, left_bit, right, right_bit);
        if (left_bit != right_bit) {
            is_palindrome = 0;
            break;
        }
        left--;
        right++;
    }

    if (is_palindrome)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
