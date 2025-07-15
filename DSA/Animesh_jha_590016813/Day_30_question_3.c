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
    int n = 9;

    int result = countSetBits(n);
    printf("Number of set bits in %d: %d\n", n, result);

    return 0;
}
