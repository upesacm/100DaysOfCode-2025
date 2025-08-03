#include <stdio.h>

int isPowerOfTwo(int n) {
    
    if (n <= 0)
        return 0;

    return (n & (n - 1)) == 0;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPowerOfTwo(n))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
