#include <stdio.h>

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    int n;
    printf("Enter an integer (n): ");
    scanf("%d", &n);

    int result = countSetBits(n);
    printf("Number of set bits: %d\n", result);

    return 0;
}
