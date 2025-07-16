#include <stdio.h>

int isPowerOfTwo(unsigned int n) {
    return (n != 0) && ((n & (n - 1)) == 0);
}

int main() {
    unsigned int n;
    printf("Enter a number: ");
    scanf("%u", &n);

    if (isPowerOfTwo(n))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
