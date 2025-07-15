#include <stdio.h>

int clearBit(int n, int i) {
    int mask = ~(1 << i); // Flip the target bit to 0
    return n & mask;
}

int main() {
    int n, i;
    scanf("%d %d", &n, &i);
    printf("%d\n", clearBit(n, i));
    return 0;
}
