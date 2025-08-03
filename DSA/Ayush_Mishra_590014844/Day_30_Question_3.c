#include <stdio.h>

int main() {
    int n, count = 0;
    printf("Enter the number (n): ");
    scanf("%d", &n);
    while (n) {
        n = n & (n - 1);
        count++;
    }
    printf("Number of set bits: %d\n", count);
    return 0;
}
