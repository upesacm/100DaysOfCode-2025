#include <stdio.h>

int countSetBits(int n) {
    int count = 0;

    while (n > 0) {
        n = n & (n - 1); 
        count++;
    }

    return count;
}

int main() {
    int n;

    printf("Enter the number (n): ");
    scanf("%d", &n);

    int result = countSetBits(n);
    printf("Number of set bits in %d: %d\n", n, result);

    return 0;
}
