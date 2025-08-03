#include <stdio.h>

int isBinaryPalindrome(unsigned int n) {
    int left = 31;
    int right = 0;
    while (left > 0 && ((n >> left) & 1) == 0)
        left--;
    while (left > right) {
        if (((n >> left) & 1) != ((n >> right) & 1))
            return 0;
        left--;
        right++;
    }
    return 1;
}

int main() {
    unsigned int n;
    printf("Enter an integer: ");
    scanf("%u", &n);
    if (isBinaryPalindrome(n))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
