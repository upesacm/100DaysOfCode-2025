#include <stdio.h>

int isBinaryPalindrome(int n) {
    int rev = 0, temp = n;
    while (temp > 0) {
        rev <<= 1;
        rev |= temp & 1;
        temp >>= 1;
    }
    return rev == n;
}

int main() {
    int n = 9;
    if (isBinaryPalindrome(n))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
