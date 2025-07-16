#include <stdio.h>

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main() {
    int n1 = 7;
    printf("countSetBits(%d) = %d\n", n1, countSetBits(n1)); // Output: 3

    int n2 = 9;
    printf("countSetBits(%d) = %d\n", n2, countSetBits(n2)); // Output: 2

    return 0;
}
