#include <stdio.h>

int isolateRightmostSetBit(int n) {
    return n & -n;
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    int result = isolateRightmostSetBit(n);
    printf("Isolated rightmost set bit: %d\n", result);

    return 0;
}
