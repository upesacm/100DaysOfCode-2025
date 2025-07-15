#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number (n): ");
    scanf("%d", &n);
    printf("Enter the bit position (i): ");
    scanf("%d", &i);
    int bit = (n >> i) & 1;
    printf("The %d-th bit is: %d\n", i, bit);
    return 0;
}
