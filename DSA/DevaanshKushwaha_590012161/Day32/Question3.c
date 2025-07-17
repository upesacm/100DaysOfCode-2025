#include <stdio.h>

int main() {
    int n, x, xor = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    while (n--) {
        scanf("%d", &x);
        xor ^= x;
    }
    printf("XOR of all elements: %d\n", xor);
    return 0;
}
