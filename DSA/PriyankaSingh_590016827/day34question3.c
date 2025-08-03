
#include <stdio.h>

int isBinaryPalindrome(unsigned int n) {
    unsigned int rev = 0, temp = n;
    int bits = sizeof(n) * 8;

    for (int i = 0; i < bits; i++) {
        rev <<= 1;
        rev |= (temp & 1);
        temp >>= 1;
    }

    // Remove leading zeros in reversed number
    while ((rev & 1) == 0 && rev != 0)
        rev >>= 1;

    return n == rev;
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
